#ifndef STEPS_HPP
#define STEPS_HPP

#include <alt_bn128.hpp>

struct StepsParams
{
    AltBn128::FrElement *pols;
    ConstantPolsFflonk *pConstPols;
    ConstantPolsFflonk *pConstPols2ns;
    AltBn128::FrElement* challenges;
    AltBn128::FrElement* x_n;
    AltBn128::FrElement* x_2ns;
    AltBn128::FrElement* publicInputs;
    AltBn128::FrElement* q_2ns;
};

class Steps
{
public:
    virtual void step2prev_first(StepsParams &params, uint64_t i) = 0;
    virtual void step2prev_i(StepsParams &params, uint64_t i) = 0;
    virtual void step2prev_last(StepsParams &params, uint64_t i) = 0;
    virtual void step2prev_parser_first_avx(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step2prev_parser_first_avx512(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};

    virtual void step3prev_first(StepsParams &params, uint64_t i) = 0;
    virtual void step3prev_i(StepsParams &params, uint64_t i) = 0;
    virtual void step3prev_last(StepsParams &params, uint64_t i) = 0;
    virtual void step3prev_parser_first_avx(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step3prev_parser_first_avx512(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};

    virtual void step3_first(StepsParams &params, uint64_t i) = 0;
    virtual void step3_i(StepsParams &params, uint64_t i) = 0;
    virtual void step3_last(StepsParams &params, uint64_t i) = 0;
    virtual void step3_parser_first(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step3_parser_first_avx(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step3_parser_first_avx_jump(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step3_parser_first_avx512(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};

    virtual void step42ns_first(StepsParams &params, uint64_t i) = 0;
    virtual void step42ns_i(StepsParams &params, uint64_t i) = 0;
    virtual void step42ns_last(StepsParams &params, uint64_t i) = 0;
    virtual void step42ns_parser_first(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step42ns_parser_first_avx(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step42ns_parser_first_avx_jump(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
    virtual void step42ns_parser_first_avx512(StepsParams &params, uint64_t nrows, uint64_t nrowsBatch){};
};

#endif // STEPS
