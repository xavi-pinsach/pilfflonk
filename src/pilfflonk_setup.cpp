#include "pilfflonk_setup.hpp"
#include "timer.hpp"
#include <stdio.h>
#include "zkey.hpp"
#include <math.h>
//#include "const_pols_serializer.hpp"


// Improve
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <system_error>
#include <string>
#include <memory.h>
#include <stdexcept>

#include "thread_utils.hpp"
#include <omp.h>
// /Improve

#include "fft.hpp"



namespace PilFflonk
{
    using FrElement = typename AltBn128::Engine::FrElement;
    using G1Point = typename AltBn128::Engine::G1Point;
    using G1PointAffine = typename AltBn128::Engine::G1PointAffine;

    PilFflonkSetup::~PilFflonkSetup()
    {
        delete zkey;
        delete fflonkInfo;
        delete[] constPolsEvals;
        delete[] constPolsEvalsExt;
        delete fft;

        delete PTau;
    }

    void PilFflonkSetup::generateZkey(std::string shKeyFilename, std::string fflonkInfoFileName,
                                      std::string pTauFilename, std::string cnstPolsFilename,
                                      std::string cnstPolsExtFilename, std::string zkeyFilename)
    {
        // STEP 1. Read shKey JSON file
        zkey = new PilFflonkZkey::PilFflonkZkey();

        zklog.info("> Reading shKey JSON file");
        json shKeyJson;
        file2json(shKeyFilename, shKeyJson);
        parseShKey(shKeyJson);

        // STEP 2. Read fflonkInfo JSON file
        zklog.info("> Reading fflonkInfo JSON file");
        fflonkInfo = new FflonkInfo(this->E, fflonkInfoFileName);

        zklog.info("> Opening PTau file");
        auto fdPtau = BinFileUtils::openExisting(pTauFilename, "ptau", 1);

        uint64_t maxFiDegree = 0;
        for (uint32_t i = 0; i < zkey->f.size(); i++)
        {
            maxFiDegree = max(maxFiDegree, zkey->f[i]->degree);
        }
        maxFiDegree++;

        if (fdPtau->getSectionSize(2) < maxFiDegree * sizeof(G1PointAffine))
        {
            throw new runtime_error("Powers of Tau is not big enough for this circuit size. Section 2 too small.");
        }

        uint64_t sG2 = zkey->n8q * 4;
        if (fdPtau->getSectionSize(3) < sG2)
        {
            throw new runtime_error("Powers of Tau is not well prepared. Section 3 too small.");
        }

        PTau = new G1PointAffine[maxFiDegree];

        int nThreads = omp_get_max_threads() / 2;
        if((uint64_t)nThreads > maxFiDegree) nThreads = 1;
        ThreadUtils::parset(PTau, 0, maxFiDegree * sizeof(G1PointAffine), nThreads);
        ThreadUtils::parcpy(PTau, fdPtau->getSectionData(2), maxFiDegree * sizeof(G1PointAffine), nThreads);

        zklog.info("> Loading const polynomials file");
        const auto [constPolsEvals, constPolsEvalsSize] = loadFromFileFr(cnstPolsFilename);
        this->constPolsEvals = constPolsEvals;
        this->constPolsEvalsSize = constPolsEvalsSize / sizeof(FrElement);

        zklog.info("> Loading const polynomials ext file");
        const auto [constPolsEvalsExt, constPolsEvalsExtSize] = loadFromFileFr(cnstPolsExtFilename);
        this->constPolsEvalsExt = constPolsEvalsExt;
        this->constPolsEvalsExtSize = constPolsEvalsExtSize / sizeof(FrElement);

        zkey->X2 = new uint8_t[sG2];
        
        memcpy(zkey->X2, (G1PointAffine*)(fdPtau->getSectionData(3) + sG2), sG2);

        auto nBits = zkey->power;
        uint64_t domainSize = 1 << nBits;

        fft = new FFT<AltBn128::Engine::Fr>(domainSize * 4);

        uint32_t extendBits = ceil(fft->log2(fflonkInfo->qDeg + 1));

        auto nBitsCoefs = fflonkInfo->nBitsZK + zkey->power;
        auto nBitsExt = zkey->power + extendBits + fflonkInfo->nBitsZK;

        uint64_t domainSizeCoefs = 1 << nBitsCoefs;
        uint64_t domainSizeExt = 1 << nBitsExt;

        ntt = new NTT_AltBn128(E, domainSize);
        nttExtended = new NTT_AltBn128(E, domainSizeExt);

        constPolsCoefs = new FrElement[fflonkInfo->nConstants * domainSize];


        if (fflonkInfo->nConstants > 0)
        {
            ntt->INTT(constPolsCoefs, constPolsEvals, domainSize, fflonkInfo->nConstants);

            ThreadUtils::parset(constPolsEvalsExt, 0, domainSizeExt * fflonkInfo->nConstants * sizeof(AltBn128::FrElement), nThreads);
            ThreadUtils::parcpy(constPolsEvalsExt, constPolsCoefs, domainSize * fflonkInfo->nConstants * sizeof(AltBn128::FrElement), nThreads);

            nttExtended->NTT(constPolsEvalsExt, constPolsEvalsExt, domainSizeExt, fflonkInfo->nConstants);

            int stage = 0;
            std::map <std::string, CommitmentAndPolynomial*> polynomialCommitments;
            for (auto it = zkey->f.begin(); it != zkey->f.end(); ++it)
            {
                PilFflonkZkey::ShPlonkPol *pol = it->second;

                u_int32_t *stages = new u_int32_t[pol->nStages];
                for (u_int32_t i = 0; i < pol->nStages; ++i)
                {
                    stages[i] = pol->stages[i].stage;
                }

                int stagePos = find(stages, pol->nStages, 0);

                if (stagePos != -1)
                {
                    PilFflonkZkey::ShPlonkStage *stagePol = &pol->stages[stagePos];

                    u_int64_t *lengths = new u_int64_t[pol->nPols]{};
                    u_int64_t *polsIds = new u_int64_t[pol->nPols]{};

                    for (u_int32_t j = 0; j < stagePol->nPols; ++j)
                    {
                        std::string name = stagePol->pols[j].name;
                        int index = find(pol->pols, pol->nPols, name);
                        if (index == -1)
                        {
                            throw std::runtime_error("Polynomial " + std::string(name) + " missing");
                        }

                        polsIds[j] = findPolId(zkey, stage, name);
                        lengths[index] = findDegree(zkey, it->first, name);
                    }

                    std::string index = "f" + std::to_string(pol->index);

                    auto cPol = new CPolynomial<AltBn128::Engine>(E, fflonkInfo->nConstants);

                    for (uint64_t i = 0; i < fflonkInfo->nConstants; i++) {
                        std::string name = (*zkey->polsNamesStage[0])[i];
                        auto polynomial = getPolFromBuffer(constPolsCoefs, fflonkInfo->nConstants, domainSize, i);
                        cPol->addPolynomial(polsIds[i], polynomial);

                    }

                    auto polynomial = cPol->getPolynomial();
                    G1PointAffine commitAffine;
                    G1Point commit = multiExponentiation(polynomial);
                    E.g1.copy(commitAffine, commit);

                    polynomialCommitments[index] = new CommitmentAndPolynomial{ commitAffine, polynomial };

                    delete[] lengths;
                    delete[] polsIds;
                }

                delete[] stages;
            }

            for (auto it = polynomialCommitments.begin(); it != polynomialCommitments.end(); ++it)
            {
                auto index = it->first;
                auto commit = it->second->commitment;
                auto pol = it->second->polynomial;

                auto pos = index.find("_");
                if (pos != std::string::npos)
                {
                    index = index.substr(0, pos);
                }

                auto shPlonkCommitment = new PilFflonkZkey::ShPlonkCommitment{
                    index,
                    commit,
                    pol->getDegree() + 1,
                    pol->coef
                };
                zkey->fCommitments[index] = shPlonkCommitment;
            }
        }

        // Precalculate x_n and x_2ns
        x_n = new FrElement[domainSize];
        x_2ns = new FrElement[domainSizeExt];
            
        for (uint64_t i = 0; i < domainSize; i++) {
            auto w = fft->root(zkey->power, i);
            x_n[i] = w;
        }

        for (uint64_t i = 0; i < domainSizeExt; i++) {
            x_2ns[i] = fft->root(nBitsExt, i);
        }

        zklog.info("Fflonk setup finished");
        zklog.info("Writing zkey file");

        PilFflonkZkey::writePilFflonkZkey(zkey,
                                        constPolsEvals, this->constPolsEvalsSize,
                                        constPolsEvalsExt, fflonkInfo->nConstants * domainSizeExt,
                                        constPolsCoefs, fflonkInfo->nConstants * domainSize,
                                        x_n, domainSize,
                                        x_2ns, domainSizeExt,
                                        zkeyFilename, PTau, maxFiDegree);

        zklog.info("Zkey file written");
    }

