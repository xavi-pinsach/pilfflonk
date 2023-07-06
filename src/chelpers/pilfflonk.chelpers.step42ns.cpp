#include <alt_bn128.hpp>
#include "pilfflonk_steps.hpp"

void PilFflonkSteps::step42ns_first(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_0 = E.fr.sub(params.cm3_2ns[0 + i*4], E.fr.set(1));
     AltBn128::FrElement tmp_55 = E.fr.mul(params.const_2ns[0 + i * 4], tmp_0);
     AltBn128::FrElement tmp_1 = E.fr.mul(params.cm2_2ns[1 + i*4], params.challenges[2]);
     AltBn128::FrElement tmp_2 = E.fr.add(params.cm2_2ns[0 + i*4], tmp_1);
     AltBn128::FrElement tmp_3 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_4 = E.fr.mul(params.challenges[3], tmp_3);
     AltBn128::FrElement tmp_5 = E.fr.add(tmp_2, tmp_4);
     AltBn128::FrElement tmp_6 = E.fr.mul(params.cm2_2ns[0 + ((i + 8)%64)*4], params.challenges[2]);
     AltBn128::FrElement tmp_7 = E.fr.add(params.cm2_2ns[1 + i*4], tmp_6);
     AltBn128::FrElement tmp_8 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_9 = E.fr.mul(params.challenges[3], tmp_8);
     AltBn128::FrElement tmp_10 = E.fr.add(tmp_7, tmp_9);
     AltBn128::FrElement tmp_56 = E.fr.mul(tmp_5, tmp_10);
     AltBn128::FrElement tmp_11 = E.fr.mul(params.cm3_2ns[0 + ((i + 8)%64)*4], tmp_56);
     AltBn128::FrElement tmp_12 = E.fr.mul(params.cm3_2ns[0 + i*4], params.cm3_2ns[2 + i*4]);
     AltBn128::FrElement tmp_57 = E.fr.sub(tmp_11, tmp_12);
     AltBn128::FrElement tmp_13 = E.fr.sub(params.cm3_2ns[1 + i*4], E.fr.set(1));
     AltBn128::FrElement tmp_58 = E.fr.mul(params.const_2ns[0 + i * 4], tmp_13);
     AltBn128::FrElement tmp_14 = E.fr.mul(params.cm2_2ns[3 + i*4], params.challenges[2]);
     AltBn128::FrElement tmp_15 = E.fr.add(params.cm2_2ns[2 + i*4], tmp_14);
     AltBn128::FrElement tmp_16 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_17 = E.fr.mul(params.challenges[3], tmp_16);
     AltBn128::FrElement tmp_18 = E.fr.add(tmp_15, tmp_17);
     AltBn128::FrElement tmp_19 = E.fr.mul(params.cm2_2ns[2 + ((i + 8)%64)*4], params.challenges[2]);
     AltBn128::FrElement tmp_20 = E.fr.add(params.cm2_2ns[3 + i*4], tmp_19);
     AltBn128::FrElement tmp_21 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_22 = E.fr.mul(params.challenges[3], tmp_21);
     AltBn128::FrElement tmp_23 = E.fr.add(tmp_20, tmp_22);
     AltBn128::FrElement tmp_59 = E.fr.mul(tmp_18, tmp_23);
     AltBn128::FrElement tmp_24 = E.fr.mul(params.cm3_2ns[1 + ((i + 8)%64)*4], tmp_59);
     AltBn128::FrElement tmp_25 = E.fr.mul(params.cm3_2ns[1 + i*4], params.cm3_2ns[3 + i*4]);
     AltBn128::FrElement tmp_60 = E.fr.sub(tmp_24, tmp_25);
     AltBn128::FrElement tmp_61 = params.cm1_2ns[0 + i*2];
     AltBn128::FrElement tmp_62 = tmp_61;
     AltBn128::FrElement tmp_63 = params.const_2ns[1 + i * 4];
     AltBn128::FrElement tmp_64 = tmp_63;
     AltBn128::FrElement tmp_65 = params.const_2ns[1 + ((i + 8)%64) * 4];
     AltBn128::FrElement tmp_66 = tmp_65;
     AltBn128::FrElement tmp_67 = params.cm1_2ns[1 + i*2];
     AltBn128::FrElement tmp_68 = tmp_67;
     AltBn128::FrElement tmp_69 = params.const_2ns[2 + i * 4];
     AltBn128::FrElement tmp_70 = tmp_69;
     AltBn128::FrElement tmp_71 = params.const_2ns[2 + ((i + 8)%64) * 4];
     AltBn128::FrElement tmp_72 = tmp_71;
     AltBn128::FrElement tmp_26 = E.fr.mul(params.challenges[4], tmp_55);
     AltBn128::FrElement tmp_27 = E.fr.add(tmp_26, tmp_57);
     AltBn128::FrElement tmp_28 = E.fr.mul(params.challenges[4], tmp_27);
     AltBn128::FrElement tmp_29 = E.fr.add(tmp_28, tmp_58);
     AltBn128::FrElement tmp_30 = E.fr.mul(params.challenges[4], tmp_29);
     AltBn128::FrElement tmp_31 = E.fr.add(tmp_30, tmp_60);
     AltBn128::FrElement tmp_32 = E.fr.mul(params.challenges[4], tmp_31);
     AltBn128::FrElement tmp_33 = E.fr.add(tmp_62, params.challenges[3]);
     AltBn128::FrElement tmp_34 = E.fr.mul(tmp_66, params.challenges[2]);
     AltBn128::FrElement tmp_35 = E.fr.add(tmp_64, tmp_34);
     AltBn128::FrElement tmp_36 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_37 = E.fr.mul(params.challenges[3], tmp_36);
     AltBn128::FrElement tmp_38 = E.fr.add(tmp_35, tmp_37);
     AltBn128::FrElement tmp_39 = E.fr.mul(tmp_33, tmp_38);
     AltBn128::FrElement tmp_40 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_41 = E.fr.mul(tmp_39, tmp_40);
     AltBn128::FrElement tmp_42 = E.fr.sub(tmp_41, params.cm3_2ns[2 + i*4]);
     AltBn128::FrElement tmp_43 = E.fr.add(tmp_32, tmp_42);
     AltBn128::FrElement tmp_44 = E.fr.mul(params.challenges[4], tmp_43);
     AltBn128::FrElement tmp_45 = E.fr.add(tmp_68, params.challenges[3]);
     AltBn128::FrElement tmp_46 = E.fr.mul(tmp_72, params.challenges[2]);
     AltBn128::FrElement tmp_47 = E.fr.add(tmp_70, tmp_46);
     AltBn128::FrElement tmp_48 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_49 = E.fr.mul(params.challenges[3], tmp_48);
     AltBn128::FrElement tmp_50 = E.fr.add(tmp_47, tmp_49);
     AltBn128::FrElement tmp_51 = E.fr.mul(tmp_45, tmp_50);
     AltBn128::FrElement tmp_52 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_53 = E.fr.mul(tmp_51, tmp_52);
     AltBn128::FrElement tmp_54 = E.fr.sub(tmp_53, params.cm3_2ns[3 + i*4]);
     AltBn128::FrElement tmp_73 = E.fr.add(tmp_44, tmp_54);
     params.q_2ns[i] = tmp_73;
}

