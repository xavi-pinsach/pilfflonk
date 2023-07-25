#include <alt_bn128.hpp>
#include "pilfflonk_steps.hpp"

void PilFflonkSteps::step3prev_first(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_74 = params.cm1_n[12 + i*15];
     AltBn128::FrElement tmp_75 = params.cm1_n[13 + ((i + 1)%256)*15];
     params.cm3_n[4 + i*15] = E.fr.mul(params.cm1_n[12 + i*15], params.cm1_n[13 + ((i + 1)%256)*15]);
     AltBn128::FrElement tmp_76 = params.const_n[7 + i * 9];
     AltBn128::FrElement tmp_77 = params.const_n[8 + i * 9];
     AltBn128::FrElement tmp_78 = params.cm1_n[14 + i*15];
     AltBn128::FrElement tmp_79 = params.const_n[6 + i * 9];
     AltBn128::FrElement tmp_12 = E.fr.mul(params.challenges[0], tmp_76);
     AltBn128::FrElement tmp_13 = E.fr.add(tmp_12, tmp_77);
     AltBn128::FrElement tmp_14 = E.fr.mul(params.challenges[0], tmp_13);
     AltBn128::FrElement tmp_15 = E.fr.add(tmp_14, tmp_78);
     AltBn128::FrElement tmp_16 = E.fr.sub(tmp_15, params.challenges[1]);
     AltBn128::FrElement tmp_17 = E.fr.mul(tmp_16, tmp_79);
     params.cm3_n[5 + i*15] = E.fr.add(tmp_17, params.challenges[1]);
     AltBn128::FrElement tmp_80 = params.cm1_n[11 + i*15];
     AltBn128::FrElement tmp_18 = E.fr.mul(tmp_74, params.challenges[0]);
     AltBn128::FrElement tmp_19 = E.fr.add(tmp_18, tmp_75);
     AltBn128::FrElement tmp_20 = E.fr.mul(tmp_19, params.challenges[0]);
     AltBn128::FrElement tmp_21 = E.fr.add(tmp_20, params.cm3_n[4 + i*15]);
     AltBn128::FrElement tmp_22 = E.fr.sub(tmp_21, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_23 = E.fr.mul(tmp_22, tmp_80);
     params.cm3_n[6 + i*15] = E.fr.add(tmp_23, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_81 = params.const_n[7 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_82 = params.const_n[8 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_83 = params.cm1_n[14 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_84 = params.const_n[6 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_24 = E.fr.mul(params.challenges[0], tmp_81);
     AltBn128::FrElement tmp_25 = E.fr.add(tmp_24, tmp_82);
     AltBn128::FrElement tmp_26 = E.fr.mul(params.challenges[0], tmp_25);
     AltBn128::FrElement tmp_27 = E.fr.add(tmp_26, tmp_83);
     AltBn128::FrElement tmp_28 = E.fr.sub(tmp_27, params.challenges[1]);
     AltBn128::FrElement tmp_29 = E.fr.mul(tmp_28, tmp_84);
     params.cm3_n[5 + ((i + 1)%256)*15] = E.fr.add(tmp_29, params.challenges[1]);
     AltBn128::FrElement tmp_30 = E.fr.add(params.cm3_n[6 + i*15], params.challenges[3]);
     AltBn128::FrElement tmp_31 = E.fr.mul(params.cm3_n[5 + ((i + 1)%256)*15], params.challenges[2]);
     AltBn128::FrElement tmp_32 = E.fr.add(params.cm3_n[5 + i*15], tmp_31);
     AltBn128::FrElement tmp_33 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_34 = E.fr.mul(params.challenges[3], tmp_33);
     AltBn128::FrElement tmp_35 = E.fr.add(tmp_32, tmp_34);
     AltBn128::FrElement tmp_36 = E.fr.mul(tmp_30, tmp_35);
     AltBn128::FrElement tmp_37 = E.fr.add(params.constValues[0], params.challenges[2]);
     params.cm3_n[7 + i*15] = E.fr.mul(tmp_36, tmp_37);
     AltBn128::FrElement tmp_38 = E.fr.mul(params.cm2_n[1 + i*2], params.challenges[2]);
     AltBn128::FrElement tmp_39 = E.fr.add(params.cm2_n[0 + i*2], tmp_38);
     AltBn128::FrElement tmp_40 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_41 = E.fr.mul(params.challenges[3], tmp_40);
     AltBn128::FrElement tmp_42 = E.fr.add(tmp_39, tmp_41);
     AltBn128::FrElement tmp_43 = E.fr.mul(params.cm2_n[0 + ((i + 1)%256)*2], params.challenges[2]);
     AltBn128::FrElement tmp_44 = E.fr.add(params.cm2_n[1 + i*2], tmp_43);
     AltBn128::FrElement tmp_45 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_46 = E.fr.mul(params.challenges[3], tmp_45);
     AltBn128::FrElement tmp_47 = E.fr.add(tmp_44, tmp_46);
     params.cm3_n[8 + i*15] = E.fr.mul(tmp_42, tmp_47);
     AltBn128::FrElement tmp_85 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_86 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_87 = params.cm1_n[9 + i*15];
     AltBn128::FrElement tmp_48 = E.fr.mul(tmp_85, params.challenges[0]);
     AltBn128::FrElement tmp_49 = E.fr.add(tmp_48, tmp_86);
     AltBn128::FrElement tmp_50 = E.fr.sub(tmp_49, params.challenges[1]);
     AltBn128::FrElement tmp_51 = E.fr.mul(tmp_50, tmp_87);
     AltBn128::FrElement tmp_88 = E.fr.add(tmp_51, params.challenges[1]);
     params.cm3_n[9 + i*15] = E.fr.add(tmp_88, params.challenges[2]);
     AltBn128::FrElement tmp_89 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_90 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_91 = params.cm1_n[10 + i*15];
     AltBn128::FrElement tmp_52 = E.fr.mul(params.challenges[0], tmp_89);
     AltBn128::FrElement tmp_53 = E.fr.add(tmp_52, tmp_90);
     AltBn128::FrElement tmp_54 = E.fr.sub(tmp_53, params.challenges[1]);
     AltBn128::FrElement tmp_55 = E.fr.mul(tmp_54, tmp_91);
     AltBn128::FrElement tmp_92 = E.fr.add(tmp_55, params.challenges[1]);
     params.cm3_n[10 + i*15] = E.fr.add(tmp_92, params.challenges[2]);
     AltBn128::FrElement tmp_93 = params.cm1_n[2 + i*15];
     AltBn128::FrElement tmp_56 = E.fr.mul(params.challenges[2], params.x_n[i]);
     AltBn128::FrElement tmp_57 = E.fr.add(tmp_93, tmp_56);
     AltBn128::FrElement tmp_94 = E.fr.add(tmp_57, params.challenges[3]);
     AltBn128::FrElement tmp_95 = params.cm1_n[3 + i*15];
     AltBn128::FrElement tmp_58 = E.fr.mul(params.challenges[2], params.constValues[1]);
     AltBn128::FrElement tmp_59 = E.fr.mul(tmp_58, params.x_n[i]);
     AltBn128::FrElement tmp_60 = E.fr.add(tmp_95, tmp_59);
     AltBn128::FrElement tmp_61 = E.fr.add(tmp_60, params.challenges[3]);
     params.cm3_n[11 + i*15] = E.fr.mul(tmp_94, tmp_61);
     AltBn128::FrElement tmp_96 = params.cm1_n[4 + i*15];
     AltBn128::FrElement tmp_62 = E.fr.mul(params.challenges[2], params.constValues[2]);
     AltBn128::FrElement tmp_63 = E.fr.mul(tmp_62, params.x_n[i]);
     AltBn128::FrElement tmp_64 = E.fr.add(tmp_96, tmp_63);
     AltBn128::FrElement tmp_65 = E.fr.add(tmp_64, params.challenges[3]);
     params.cm3_n[13 + i*15] = E.fr.mul(params.cm3_n[11 + i*15], tmp_65);
     AltBn128::FrElement tmp_97 = params.const_n[3 + i * 9];
     AltBn128::FrElement tmp_66 = E.fr.mul(params.challenges[2], tmp_97);
     AltBn128::FrElement tmp_67 = E.fr.add(tmp_93, tmp_66);
     AltBn128::FrElement tmp_98 = E.fr.add(tmp_67, params.challenges[3]);
     AltBn128::FrElement tmp_99 = params.const_n[4 + i * 9];
     AltBn128::FrElement tmp_68 = E.fr.mul(params.challenges[2], tmp_99);
     AltBn128::FrElement tmp_69 = E.fr.add(tmp_95, tmp_68);
     AltBn128::FrElement tmp_70 = E.fr.add(tmp_69, params.challenges[3]);
     params.cm3_n[12 + i*15] = E.fr.mul(tmp_98, tmp_70);
     AltBn128::FrElement tmp_100 = params.const_n[5 + i * 9];
     AltBn128::FrElement tmp_71 = E.fr.mul(params.challenges[2], tmp_100);
     AltBn128::FrElement tmp_72 = E.fr.add(tmp_96, tmp_71);
     AltBn128::FrElement tmp_73 = E.fr.add(tmp_72, params.challenges[3]);
     params.cm3_n[14 + i*15] = E.fr.mul(params.cm3_n[12 + i*15], tmp_73);
}

void PilFflonkSteps::step3prev_i(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_74 = params.cm1_n[12 + i*15];
     AltBn128::FrElement tmp_75 = params.cm1_n[13 + ((i + 1)%256)*15];
     params.cm3_n[4 + i*15] = E.fr.mul(params.cm1_n[12 + i*15], params.cm1_n[13 + ((i + 1)%256)*15]);
     AltBn128::FrElement tmp_76 = params.const_n[7 + i * 9];
     AltBn128::FrElement tmp_77 = params.const_n[8 + i * 9];
     AltBn128::FrElement tmp_78 = params.cm1_n[14 + i*15];
     AltBn128::FrElement tmp_79 = params.const_n[6 + i * 9];
     AltBn128::FrElement tmp_12 = E.fr.mul(params.challenges[0], tmp_76);
     AltBn128::FrElement tmp_13 = E.fr.add(tmp_12, tmp_77);
     AltBn128::FrElement tmp_14 = E.fr.mul(params.challenges[0], tmp_13);
     AltBn128::FrElement tmp_15 = E.fr.add(tmp_14, tmp_78);
     AltBn128::FrElement tmp_16 = E.fr.sub(tmp_15, params.challenges[1]);
     AltBn128::FrElement tmp_17 = E.fr.mul(tmp_16, tmp_79);
     params.cm3_n[5 + i*15] = E.fr.add(tmp_17, params.challenges[1]);
     AltBn128::FrElement tmp_80 = params.cm1_n[11 + i*15];
     AltBn128::FrElement tmp_18 = E.fr.mul(tmp_74, params.challenges[0]);
     AltBn128::FrElement tmp_19 = E.fr.add(tmp_18, tmp_75);
     AltBn128::FrElement tmp_20 = E.fr.mul(tmp_19, params.challenges[0]);
     AltBn128::FrElement tmp_21 = E.fr.add(tmp_20, params.cm3_n[4 + i*15]);
     AltBn128::FrElement tmp_22 = E.fr.sub(tmp_21, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_23 = E.fr.mul(tmp_22, tmp_80);
     params.cm3_n[6 + i*15] = E.fr.add(tmp_23, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_81 = params.const_n[7 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_82 = params.const_n[8 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_83 = params.cm1_n[14 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_84 = params.const_n[6 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_24 = E.fr.mul(params.challenges[0], tmp_81);
     AltBn128::FrElement tmp_25 = E.fr.add(tmp_24, tmp_82);
     AltBn128::FrElement tmp_26 = E.fr.mul(params.challenges[0], tmp_25);
     AltBn128::FrElement tmp_27 = E.fr.add(tmp_26, tmp_83);
     AltBn128::FrElement tmp_28 = E.fr.sub(tmp_27, params.challenges[1]);
     AltBn128::FrElement tmp_29 = E.fr.mul(tmp_28, tmp_84);
     params.cm3_n[5 + ((i + 1)%256)*15] = E.fr.add(tmp_29, params.challenges[1]);
     AltBn128::FrElement tmp_30 = E.fr.add(params.cm3_n[6 + i*15], params.challenges[3]);
     AltBn128::FrElement tmp_31 = E.fr.mul(params.cm3_n[5 + ((i + 1)%256)*15], params.challenges[2]);
     AltBn128::FrElement tmp_32 = E.fr.add(params.cm3_n[5 + i*15], tmp_31);
     AltBn128::FrElement tmp_33 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_34 = E.fr.mul(params.challenges[3], tmp_33);
     AltBn128::FrElement tmp_35 = E.fr.add(tmp_32, tmp_34);
     AltBn128::FrElement tmp_36 = E.fr.mul(tmp_30, tmp_35);
     AltBn128::FrElement tmp_37 = E.fr.add(params.constValues[0], params.challenges[2]);
     params.cm3_n[7 + i*15] = E.fr.mul(tmp_36, tmp_37);
     AltBn128::FrElement tmp_38 = E.fr.mul(params.cm2_n[1 + i*2], params.challenges[2]);
     AltBn128::FrElement tmp_39 = E.fr.add(params.cm2_n[0 + i*2], tmp_38);
     AltBn128::FrElement tmp_40 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_41 = E.fr.mul(params.challenges[3], tmp_40);
     AltBn128::FrElement tmp_42 = E.fr.add(tmp_39, tmp_41);
     AltBn128::FrElement tmp_43 = E.fr.mul(params.cm2_n[0 + ((i + 1)%256)*2], params.challenges[2]);
     AltBn128::FrElement tmp_44 = E.fr.add(params.cm2_n[1 + i*2], tmp_43);
     AltBn128::FrElement tmp_45 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_46 = E.fr.mul(params.challenges[3], tmp_45);
     AltBn128::FrElement tmp_47 = E.fr.add(tmp_44, tmp_46);
     params.cm3_n[8 + i*15] = E.fr.mul(tmp_42, tmp_47);
     AltBn128::FrElement tmp_85 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_86 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_87 = params.cm1_n[9 + i*15];
     AltBn128::FrElement tmp_48 = E.fr.mul(tmp_85, params.challenges[0]);
     AltBn128::FrElement tmp_49 = E.fr.add(tmp_48, tmp_86);
     AltBn128::FrElement tmp_50 = E.fr.sub(tmp_49, params.challenges[1]);
     AltBn128::FrElement tmp_51 = E.fr.mul(tmp_50, tmp_87);
     AltBn128::FrElement tmp_88 = E.fr.add(tmp_51, params.challenges[1]);
     params.cm3_n[9 + i*15] = E.fr.add(tmp_88, params.challenges[2]);
     AltBn128::FrElement tmp_89 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_90 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_91 = params.cm1_n[10 + i*15];
     AltBn128::FrElement tmp_52 = E.fr.mul(params.challenges[0], tmp_89);
     AltBn128::FrElement tmp_53 = E.fr.add(tmp_52, tmp_90);
     AltBn128::FrElement tmp_54 = E.fr.sub(tmp_53, params.challenges[1]);
     AltBn128::FrElement tmp_55 = E.fr.mul(tmp_54, tmp_91);
     AltBn128::FrElement tmp_92 = E.fr.add(tmp_55, params.challenges[1]);
     params.cm3_n[10 + i*15] = E.fr.add(tmp_92, params.challenges[2]);
     AltBn128::FrElement tmp_93 = params.cm1_n[2 + i*15];
     AltBn128::FrElement tmp_56 = E.fr.mul(params.challenges[2], params.x_n[i]);
     AltBn128::FrElement tmp_57 = E.fr.add(tmp_93, tmp_56);
     AltBn128::FrElement tmp_94 = E.fr.add(tmp_57, params.challenges[3]);
     AltBn128::FrElement tmp_95 = params.cm1_n[3 + i*15];
     AltBn128::FrElement tmp_58 = E.fr.mul(params.challenges[2], params.constValues[1]);
     AltBn128::FrElement tmp_59 = E.fr.mul(tmp_58, params.x_n[i]);
     AltBn128::FrElement tmp_60 = E.fr.add(tmp_95, tmp_59);
     AltBn128::FrElement tmp_61 = E.fr.add(tmp_60, params.challenges[3]);
     params.cm3_n[11 + i*15] = E.fr.mul(tmp_94, tmp_61);
     AltBn128::FrElement tmp_96 = params.cm1_n[4 + i*15];
     AltBn128::FrElement tmp_62 = E.fr.mul(params.challenges[2], params.constValues[2]);
     AltBn128::FrElement tmp_63 = E.fr.mul(tmp_62, params.x_n[i]);
     AltBn128::FrElement tmp_64 = E.fr.add(tmp_96, tmp_63);
     AltBn128::FrElement tmp_65 = E.fr.add(tmp_64, params.challenges[3]);
     params.cm3_n[13 + i*15] = E.fr.mul(params.cm3_n[11 + i*15], tmp_65);
     AltBn128::FrElement tmp_97 = params.const_n[3 + i * 9];
     AltBn128::FrElement tmp_66 = E.fr.mul(params.challenges[2], tmp_97);
     AltBn128::FrElement tmp_67 = E.fr.add(tmp_93, tmp_66);
     AltBn128::FrElement tmp_98 = E.fr.add(tmp_67, params.challenges[3]);
     AltBn128::FrElement tmp_99 = params.const_n[4 + i * 9];
     AltBn128::FrElement tmp_68 = E.fr.mul(params.challenges[2], tmp_99);
     AltBn128::FrElement tmp_69 = E.fr.add(tmp_95, tmp_68);
     AltBn128::FrElement tmp_70 = E.fr.add(tmp_69, params.challenges[3]);
     params.cm3_n[12 + i*15] = E.fr.mul(tmp_98, tmp_70);
     AltBn128::FrElement tmp_100 = params.const_n[5 + i * 9];
     AltBn128::FrElement tmp_71 = E.fr.mul(params.challenges[2], tmp_100);
     AltBn128::FrElement tmp_72 = E.fr.add(tmp_96, tmp_71);
     AltBn128::FrElement tmp_73 = E.fr.add(tmp_72, params.challenges[3]);
     params.cm3_n[14 + i*15] = E.fr.mul(params.cm3_n[12 + i*15], tmp_73);
}

void PilFflonkSteps::step3prev_last(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_74 = params.cm1_n[12 + i*15];
     AltBn128::FrElement tmp_75 = params.cm1_n[13 + ((i + 1)%256)*15];
     params.cm3_n[4 + i*15] = E.fr.mul(params.cm1_n[12 + i*15], params.cm1_n[13 + ((i + 1)%256)*15]);
     AltBn128::FrElement tmp_76 = params.const_n[7 + i * 9];
     AltBn128::FrElement tmp_77 = params.const_n[8 + i * 9];
     AltBn128::FrElement tmp_78 = params.cm1_n[14 + i*15];
     AltBn128::FrElement tmp_79 = params.const_n[6 + i * 9];
     AltBn128::FrElement tmp_12 = E.fr.mul(params.challenges[0], tmp_76);
     AltBn128::FrElement tmp_13 = E.fr.add(tmp_12, tmp_77);
     AltBn128::FrElement tmp_14 = E.fr.mul(params.challenges[0], tmp_13);
     AltBn128::FrElement tmp_15 = E.fr.add(tmp_14, tmp_78);
     AltBn128::FrElement tmp_16 = E.fr.sub(tmp_15, params.challenges[1]);
     AltBn128::FrElement tmp_17 = E.fr.mul(tmp_16, tmp_79);
     params.cm3_n[5 + i*15] = E.fr.add(tmp_17, params.challenges[1]);
     AltBn128::FrElement tmp_80 = params.cm1_n[11 + i*15];
     AltBn128::FrElement tmp_18 = E.fr.mul(tmp_74, params.challenges[0]);
     AltBn128::FrElement tmp_19 = E.fr.add(tmp_18, tmp_75);
     AltBn128::FrElement tmp_20 = E.fr.mul(tmp_19, params.challenges[0]);
     AltBn128::FrElement tmp_21 = E.fr.add(tmp_20, params.cm3_n[4 + i*15]);
     AltBn128::FrElement tmp_22 = E.fr.sub(tmp_21, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_23 = E.fr.mul(tmp_22, tmp_80);
     params.cm3_n[6 + i*15] = E.fr.add(tmp_23, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_81 = params.const_n[7 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_82 = params.const_n[8 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_83 = params.cm1_n[14 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_84 = params.const_n[6 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_24 = E.fr.mul(params.challenges[0], tmp_81);
     AltBn128::FrElement tmp_25 = E.fr.add(tmp_24, tmp_82);
     AltBn128::FrElement tmp_26 = E.fr.mul(params.challenges[0], tmp_25);
     AltBn128::FrElement tmp_27 = E.fr.add(tmp_26, tmp_83);
     AltBn128::FrElement tmp_28 = E.fr.sub(tmp_27, params.challenges[1]);
     AltBn128::FrElement tmp_29 = E.fr.mul(tmp_28, tmp_84);
     params.cm3_n[5 + ((i + 1)%256)*15] = E.fr.add(tmp_29, params.challenges[1]);
     AltBn128::FrElement tmp_30 = E.fr.add(params.cm3_n[6 + i*15], params.challenges[3]);
     AltBn128::FrElement tmp_31 = E.fr.mul(params.cm3_n[5 + ((i + 1)%256)*15], params.challenges[2]);
     AltBn128::FrElement tmp_32 = E.fr.add(params.cm3_n[5 + i*15], tmp_31);
     AltBn128::FrElement tmp_33 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_34 = E.fr.mul(params.challenges[3], tmp_33);
     AltBn128::FrElement tmp_35 = E.fr.add(tmp_32, tmp_34);
     AltBn128::FrElement tmp_36 = E.fr.mul(tmp_30, tmp_35);
     AltBn128::FrElement tmp_37 = E.fr.add(params.constValues[0], params.challenges[2]);
     params.cm3_n[7 + i*15] = E.fr.mul(tmp_36, tmp_37);
     AltBn128::FrElement tmp_38 = E.fr.mul(params.cm2_n[1 + i*2], params.challenges[2]);
     AltBn128::FrElement tmp_39 = E.fr.add(params.cm2_n[0 + i*2], tmp_38);
     AltBn128::FrElement tmp_40 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_41 = E.fr.mul(params.challenges[3], tmp_40);
     AltBn128::FrElement tmp_42 = E.fr.add(tmp_39, tmp_41);
     AltBn128::FrElement tmp_43 = E.fr.mul(params.cm2_n[0 + ((i + 1)%256)*2], params.challenges[2]);
     AltBn128::FrElement tmp_44 = E.fr.add(params.cm2_n[1 + i*2], tmp_43);
     AltBn128::FrElement tmp_45 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_46 = E.fr.mul(params.challenges[3], tmp_45);
     AltBn128::FrElement tmp_47 = E.fr.add(tmp_44, tmp_46);
     params.cm3_n[8 + i*15] = E.fr.mul(tmp_42, tmp_47);
     AltBn128::FrElement tmp_85 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_86 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_87 = params.cm1_n[9 + i*15];
     AltBn128::FrElement tmp_48 = E.fr.mul(tmp_85, params.challenges[0]);
     AltBn128::FrElement tmp_49 = E.fr.add(tmp_48, tmp_86);
     AltBn128::FrElement tmp_50 = E.fr.sub(tmp_49, params.challenges[1]);
     AltBn128::FrElement tmp_51 = E.fr.mul(tmp_50, tmp_87);
     AltBn128::FrElement tmp_88 = E.fr.add(tmp_51, params.challenges[1]);
     params.cm3_n[9 + i*15] = E.fr.add(tmp_88, params.challenges[2]);
     AltBn128::FrElement tmp_89 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_90 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_91 = params.cm1_n[10 + i*15];
     AltBn128::FrElement tmp_52 = E.fr.mul(params.challenges[0], tmp_89);
     AltBn128::FrElement tmp_53 = E.fr.add(tmp_52, tmp_90);
     AltBn128::FrElement tmp_54 = E.fr.sub(tmp_53, params.challenges[1]);
     AltBn128::FrElement tmp_55 = E.fr.mul(tmp_54, tmp_91);
     AltBn128::FrElement tmp_92 = E.fr.add(tmp_55, params.challenges[1]);
     params.cm3_n[10 + i*15] = E.fr.add(tmp_92, params.challenges[2]);
     AltBn128::FrElement tmp_93 = params.cm1_n[2 + i*15];
     AltBn128::FrElement tmp_56 = E.fr.mul(params.challenges[2], params.x_n[i]);
     AltBn128::FrElement tmp_57 = E.fr.add(tmp_93, tmp_56);
     AltBn128::FrElement tmp_94 = E.fr.add(tmp_57, params.challenges[3]);
     AltBn128::FrElement tmp_95 = params.cm1_n[3 + i*15];
     AltBn128::FrElement tmp_58 = E.fr.mul(params.challenges[2], params.constValues[1]);
     AltBn128::FrElement tmp_59 = E.fr.mul(tmp_58, params.x_n[i]);
     AltBn128::FrElement tmp_60 = E.fr.add(tmp_95, tmp_59);
     AltBn128::FrElement tmp_61 = E.fr.add(tmp_60, params.challenges[3]);
     params.cm3_n[11 + i*15] = E.fr.mul(tmp_94, tmp_61);
     AltBn128::FrElement tmp_96 = params.cm1_n[4 + i*15];
     AltBn128::FrElement tmp_62 = E.fr.mul(params.challenges[2], params.constValues[2]);
     AltBn128::FrElement tmp_63 = E.fr.mul(tmp_62, params.x_n[i]);
     AltBn128::FrElement tmp_64 = E.fr.add(tmp_96, tmp_63);
     AltBn128::FrElement tmp_65 = E.fr.add(tmp_64, params.challenges[3]);
     params.cm3_n[13 + i*15] = E.fr.mul(params.cm3_n[11 + i*15], tmp_65);
     AltBn128::FrElement tmp_97 = params.const_n[3 + i * 9];
     AltBn128::FrElement tmp_66 = E.fr.mul(params.challenges[2], tmp_97);
     AltBn128::FrElement tmp_67 = E.fr.add(tmp_93, tmp_66);
     AltBn128::FrElement tmp_98 = E.fr.add(tmp_67, params.challenges[3]);
     AltBn128::FrElement tmp_99 = params.const_n[4 + i * 9];
     AltBn128::FrElement tmp_68 = E.fr.mul(params.challenges[2], tmp_99);
     AltBn128::FrElement tmp_69 = E.fr.add(tmp_95, tmp_68);
     AltBn128::FrElement tmp_70 = E.fr.add(tmp_69, params.challenges[3]);
     params.cm3_n[12 + i*15] = E.fr.mul(tmp_98, tmp_70);
     AltBn128::FrElement tmp_100 = params.const_n[5 + i * 9];
     AltBn128::FrElement tmp_71 = E.fr.mul(params.challenges[2], tmp_100);
     AltBn128::FrElement tmp_72 = E.fr.add(tmp_96, tmp_71);
     AltBn128::FrElement tmp_73 = E.fr.add(tmp_72, params.challenges[3]);
     params.cm3_n[14 + i*15] = E.fr.mul(params.cm3_n[12 + i*15], tmp_73);
}