    void PilFflonkSetup::parseShKey(json shKeyJson) {
        zkey->power = shKeyJson["power"];
        zkey->powerW = shKeyJson["powerW"];
        zkey->maxQDegree = shKeyJson["maxQDegree"];
        zkey->nPublics = shKeyJson["nPublics"];

        // These values are not in the file but we must initialize them
        zkey->n8q = shKeyJson["n8q"];
        mpz_init(zkey->qPrime);
        std::string primeQStr = shKeyJson["primeQ"];
        mpz_set_str(zkey->qPrime, primeQStr.c_str(), 10);


        zkey->n8r = shKeyJson["n8r"];
        mpz_init(zkey->rPrime);
            std::string primeRStr = shKeyJson["primeR"];
        mpz_set_str(zkey->rPrime, primeRStr.c_str(), 10);

        parseFShKey(shKeyJson);

        parsePolsNamesStageShKey(shKeyJson);

        parseOmegasShKey(shKeyJson);
    }

    void PilFflonkSetup::parseFShKey(json shKeyJson) {
        auto f = shKeyJson["f"];

        for (uint32_t i = 0; i < f.size(); i++)
        {
            PilFflonkZkey::ShPlonkPol *shPlonkPol = new PilFflonkZkey::ShPlonkPol();

            auto index = f[i]["index"];
            shPlonkPol->index = index;
            shPlonkPol->degree = f[i]["degree"];

            shPlonkPol->nOpeningPoints = f[i]["openingPoints"].size();
            shPlonkPol->openingPoints = new uint32_t[shPlonkPol->nOpeningPoints];
            for (uint32_t j = 0; j < shPlonkPol->nOpeningPoints; j++)
            {
                shPlonkPol->openingPoints[j] = f[i]["openingPoints"][j];
            }

            shPlonkPol->nPols = f[i]["pols"].size();
            shPlonkPol->pols = new std::string[shPlonkPol->nPols];
            for (uint32_t j = 0; j < shPlonkPol->nPols; j++)
            {
                shPlonkPol->pols[j] = f[i]["pols"][j];
            }
            shPlonkPol->nStages = f[i]["stages"].size();
            shPlonkPol->stages = new PilFflonkZkey::ShPlonkStage[shPlonkPol->nStages];
            for (uint32_t j = 0; j < shPlonkPol->nStages; j++)
            {
                shPlonkPol->stages[j].stage = f[i]["stages"][j]["stage"];
                shPlonkPol->stages[j].nPols = f[i]["stages"][j]["pols"].size();
                shPlonkPol->stages[j].pols = new PilFflonkZkey::ShPlonkStagePol[shPlonkPol->stages[j].nPols];
                for (uint32_t k = 0; k < shPlonkPol->stages[j].nPols; k++)
                {
                    shPlonkPol->stages[j].pols[k].name = f[i]["stages"][j]["pols"][k]["name"];
                    shPlonkPol->stages[j].pols[k].degree = f[i]["stages"][j]["pols"][k]["degree"];
                }
            }

            zkey->f[index] = shPlonkPol;
        }
    }

