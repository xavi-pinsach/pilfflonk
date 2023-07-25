#include <alt_bn128.hpp>
#include "pilfflonk_steps.hpp"

void PilFflonkSteps::step3_first(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_74 = E.fr.mul(params.cm1_n[0 + i*15], params.cm1_n[0 + i*15]);
     AltBn128::FrElement tmp_75 = E.fr.mul(params.cm1_n[1 + i*15], params.cm1_n[1 + i*15]);
     params.cm3_n[3 + i*15] = E.fr.add(tmp_74, tmp_75);
     params.cm3_n[4 + i*15] = E.fr.mul(params.cm1_n[12 + i*15], params.cm1_n[13 + ((i + 1)%256)*15]);
     AltBn128::FrElement tmp_138 = params.const_n[7 + i * 9];
     AltBn128::FrElement tmp_139 = params.const_n[8 + i * 9];
     AltBn128::FrElement tmp_140 = params.cm1_n[14 + i*15];
     AltBn128::FrElement tmp_141 = params.const_n[6 + i * 9];
     AltBn128::FrElement tmp_76 = E.fr.mul(params.challenges[0], tmp_138);
     AltBn128::FrElement tmp_77 = E.fr.add(tmp_76, tmp_139);
     AltBn128::FrElement tmp_78 = E.fr.mul(params.challenges[0], tmp_77);
     AltBn128::FrElement tmp_79 = E.fr.add(tmp_78, tmp_140);
     AltBn128::FrElement tmp_80 = E.fr.sub(tmp_79, params.challenges[1]);
     AltBn128::FrElement tmp_81 = E.fr.mul(tmp_80, tmp_141);
     params.cm3_n[5 + i*15] = E.fr.add(tmp_81, params.challenges[1]);
     AltBn128::FrElement tmp_142 = params.cm1_n[12 + i*15];
     AltBn128::FrElement tmp_143 = params.cm1_n[13 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_144 = params.cm1_n[11 + i*15];
     AltBn128::FrElement tmp_82 = E.fr.mul(tmp_142, params.challenges[0]);
     AltBn128::FrElement tmp_83 = E.fr.add(tmp_82, tmp_143);
     AltBn128::FrElement tmp_84 = E.fr.mul(tmp_83, params.challenges[0]);
     AltBn128::FrElement tmp_85 = E.fr.add(tmp_84, params.cm3_n[4 + i*15]);
     AltBn128::FrElement tmp_86 = E.fr.sub(tmp_85, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_87 = E.fr.mul(tmp_86, tmp_144);
     params.cm3_n[6 + i*15] = E.fr.add(tmp_87, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_145 = params.const_n[7 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_146 = params.const_n[8 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_147 = params.cm1_n[14 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_148 = params.const_n[6 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_88 = E.fr.mul(params.challenges[0], tmp_145);
     AltBn128::FrElement tmp_89 = E.fr.add(tmp_88, tmp_146);
     AltBn128::FrElement tmp_90 = E.fr.mul(params.challenges[0], tmp_89);
     AltBn128::FrElement tmp_91 = E.fr.add(tmp_90, tmp_147);
     AltBn128::FrElement tmp_92 = E.fr.sub(tmp_91, params.challenges[1]);
     AltBn128::FrElement tmp_93 = E.fr.mul(tmp_92, tmp_148);
     params.cm3_n[5 + ((i + 1)%256)*15] = E.fr.add(tmp_93, params.challenges[1]);
     AltBn128::FrElement tmp_94 = E.fr.add(params.cm3_n[6 + i*15], params.challenges[3]);
     AltBn128::FrElement tmp_95 = E.fr.mul(params.cm3_n[5 + ((i + 1)%256)*15], params.challenges[2]);
     AltBn128::FrElement tmp_96 = E.fr.add(params.cm3_n[5 + i*15], tmp_95);
     AltBn128::FrElement tmp_97 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_98 = E.fr.mul(params.challenges[3], tmp_97);
     AltBn128::FrElement tmp_99 = E.fr.add(tmp_96, tmp_98);
     AltBn128::FrElement tmp_100 = E.fr.mul(tmp_94, tmp_99);
     AltBn128::FrElement tmp_101 = E.fr.add(params.constValues[0], params.challenges[2]);
     params.cm3_n[7 + i*15] = E.fr.mul(tmp_100, tmp_101);
     AltBn128::FrElement tmp_102 = E.fr.mul(params.cm2_n[1 + i*2], params.challenges[2]);
     AltBn128::FrElement tmp_103 = E.fr.add(params.cm2_n[0 + i*2], tmp_102);
     AltBn128::FrElement tmp_104 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_105 = E.fr.mul(params.challenges[3], tmp_104);
     AltBn128::FrElement tmp_106 = E.fr.add(tmp_103, tmp_105);
     AltBn128::FrElement tmp_107 = E.fr.mul(params.cm2_n[0 + ((i + 1)%256)*2], params.challenges[2]);
     AltBn128::FrElement tmp_108 = E.fr.add(params.cm2_n[1 + i*2], tmp_107);
     AltBn128::FrElement tmp_109 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_110 = E.fr.mul(params.challenges[3], tmp_109);
     AltBn128::FrElement tmp_111 = E.fr.add(tmp_108, tmp_110);
     params.cm3_n[8 + i*15] = E.fr.mul(tmp_106, tmp_111);
     AltBn128::FrElement tmp_149 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_150 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_151 = params.cm1_n[9 + i*15];
     AltBn128::FrElement tmp_112 = E.fr.mul(tmp_149, params.challenges[0]);
     AltBn128::FrElement tmp_113 = E.fr.add(tmp_112, tmp_150);
     AltBn128::FrElement tmp_114 = E.fr.sub(tmp_113, params.challenges[1]);
     AltBn128::FrElement tmp_115 = E.fr.mul(tmp_114, tmp_151);
     AltBn128::FrElement tmp_152 = E.fr.add(tmp_115, params.challenges[1]);
     params.cm3_n[9 + i*15] = E.fr.add(tmp_152, params.challenges[2]);
     AltBn128::FrElement tmp_153 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_154 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_155 = params.cm1_n[10 + i*15];
     AltBn128::FrElement tmp_116 = E.fr.mul(params.challenges[0], tmp_153);
     AltBn128::FrElement tmp_117 = E.fr.add(tmp_116, tmp_154);
     AltBn128::FrElement tmp_118 = E.fr.sub(tmp_117, params.challenges[1]);
     AltBn128::FrElement tmp_119 = E.fr.mul(tmp_118, tmp_155);
     AltBn128::FrElement tmp_156 = E.fr.add(tmp_119, params.challenges[1]);
     params.cm3_n[10 + i*15] = E.fr.add(tmp_156, params.challenges[2]);
     AltBn128::FrElement tmp_157 = params.cm1_n[2 + i*15];
     AltBn128::FrElement tmp_120 = E.fr.mul(params.challenges[2], params.x_n[i]);
     AltBn128::FrElement tmp_121 = E.fr.add(tmp_157, tmp_120);
     AltBn128::FrElement tmp_158 = E.fr.add(tmp_121, params.challenges[3]);
     AltBn128::FrElement tmp_159 = params.cm1_n[3 + i*15];
     AltBn128::FrElement tmp_122 = E.fr.mul(params.challenges[2], params.constValues[1]);
     AltBn128::FrElement tmp_123 = E.fr.mul(tmp_122, params.x_n[i]);
     AltBn128::FrElement tmp_124 = E.fr.add(tmp_159, tmp_123);
     AltBn128::FrElement tmp_125 = E.fr.add(tmp_124, params.challenges[3]);
     params.cm3_n[11 + i*15] = E.fr.mul(tmp_158, tmp_125);
     AltBn128::FrElement tmp_160 = params.const_n[3 + i * 9];
     AltBn128::FrElement tmp_126 = E.fr.mul(params.challenges[2], tmp_160);
     AltBn128::FrElement tmp_127 = E.fr.add(tmp_157, tmp_126);
     AltBn128::FrElement tmp_161 = E.fr.add(tmp_127, params.challenges[3]);
     AltBn128::FrElement tmp_162 = params.const_n[4 + i * 9];
     AltBn128::FrElement tmp_128 = E.fr.mul(params.challenges[2], tmp_162);
     AltBn128::FrElement tmp_129 = E.fr.add(tmp_159, tmp_128);
     AltBn128::FrElement tmp_130 = E.fr.add(tmp_129, params.challenges[3]);
     params.cm3_n[12 + i*15] = E.fr.mul(tmp_161, tmp_130);
     AltBn128::FrElement tmp_163 = params.cm1_n[4 + i*15];
     AltBn128::FrElement tmp_131 = E.fr.mul(params.challenges[2], params.constValues[2]);
     AltBn128::FrElement tmp_132 = E.fr.mul(tmp_131, params.x_n[i]);
     AltBn128::FrElement tmp_133 = E.fr.add(tmp_163, tmp_132);
     AltBn128::FrElement tmp_134 = E.fr.add(tmp_133, params.challenges[3]);
     params.cm3_n[13 + i*15] = E.fr.mul(params.cm3_n[11 + i*15], tmp_134);
     AltBn128::FrElement tmp_164 = params.const_n[5 + i * 9];
     AltBn128::FrElement tmp_135 = E.fr.mul(params.challenges[2], tmp_164);
     AltBn128::FrElement tmp_136 = E.fr.add(tmp_163, tmp_135);
     AltBn128::FrElement tmp_137 = E.fr.add(tmp_136, params.challenges[3]);
     params.cm3_n[14 + i*15] = E.fr.mul(params.cm3_n[12 + i*15], tmp_137);
}

void PilFflonkSteps::step3_i(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_74 = E.fr.mul(params.cm1_n[0 + i*15], params.cm1_n[0 + i*15]);
     AltBn128::FrElement tmp_75 = E.fr.mul(params.cm1_n[1 + i*15], params.cm1_n[1 + i*15]);
     params.cm3_n[3 + i*15] = E.fr.add(tmp_74, tmp_75);
     params.cm3_n[4 + i*15] = E.fr.mul(params.cm1_n[12 + i*15], params.cm1_n[13 + ((i + 1)%256)*15]);
     AltBn128::FrElement tmp_138 = params.const_n[7 + i * 9];
     AltBn128::FrElement tmp_139 = params.const_n[8 + i * 9];
     AltBn128::FrElement tmp_140 = params.cm1_n[14 + i*15];
     AltBn128::FrElement tmp_141 = params.const_n[6 + i * 9];
     AltBn128::FrElement tmp_76 = E.fr.mul(params.challenges[0], tmp_138);
     AltBn128::FrElement tmp_77 = E.fr.add(tmp_76, tmp_139);
     AltBn128::FrElement tmp_78 = E.fr.mul(params.challenges[0], tmp_77);
     AltBn128::FrElement tmp_79 = E.fr.add(tmp_78, tmp_140);
     AltBn128::FrElement tmp_80 = E.fr.sub(tmp_79, params.challenges[1]);
     AltBn128::FrElement tmp_81 = E.fr.mul(tmp_80, tmp_141);
     params.cm3_n[5 + i*15] = E.fr.add(tmp_81, params.challenges[1]);
     AltBn128::FrElement tmp_142 = params.cm1_n[12 + i*15];
     AltBn128::FrElement tmp_143 = params.cm1_n[13 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_144 = params.cm1_n[11 + i*15];
     AltBn128::FrElement tmp_82 = E.fr.mul(tmp_142, params.challenges[0]);
     AltBn128::FrElement tmp_83 = E.fr.add(tmp_82, tmp_143);
     AltBn128::FrElement tmp_84 = E.fr.mul(tmp_83, params.challenges[0]);
     AltBn128::FrElement tmp_85 = E.fr.add(tmp_84, params.cm3_n[4 + i*15]);
     AltBn128::FrElement tmp_86 = E.fr.sub(tmp_85, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_87 = E.fr.mul(tmp_86, tmp_144);
     params.cm3_n[6 + i*15] = E.fr.add(tmp_87, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_145 = params.const_n[7 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_146 = params.const_n[8 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_147 = params.cm1_n[14 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_148 = params.const_n[6 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_88 = E.fr.mul(params.challenges[0], tmp_145);
     AltBn128::FrElement tmp_89 = E.fr.add(tmp_88, tmp_146);
     AltBn128::FrElement tmp_90 = E.fr.mul(params.challenges[0], tmp_89);
     AltBn128::FrElement tmp_91 = E.fr.add(tmp_90, tmp_147);
     AltBn128::FrElement tmp_92 = E.fr.sub(tmp_91, params.challenges[1]);
     AltBn128::FrElement tmp_93 = E.fr.mul(tmp_92, tmp_148);
     params.cm3_n[5 + ((i + 1)%256)*15] = E.fr.add(tmp_93, params.challenges[1]);
     AltBn128::FrElement tmp_94 = E.fr.add(params.cm3_n[6 + i*15], params.challenges[3]);
     AltBn128::FrElement tmp_95 = E.fr.mul(params.cm3_n[5 + ((i + 1)%256)*15], params.challenges[2]);
     AltBn128::FrElement tmp_96 = E.fr.add(params.cm3_n[5 + i*15], tmp_95);
     AltBn128::FrElement tmp_97 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_98 = E.fr.mul(params.challenges[3], tmp_97);
     AltBn128::FrElement tmp_99 = E.fr.add(tmp_96, tmp_98);
     AltBn128::FrElement tmp_100 = E.fr.mul(tmp_94, tmp_99);
     AltBn128::FrElement tmp_101 = E.fr.add(params.constValues[0], params.challenges[2]);
     params.cm3_n[7 + i*15] = E.fr.mul(tmp_100, tmp_101);
     AltBn128::FrElement tmp_102 = E.fr.mul(params.cm2_n[1 + i*2], params.challenges[2]);
     AltBn128::FrElement tmp_103 = E.fr.add(params.cm2_n[0 + i*2], tmp_102);
     AltBn128::FrElement tmp_104 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_105 = E.fr.mul(params.challenges[3], tmp_104);
     AltBn128::FrElement tmp_106 = E.fr.add(tmp_103, tmp_105);
     AltBn128::FrElement tmp_107 = E.fr.mul(params.cm2_n[0 + ((i + 1)%256)*2], params.challenges[2]);
     AltBn128::FrElement tmp_108 = E.fr.add(params.cm2_n[1 + i*2], tmp_107);
     AltBn128::FrElement tmp_109 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_110 = E.fr.mul(params.challenges[3], tmp_109);
     AltBn128::FrElement tmp_111 = E.fr.add(tmp_108, tmp_110);
     params.cm3_n[8 + i*15] = E.fr.mul(tmp_106, tmp_111);
     AltBn128::FrElement tmp_149 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_150 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_151 = params.cm1_n[9 + i*15];
     AltBn128::FrElement tmp_112 = E.fr.mul(tmp_149, params.challenges[0]);
     AltBn128::FrElement tmp_113 = E.fr.add(tmp_112, tmp_150);
     AltBn128::FrElement tmp_114 = E.fr.sub(tmp_113, params.challenges[1]);
     AltBn128::FrElement tmp_115 = E.fr.mul(tmp_114, tmp_151);
     AltBn128::FrElement tmp_152 = E.fr.add(tmp_115, params.challenges[1]);
     params.cm3_n[9 + i*15] = E.fr.add(tmp_152, params.challenges[2]);
     AltBn128::FrElement tmp_153 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_154 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_155 = params.cm1_n[10 + i*15];
     AltBn128::FrElement tmp_116 = E.fr.mul(params.challenges[0], tmp_153);
     AltBn128::FrElement tmp_117 = E.fr.add(tmp_116, tmp_154);
     AltBn128::FrElement tmp_118 = E.fr.sub(tmp_117, params.challenges[1]);
     AltBn128::FrElement tmp_119 = E.fr.mul(tmp_118, tmp_155);
     AltBn128::FrElement tmp_156 = E.fr.add(tmp_119, params.challenges[1]);
     params.cm3_n[10 + i*15] = E.fr.add(tmp_156, params.challenges[2]);
     AltBn128::FrElement tmp_157 = params.cm1_n[2 + i*15];
     AltBn128::FrElement tmp_120 = E.fr.mul(params.challenges[2], params.x_n[i]);
     AltBn128::FrElement tmp_121 = E.fr.add(tmp_157, tmp_120);
     AltBn128::FrElement tmp_158 = E.fr.add(tmp_121, params.challenges[3]);
     AltBn128::FrElement tmp_159 = params.cm1_n[3 + i*15];
     AltBn128::FrElement tmp_122 = E.fr.mul(params.challenges[2], params.constValues[1]);
     AltBn128::FrElement tmp_123 = E.fr.mul(tmp_122, params.x_n[i]);
     AltBn128::FrElement tmp_124 = E.fr.add(tmp_159, tmp_123);
     AltBn128::FrElement tmp_125 = E.fr.add(tmp_124, params.challenges[3]);
     params.cm3_n[11 + i*15] = E.fr.mul(tmp_158, tmp_125);
     AltBn128::FrElement tmp_160 = params.const_n[3 + i * 9];
     AltBn128::FrElement tmp_126 = E.fr.mul(params.challenges[2], tmp_160);
     AltBn128::FrElement tmp_127 = E.fr.add(tmp_157, tmp_126);
     AltBn128::FrElement tmp_161 = E.fr.add(tmp_127, params.challenges[3]);
     AltBn128::FrElement tmp_162 = params.const_n[4 + i * 9];
     AltBn128::FrElement tmp_128 = E.fr.mul(params.challenges[2], tmp_162);
     AltBn128::FrElement tmp_129 = E.fr.add(tmp_159, tmp_128);
     AltBn128::FrElement tmp_130 = E.fr.add(tmp_129, params.challenges[3]);
     params.cm3_n[12 + i*15] = E.fr.mul(tmp_161, tmp_130);
     AltBn128::FrElement tmp_163 = params.cm1_n[4 + i*15];
     AltBn128::FrElement tmp_131 = E.fr.mul(params.challenges[2], params.constValues[2]);
     AltBn128::FrElement tmp_132 = E.fr.mul(tmp_131, params.x_n[i]);
     AltBn128::FrElement tmp_133 = E.fr.add(tmp_163, tmp_132);
     AltBn128::FrElement tmp_134 = E.fr.add(tmp_133, params.challenges[3]);
     params.cm3_n[13 + i*15] = E.fr.mul(params.cm3_n[11 + i*15], tmp_134);
     AltBn128::FrElement tmp_164 = params.const_n[5 + i * 9];
     AltBn128::FrElement tmp_135 = E.fr.mul(params.challenges[2], tmp_164);
     AltBn128::FrElement tmp_136 = E.fr.add(tmp_163, tmp_135);
     AltBn128::FrElement tmp_137 = E.fr.add(tmp_136, params.challenges[3]);
     params.cm3_n[14 + i*15] = E.fr.mul(params.cm3_n[12 + i*15], tmp_137);
}

void PilFflonkSteps::step3_last(AltBn128::Engine &E, StepsParams &params, uint64_t i) {
     AltBn128::FrElement tmp_74 = E.fr.mul(params.cm1_n[0 + i*15], params.cm1_n[0 + i*15]);
     AltBn128::FrElement tmp_75 = E.fr.mul(params.cm1_n[1 + i*15], params.cm1_n[1 + i*15]);
     params.cm3_n[3 + i*15] = E.fr.add(tmp_74, tmp_75);
     params.cm3_n[4 + i*15] = E.fr.mul(params.cm1_n[12 + i*15], params.cm1_n[13 + ((i + 1)%256)*15]);
     AltBn128::FrElement tmp_138 = params.const_n[7 + i * 9];
     AltBn128::FrElement tmp_139 = params.const_n[8 + i * 9];
     AltBn128::FrElement tmp_140 = params.cm1_n[14 + i*15];
     AltBn128::FrElement tmp_141 = params.const_n[6 + i * 9];
     AltBn128::FrElement tmp_76 = E.fr.mul(params.challenges[0], tmp_138);
     AltBn128::FrElement tmp_77 = E.fr.add(tmp_76, tmp_139);
     AltBn128::FrElement tmp_78 = E.fr.mul(params.challenges[0], tmp_77);
     AltBn128::FrElement tmp_79 = E.fr.add(tmp_78, tmp_140);
     AltBn128::FrElement tmp_80 = E.fr.sub(tmp_79, params.challenges[1]);
     AltBn128::FrElement tmp_81 = E.fr.mul(tmp_80, tmp_141);
     params.cm3_n[5 + i*15] = E.fr.add(tmp_81, params.challenges[1]);
     AltBn128::FrElement tmp_142 = params.cm1_n[12 + i*15];
     AltBn128::FrElement tmp_143 = params.cm1_n[13 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_144 = params.cm1_n[11 + i*15];
     AltBn128::FrElement tmp_82 = E.fr.mul(tmp_142, params.challenges[0]);
     AltBn128::FrElement tmp_83 = E.fr.add(tmp_82, tmp_143);
     AltBn128::FrElement tmp_84 = E.fr.mul(tmp_83, params.challenges[0]);
     AltBn128::FrElement tmp_85 = E.fr.add(tmp_84, params.cm3_n[4 + i*15]);
     AltBn128::FrElement tmp_86 = E.fr.sub(tmp_85, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_87 = E.fr.mul(tmp_86, tmp_144);
     params.cm3_n[6 + i*15] = E.fr.add(tmp_87, params.cm3_n[5 + i*15]);
     AltBn128::FrElement tmp_145 = params.const_n[7 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_146 = params.const_n[8 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_147 = params.cm1_n[14 + ((i + 1)%256)*15];
     AltBn128::FrElement tmp_148 = params.const_n[6 + ((i + 1)%256) * 9];
     AltBn128::FrElement tmp_88 = E.fr.mul(params.challenges[0], tmp_145);
     AltBn128::FrElement tmp_89 = E.fr.add(tmp_88, tmp_146);
     AltBn128::FrElement tmp_90 = E.fr.mul(params.challenges[0], tmp_89);
     AltBn128::FrElement tmp_91 = E.fr.add(tmp_90, tmp_147);
     AltBn128::FrElement tmp_92 = E.fr.sub(tmp_91, params.challenges[1]);
     AltBn128::FrElement tmp_93 = E.fr.mul(tmp_92, tmp_148);
     params.cm3_n[5 + ((i + 1)%256)*15] = E.fr.add(tmp_93, params.challenges[1]);
     AltBn128::FrElement tmp_94 = E.fr.add(params.cm3_n[6 + i*15], params.challenges[3]);
     AltBn128::FrElement tmp_95 = E.fr.mul(params.cm3_n[5 + ((i + 1)%256)*15], params.challenges[2]);
     AltBn128::FrElement tmp_96 = E.fr.add(params.cm3_n[5 + i*15], tmp_95);
     AltBn128::FrElement tmp_97 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_98 = E.fr.mul(params.challenges[3], tmp_97);
     AltBn128::FrElement tmp_99 = E.fr.add(tmp_96, tmp_98);
     AltBn128::FrElement tmp_100 = E.fr.mul(tmp_94, tmp_99);
     AltBn128::FrElement tmp_101 = E.fr.add(params.constValues[0], params.challenges[2]);
     params.cm3_n[7 + i*15] = E.fr.mul(tmp_100, tmp_101);
     AltBn128::FrElement tmp_102 = E.fr.mul(params.cm2_n[1 + i*2], params.challenges[2]);
     AltBn128::FrElement tmp_103 = E.fr.add(params.cm2_n[0 + i*2], tmp_102);
     AltBn128::FrElement tmp_104 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_105 = E.fr.mul(params.challenges[3], tmp_104);
     AltBn128::FrElement tmp_106 = E.fr.add(tmp_103, tmp_105);
     AltBn128::FrElement tmp_107 = E.fr.mul(params.cm2_n[0 + ((i + 1)%256)*2], params.challenges[2]);
     AltBn128::FrElement tmp_108 = E.fr.add(params.cm2_n[1 + i*2], tmp_107);
     AltBn128::FrElement tmp_109 = E.fr.add(params.constValues[0], params.challenges[2]);
     AltBn128::FrElement tmp_110 = E.fr.mul(params.challenges[3], tmp_109);
     AltBn128::FrElement tmp_111 = E.fr.add(tmp_108, tmp_110);
     params.cm3_n[8 + i*15] = E.fr.mul(tmp_106, tmp_111);
     AltBn128::FrElement tmp_149 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_150 = params.cm1_n[7 + i*15];
     AltBn128::FrElement tmp_151 = params.cm1_n[9 + i*15];
     AltBn128::FrElement tmp_112 = E.fr.mul(tmp_149, params.challenges[0]);
     AltBn128::FrElement tmp_113 = E.fr.add(tmp_112, tmp_150);
     AltBn128::FrElement tmp_114 = E.fr.sub(tmp_113, params.challenges[1]);
     AltBn128::FrElement tmp_115 = E.fr.mul(tmp_114, tmp_151);
     AltBn128::FrElement tmp_152 = E.fr.add(tmp_115, params.challenges[1]);
     params.cm3_n[9 + i*15] = E.fr.add(tmp_152, params.challenges[2]);
     AltBn128::FrElement tmp_153 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_154 = params.cm1_n[8 + i*15];
     AltBn128::FrElement tmp_155 = params.cm1_n[10 + i*15];
     AltBn128::FrElement tmp_116 = E.fr.mul(params.challenges[0], tmp_153);
     AltBn128::FrElement tmp_117 = E.fr.add(tmp_116, tmp_154);
     AltBn128::FrElement tmp_118 = E.fr.sub(tmp_117, params.challenges[1]);
     AltBn128::FrElement tmp_119 = E.fr.mul(tmp_118, tmp_155);
     AltBn128::FrElement tmp_156 = E.fr.add(tmp_119, params.challenges[1]);
     params.cm3_n[10 + i*15] = E.fr.add(tmp_156, params.challenges[2]);
     AltBn128::FrElement tmp_157 = params.cm1_n[2 + i*15];
     AltBn128::FrElement tmp_120 = E.fr.mul(params.challenges[2], params.x_n[i]);
     AltBn128::FrElement tmp_121 = E.fr.add(tmp_157, tmp_120);
     AltBn128::FrElement tmp_158 = E.fr.add(tmp_121, params.challenges[3]);
     AltBn128::FrElement tmp_159 = params.cm1_n[3 + i*15];
     AltBn128::FrElement tmp_122 = E.fr.mul(params.challenges[2], params.constValues[1]);
     AltBn128::FrElement tmp_123 = E.fr.mul(tmp_122, params.x_n[i]);
     AltBn128::FrElement tmp_124 = E.fr.add(tmp_159, tmp_123);
     AltBn128::FrElement tmp_125 = E.fr.add(tmp_124, params.challenges[3]);
     params.cm3_n[11 + i*15] = E.fr.mul(tmp_158, tmp_125);
     AltBn128::FrElement tmp_160 = params.const_n[3 + i * 9];
     AltBn128::FrElement tmp_126 = E.fr.mul(params.challenges[2], tmp_160);
     AltBn128::FrElement tmp_127 = E.fr.add(tmp_157, tmp_126);
     AltBn128::FrElement tmp_161 = E.fr.add(tmp_127, params.challenges[3]);
     AltBn128::FrElement tmp_162 = params.const_n[4 + i * 9];
     AltBn128::FrElement tmp_128 = E.fr.mul(params.challenges[2], tmp_162);
     AltBn128::FrElement tmp_129 = E.fr.add(tmp_159, tmp_128);
     AltBn128::FrElement tmp_130 = E.fr.add(tmp_129, params.challenges[3]);
     params.cm3_n[12 + i*15] = E.fr.mul(tmp_161, tmp_130);
     AltBn128::FrElement tmp_163 = params.cm1_n[4 + i*15];
     AltBn128::FrElement tmp_131 = E.fr.mul(params.challenges[2], params.constValues[2]);
     AltBn128::FrElement tmp_132 = E.fr.mul(tmp_131, params.x_n[i]);
     AltBn128::FrElement tmp_133 = E.fr.add(tmp_163, tmp_132);
     AltBn128::FrElement tmp_134 = E.fr.add(tmp_133, params.challenges[3]);
     params.cm3_n[13 + i*15] = E.fr.mul(params.cm3_n[11 + i*15], tmp_134);
     AltBn128::FrElement tmp_164 = params.const_n[5 + i * 9];
     AltBn128::FrElement tmp_135 = E.fr.mul(params.challenges[2], tmp_164);
     AltBn128::FrElement tmp_136 = E.fr.add(tmp_163, tmp_135);
     AltBn128::FrElement tmp_137 = E.fr.add(tmp_136, params.challenges[3]);
     params.cm3_n[14 + i*15] = E.fr.mul(params.cm3_n[12 + i*15], tmp_137);
}