void PilFflonkSteps::step42ns_i(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_0 = E.fr.sub(params.cm3_2ns[0 + i*4], E.fr.set(1));
     AltBn128::FrElement tmp_55 = E.fr.mul(params.const_2ns[0 + i * 4], tmp_0);
     AltBn128::FrElement tmp_1 = E.fr.mul(params.cm2_2ns[1 + i*4], params.challenges[2]);
     AltBn128::FrElement tmp_2 = E.fr.add(params.cm2_2ns[0 + i*4], tmp_1);
     AltBn128::FrElement tmp_3 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_4 = E.fr.mul(params.challenges[3], tmp_3);
     AltBn128::FrElement tmp_5 = E.fr.add(tmp_2, tmp_4);
     AltBn128::FrElement tmp_6 = E.fr.mul(params.cm2_2ns[0 + ((i + 8)%64)*4], params.challenges[2]);
     AltBn128::FrElement tmp_7 = E.fr.add(params.cm2_2ns[1 + i*4], tmp_6);
     AltBn128::FrElement tmp_8 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_9 = E.fr.mul(params.challenges[3], tmp_8);
     AltBn128::FrElement tmp_10 = E.fr.add(tmp_7, tmp_9);
     AltBn128::FrElement tmp_56 = E.fr.mul(tmp_5, tmp_10);
     AltBn128::FrElement tmp_11 = E.fr.mul(params.cm3_2ns[0 + ((i + 8)%64)*4], tmp_56);
     AltBn128::FrElement tmp_12 = E.fr.mul(params.cm3_2ns[0 + i*4], params.cm3_2ns[2 + i*4]);
     AltBn128::FrElement tmp_57 = E.fr.sub(tmp_11, tmp_12);
     AltBn128::FrElement tmp_13 = E.fr.sub(params.cm3_2ns[1 + i*4], E.fr.set(1));
     AltBn128::FrElement tmp_58 = E.fr.mul(params.const_2ns[0 + i * 4], tmp_13);
     AltBn128::FrElement tmp_14 = E.fr.mul(params.cm2_2ns[3 + i*4], params.challenges[2]);
     AltBn128::FrElement tmp_15 = E.fr.add(params.cm2_2ns[2 + i*4], tmp_14);
     AltBn128::FrElement tmp_16 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_17 = E.fr.mul(params.challenges[3], tmp_16);
     AltBn128::FrElement tmp_18 = E.fr.add(tmp_15, tmp_17);
     AltBn128::FrElement tmp_19 = E.fr.mul(params.cm2_2ns[2 + ((i + 8)%64)*4], params.challenges[2]);
     AltBn128::FrElement tmp_20 = E.fr.add(params.cm2_2ns[3 + i*4], tmp_19);
     AltBn128::FrElement tmp_21 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_22 = E.fr.mul(params.challenges[3], tmp_21);
     AltBn128::FrElement tmp_23 = E.fr.add(tmp_20, tmp_22);
     AltBn128::FrElement tmp_59 = E.fr.mul(tmp_18, tmp_23);
     AltBn128::FrElement tmp_24 = E.fr.mul(params.cm3_2ns[1 + ((i + 8)%64)*4], tmp_59);
     AltBn128::FrElement tmp_25 = E.fr.mul(params.cm3_2ns[1 + i*4], params.cm3_2ns[3 + i*4]);
     AltBn128::FrElement tmp_60 = E.fr.sub(tmp_24, tmp_25);
     AltBn128::FrElement tmp_61 = params.cm1_2ns[0 + i*2];
     AltBn128::FrElement tmp_62 = tmp_61;
     AltBn128::FrElement tmp_63 = params.const_2ns[1 + i * 4];
     AltBn128::FrElement tmp_64 = tmp_63;
     AltBn128::FrElement tmp_65 = params.const_2ns[1 + ((i + 8)%64) * 4];
     AltBn128::FrElement tmp_66 = tmp_65;
     AltBn128::FrElement tmp_67 = params.cm1_2ns[1 + i*2];
     AltBn128::FrElement tmp_68 = tmp_67;
     AltBn128::FrElement tmp_69 = params.const_2ns[2 + i * 4];
     AltBn128::FrElement tmp_70 = tmp_69;
     AltBn128::FrElement tmp_71 = params.const_2ns[2 + ((i + 8)%64) * 4];
     AltBn128::FrElement tmp_72 = tmp_71;
     AltBn128::FrElement tmp_26 = E.fr.mul(params.challenges[4], tmp_55);
     AltBn128::FrElement tmp_27 = E.fr.add(tmp_26, tmp_57);
     AltBn128::FrElement tmp_28 = E.fr.mul(params.challenges[4], tmp_27);
     AltBn128::FrElement tmp_29 = E.fr.add(tmp_28, tmp_58);
     AltBn128::FrElement tmp_30 = E.fr.mul(params.challenges[4], tmp_29);
     AltBn128::FrElement tmp_31 = E.fr.add(tmp_30, tmp_60);
     AltBn128::FrElement tmp_32 = E.fr.mul(params.challenges[4], tmp_31);
     AltBn128::FrElement tmp_33 = E.fr.add(tmp_62, params.challenges[3]);
     AltBn128::FrElement tmp_34 = E.fr.mul(tmp_66, params.challenges[2]);
     AltBn128::FrElement tmp_35 = E.fr.add(tmp_64, tmp_34);
     AltBn128::FrElement tmp_36 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_37 = E.fr.mul(params.challenges[3], tmp_36);
     AltBn128::FrElement tmp_38 = E.fr.add(tmp_35, tmp_37);
     AltBn128::FrElement tmp_39 = E.fr.mul(tmp_33, tmp_38);
     AltBn128::FrElement tmp_40 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_41 = E.fr.mul(tmp_39, tmp_40);
     AltBn128::FrElement tmp_42 = E.fr.sub(tmp_41, params.cm3_2ns[2 + i*4]);
     AltBn128::FrElement tmp_43 = E.fr.add(tmp_32, tmp_42);
     AltBn128::FrElement tmp_44 = E.fr.mul(params.challenges[4], tmp_43);
     AltBn128::FrElement tmp_45 = E.fr.add(tmp_68, params.challenges[3]);
     AltBn128::FrElement tmp_46 = E.fr.mul(tmp_72, params.challenges[2]);
     AltBn128::FrElement tmp_47 = E.fr.add(tmp_70, tmp_46);
     AltBn128::FrElement tmp_48 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_49 = E.fr.mul(params.challenges[3], tmp_48);
     AltBn128::FrElement tmp_50 = E.fr.add(tmp_47, tmp_49);
     AltBn128::FrElement tmp_51 = E.fr.mul(tmp_45, tmp_50);
     AltBn128::FrElement tmp_52 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_53 = E.fr.mul(tmp_51, tmp_52);
     AltBn128::FrElement tmp_54 = E.fr.sub(tmp_53, params.cm3_2ns[3 + i*4]);
     AltBn128::FrElement tmp_73 = E.fr.add(tmp_44, tmp_54);
     params.q_2ns[i] = tmp_73;
}

