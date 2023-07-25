#ifndef ZKEVM_VERIFIER_MAIN_FINAL_HPP
#define ZKEVM_VERIFIER_MAIN_FINAL_HPP

#include <string>
#include <nlohmann/json.hpp>
#include "calcwit.pilfflonk.hpp"
#include "circom.pilfflonk.hpp"
#include "fr.hpp"
#include <alt_bn128.hpp>
#include "execFile.hpp"

namespace CircomPilFflonk
{
    Circom_Circuit *loadCircuit(std::string const &datFileName);
    void freeCircuit(Circom_Circuit *circuit);
    void loadJson(Circom_CalcWit *ctx, std::string filename);
    void loadJsonImpl(Circom_CalcWit *ctx, json &j);
    void writeBinWitness(Circom_CalcWit *ctx, std::string wtnsFileName);
    void getBinWitness(Circom_CalcWit *ctx, RawFr::Element *&pWitness, uint64_t &witnessSize);
    bool check_valid_number(std::string &s, uint base);
    void getCommittedPols(AltBn128::Engine &E, FrElement *buffDst, const std::string circomVerifier, const std::string execFile, nlohmann::json &zkin, uint64_t nCols);
}
#endif