    void PilFflonkSetup::parsePolsNamesStageShKey(json shKeyJson) {
        auto pns = shKeyJson["polsNamesStage"];

        for (auto& el : pns.items())
        {
            std::map<u_int32_t, std::string> *polsNamesStage = new std::map<u_int32_t, std::string>();

            auto value = el.value();

            u_int32_t lenPolsStage = value.size();

            for (u_int32_t j = 0; j < lenPolsStage; ++j)
            {
                (*polsNamesStage)[j] = value[j];
            }


            zkey->polsNamesStage[stoi(el.key())] = polsNamesStage;
        }
    }

    void PilFflonkSetup::parseOmegasShKey(json shKeyJson) {
        auto omegas = shKeyJson.items();

        for (auto &el : omegas)
        {
            auto key = el.key();
            if (key.find("w") == 0)
            {
                FrElement omega;
                E.fr.fromString(omega, el.value());
                zkey->omegas[key] = omega;
            }
        }
    }

    std::tuple<FrElement*, uint64_t> PilFflonkSetup::loadFromFileFr(std::string filename) {
        struct stat sb;

        int fd = open(filename.c_str(), O_RDONLY);
        if (fd == -1)
            throw std::system_error(errno, std::generic_category(), "open");

        if (fstat(fd, &sb) == -1) /* To obtain file size */
            throw std::system_error(errno, std::generic_category(), "fstat");

        void *addrmm = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
        FrElement* values = (FrElement*)(malloc(sb.st_size));

        int nThreads = omp_get_max_threads() / 2;
        ThreadUtils::parcpy(values, addrmm, sb.st_size, nThreads);

        munmap(addrmm, sb.st_size);
        close(fd);

        return {values, sb.st_size};
    }