void PilFflonkSteps::step42ns_last(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_0 = E.fr.sub(params.cm3_2ns[0 + i*4], E.fr.set(1));
     AltBn128::FrElement tmp_55 = E.fr.mul(params.const_2ns[0 + i * 4], tmp_0);
     AltBn128::FrElement tmp_1 = E.fr.mul(params.cm2_2ns[1 + i*4], params.challenges[2]);
     AltBn128::FrElement tmp_2 = E.fr.add(params.cm2_2ns[0 + i*4], tmp_1);
     AltBn128::FrElement tmp_3 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_4 = E.fr.mul(params.challenges[3], tmp_3);
     AltBn128::FrElement tmp_5 = E.fr.add(tmp_2, tmp_4);
     AltBn128::FrElement tmp_6 = E.fr.mul(params.cm2_2ns[0 + ((i + 8)%64)*4], params.challenges[2]);
     AltBn128::FrElement tmp_7 = E.fr.add(params.cm2_2ns[1 + i*4], tmp_6);
     AltBn128::FrElement tmp_8 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_9 = E.fr.mul(params.challenges[3], tmp_8);
     AltBn128::FrElement tmp_10 = E.fr.add(tmp_7, tmp_9);
     AltBn128::FrElement tmp_56 = E.fr.mul(tmp_5, tmp_10);
     AltBn128::FrElement tmp_11 = E.fr.mul(params.cm3_2ns[0 + ((i + 8)%64)*4], tmp_56);
     AltBn128::FrElement tmp_12 = E.fr.mul(params.cm3_2ns[0 + i*4], params.cm3_2ns[2 + i*4]);
     AltBn128::FrElement tmp_57 = E.fr.sub(tmp_11, tmp_12);
     AltBn128::FrElement tmp_13 = E.fr.sub(params.cm3_2ns[1 + i*4], E.fr.set(1));
     AltBn128::FrElement tmp_58 = E.fr.mul(params.const_2ns[0 + i * 4], tmp_13);
     AltBn128::FrElement tmp_14 = E.fr.mul(params.cm2_2ns[3 + i*4], params.challenges[2]);
     AltBn128::FrElement tmp_15 = E.fr.add(params.cm2_2ns[2 + i*4], tmp_14);
     AltBn128::FrElement tmp_16 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_17 = E.fr.mul(params.challenges[3], tmp_16);
     AltBn128::FrElement tmp_18 = E.fr.add(tmp_15, tmp_17);
     AltBn128::FrElement tmp_19 = E.fr.mul(params.cm2_2ns[2 + ((i + 8)%64)*4], params.challenges[2]);
     AltBn128::FrElement tmp_20 = E.fr.add(params.cm2_2ns[3 + i*4], tmp_19);
     AltBn128::FrElement tmp_21 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_22 = E.fr.mul(params.challenges[3], tmp_21);
     AltBn128::FrElement tmp_23 = E.fr.add(tmp_20, tmp_22);
     AltBn128::FrElement tmp_59 = E.fr.mul(tmp_18, tmp_23);
     AltBn128::FrElement tmp_24 = E.fr.mul(params.cm3_2ns[1 + ((i + 8)%64)*4], tmp_59);
     AltBn128::FrElement tmp_25 = E.fr.mul(params.cm3_2ns[1 + i*4], params.cm3_2ns[3 + i*4]);
     AltBn128::FrElement tmp_60 = E.fr.sub(tmp_24, tmp_25);
     AltBn128::FrElement tmp_61 = params.cm1_2ns[0 + i*2];
     AltBn128::FrElement tmp_62 = tmp_61;
     AltBn128::FrElement tmp_63 = params.const_2ns[1 + i * 4];
     AltBn128::FrElement tmp_64 = tmp_63;
     AltBn128::FrElement tmp_65 = params.const_2ns[1 + ((i + 8)%64) * 4];
     AltBn128::FrElement tmp_66 = tmp_65;
     AltBn128::FrElement tmp_67 = params.cm1_2ns[1 + i*2];
     AltBn128::FrElement tmp_68 = tmp_67;
     AltBn128::FrElement tmp_69 = params.const_2ns[2 + i * 4];
     AltBn128::FrElement tmp_70 = tmp_69;
     AltBn128::FrElement tmp_71 = params.const_2ns[2 + ((i + 8)%64) * 4];
     AltBn128::FrElement tmp_72 = tmp_71;
     AltBn128::FrElement tmp_26 = E.fr.mul(params.challenges[4], tmp_55);
     AltBn128::FrElement tmp_27 = E.fr.add(tmp_26, tmp_57);
     AltBn128::FrElement tmp_28 = E.fr.mul(params.challenges[4], tmp_27);
     AltBn128::FrElement tmp_29 = E.fr.add(tmp_28, tmp_58);
     AltBn128::FrElement tmp_30 = E.fr.mul(params.challenges[4], tmp_29);
     AltBn128::FrElement tmp_31 = E.fr.add(tmp_30, tmp_60);
     AltBn128::FrElement tmp_32 = E.fr.mul(params.challenges[4], tmp_31);
     AltBn128::FrElement tmp_33 = E.fr.add(tmp_62, params.challenges[3]);
     AltBn128::FrElement tmp_34 = E.fr.mul(tmp_66, params.challenges[2]);
     AltBn128::FrElement tmp_35 = E.fr.add(tmp_64, tmp_34);
     AltBn128::FrElement tmp_36 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_37 = E.fr.mul(params.challenges[3], tmp_36);
     AltBn128::FrElement tmp_38 = E.fr.add(tmp_35, tmp_37);
     AltBn128::FrElement tmp_39 = E.fr.mul(tmp_33, tmp_38);
     AltBn128::FrElement tmp_40 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_41 = E.fr.mul(tmp_39, tmp_40);
     AltBn128::FrElement tmp_42 = E.fr.sub(tmp_41, params.cm3_2ns[2 + i*4]);
     AltBn128::FrElement tmp_43 = E.fr.add(tmp_32, tmp_42);
     AltBn128::FrElement tmp_44 = E.fr.mul(params.challenges[4], tmp_43);
     AltBn128::FrElement tmp_45 = E.fr.add(tmp_68, params.challenges[3]);
     AltBn128::FrElement tmp_46 = E.fr.mul(tmp_72, params.challenges[2]);
     AltBn128::FrElement tmp_47 = E.fr.add(tmp_70, tmp_46);
     AltBn128::FrElement tmp_48 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_49 = E.fr.mul(params.challenges[3], tmp_48);
     AltBn128::FrElement tmp_50 = E.fr.add(tmp_47, tmp_49);
     AltBn128::FrElement tmp_51 = E.fr.mul(tmp_45, tmp_50);
     AltBn128::FrElement tmp_52 = E.fr.add(E.fr.set(1), params.challenges[2]);
     AltBn128::FrElement tmp_53 = E.fr.mul(tmp_51, tmp_52);
     AltBn128::FrElement tmp_54 = E.fr.sub(tmp_53, params.cm3_2ns[3 + i*4]);
     AltBn128::FrElement tmp_73 = E.fr.add(tmp_44, tmp_54);
     params.q_2ns[i] = tmp_73;
}