    FrElement* PilFflonkSetup::polynomialFromMontgomery(Polynomial<AltBn128::Engine> *polynomial)
    {
        const u_int64_t length = polynomial->getLength();

        FrElement *result = new FrElement[length];
        int nThreads = omp_get_max_threads() / 2;
        ThreadUtils::parset(result, 0, length * sizeof(FrElement), nThreads);

#pragma omp parallel for
        for (u_int32_t index = 0; index < length; ++index)
        {
            E.fr.fromMontgomery(result[index], polynomial->coef[index]);
        }

        return result;
    }

    G1Point PilFflonkSetup::multiExponentiation(Polynomial<AltBn128::Engine> *polynomial)
    {
        G1Point value;
        FrElement *pol = polynomialFromMontgomery(polynomial);

        E.g1.multiMulByScalar(value, PTau, (uint8_t *)pol, sizeof(pol[0]), polynomial->getDegree() + 1);

        return value;
    }

    Polynomial<AltBn128::Engine>* PilFflonkSetup::getPolFromBuffer(FrElement* buff, uint32_t nPols, uint64_t N, int32_t id) {
        FrElement* polBuffer = new FrElement[N];

        for (uint32_t j = 0; j < N; j++) {
            polBuffer[j] = buff[id + j * nPols];
        }

        //TODO use new Polynomial from coefficients without copying two times the buffer!!!!
        return Polynomial<AltBn128::Engine>::fromCoefficients(E, polBuffer, N);
    }

    u_int32_t PilFflonkSetup::findPolId(PilFflonkZkey::PilFflonkZkey* zkey, u_int32_t stage, std::string polName) {
        for (const auto& [index, name] : *zkey->polsNamesStage[stage]) {
            if(name == polName) return index;
        }
        throw std::runtime_error("Polynomial name not found");
    }

    u_int32_t PilFflonkSetup::findDegree(PilFflonkZkey::PilFflonkZkey* zkey, u_int32_t fIndex, std::string name)
    {
        for (u_int32_t i = 0; i < zkey->f[fIndex]->stages[0].nPols; i++)
        {
            if (zkey->f[fIndex]->stages[0].pols[i].name == name)
            {
                return zkey->f[fIndex]->stages[0].pols[i].degree;
            }
        }
        throw std::runtime_error("Polynomial name not found");
    }

    int PilFflonkSetup::find(std::string *arr, u_int32_t n, std::string x)
    {
        for (u_int32_t i = 0; i < n; ++i)
        {
            if (arr[i] == x)
            {
                return int(i);
            }
        }

        return -1;
    }

    int PilFflonkSetup::find(u_int32_t *arr, u_int32_t n, u_int32_t x)
    {
        for (u_int32_t i = 0; i < n; ++i)
        {
            if (arr[i] == x)
            {
                return int(i);
            }
        }

        return -1;
    }
}