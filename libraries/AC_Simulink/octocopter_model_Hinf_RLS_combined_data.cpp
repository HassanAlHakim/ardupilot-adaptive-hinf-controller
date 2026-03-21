//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: octocopter_model_Hinf_RLS_combined_data.cpp
//
// Code generated for Simulink model 'octocopter_model_Hinf_RLS_combined'.
//
// Model version                  : 16.132
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Sat Mar 21 20:48:26 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "octocopter_model_Hinf_RLS_combined.h"

// model 7

// Block parameters (default storage)
octocopter_model_Hinf_RLS_combined::P_octocopter_model_Hinf_RLS_c_T
  octocopter_model_Hinf_RLS_combined::octocopter_model_Hinf_RLS_com_P{
  // Variable: Ixx_m
  //  Referenced by:
  //    '<S21>/Constant'
  //    '<S21>/Constant1'
  //    '<S21>/Constant4'
  //    '<S21>/Constant8'

  0.93695,

  // Variable: Iyy_m
  //  Referenced by:
  //    '<S21>/Constant1'
  //    '<S21>/Constant3'
  //    '<S21>/Constant4'
  //    '<S21>/Constant8'

  0.92838,

  // Variable: Izz_m
  //  Referenced by:
  //    '<S21>/Constant1'
  //    '<S21>/Constant4'
  //    '<S21>/Constant6'
  //    '<S21>/Constant8'

  1.17248,

  // Variable: Ts
  //  Referenced by:
  //    '<S1>/Constant'
  //    '<S1>/Constant4'
  //    '<S1>/Constant6'

  0.0025,

  // Variable: twait_RLS
  //  Referenced by:
  //    '<S21>/Step1'
  //    '<S21>/Step2'
  //    '<S21>/Step4'

  5000.0,

  // Variable: A_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 0.965620041F, -0.0115724066F, -0.0216502F, 0.00377476565F, -0.0168817397F,
    -0.0172084086F, 2.17102469E-9F, -2.8231073E-9F, -0.00352787133F,
    -7.15602218E-5F, -5.51549073E-9F, -0.0154115865F, 0.953608036F,
    -0.0133849271F, 0.0180760454F, -0.00586498249F, -0.0130035607F,
    5.43483702E-9F, 1.73755654E-9F, -0.00186131115F, -0.00316155073F,
    3.39466855E-9F, 0.00804214459F, 0.00407156954F, 0.978325665F,
    0.000899018371F, 0.00718655111F, 0.00182676851F, -6.95999702E-8F,
    -6.16801898E-8F, -0.00940312259F, 0.0043551079F, -1.20505092E-7F,
    -0.0192509592F, 0.00227878196F, -0.00943467207F, 0.958310246F,
    -0.0233886689F, 0.00878992863F, 7.44852047E-9F, 4.32968639E-9F,
    0.00816635136F, 0.00687414454F, 8.45892334E-9F, 0.00387813384F,
    0.00447601033F, -0.0141913155F, 0.00654608943F, 0.97596091F, 0.0114300614F,
    2.05903961E-9F, -1.62208902E-9F, -0.00720818434F, 0.0117570898F,
    -3.16905924E-9F, 0.00502842199F, 0.0174940508F, -0.00801703706F,
    -0.0287742615F, -0.0200289059F, 0.975520432F, 6.76711087E-9F, 4.53868365E-9F,
    -0.00770099508F, -0.00823596399F, 8.86724738E-9F, -5.43430323E-9F,
    1.2295942E-9F, -6.96049582E-8F, 3.81377685E-9F, -4.24442614E-9F,
    4.79206363E-9F, 0.701037765F, -0.245952368F, 2.43458143E-9F, -1.22218924E-9F,
    -0.480518937F, -1.65114367E-9F, 1.0162744E-9F, -3.60743684E-8F,
    2.53230659E-9F, -9.48732537E-10F, 2.6544924E-9F, -0.143848196F, 0.832346201F,
    -4.21245883E-14F, 5.66880315E-15F, -0.225467801F, -9.53611197E-6F,
    -0.0114664249F, 0.0166211575F, -0.0230126195F, 0.0163414348F, 0.0173112638F,
    -4.44259696E-9F, -1.79109115E-14F, 0.975602388F, -1.11735385E-16F,
    -1.76408706E-14F, 0.00716507854F, -0.00122568954F, -0.00614151172F,
    -0.00293168798F, -0.0266541075F, 0.0263524149F, 2.05972417E-9F,
    -1.29794806E-14F, -1.41159777E-15F, 0.975602388F, -2.8639878E-14F,
    -1.94782523E-9F, 1.19893606E-9F, -4.25567102E-8F, 2.98735592E-9F,
    -1.11920906E-9F, 3.13150794E-9F, -0.169696972F, -0.195250601F,
    -4.95337041E-14F, 8.51499691E-15F, 0.668171048F },

  // Variable: B_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { -0.0629466549F, 0.0112029808F, 0.0158296768F, -0.00196923013F, 0.216727331F,
    -0.102363527F, -6.52060139E-9F, 3.62833705E-13F, -0.0828098878F,
    0.383458644F, 7.27756559E-13F, 0.062291909F, -0.0854061693F, 0.0558438934F,
    -0.161530986F, 0.0760071352F, 0.125015572F, -1.63605307E-8F, 7.8849965E-14F,
    -0.383458644F, -0.0828098878F, 3.21857666E-13F, -5.51545121E-8F,
    3.39482114E-8F, -1.20503444E-6F, 8.45893808E-8F, -3.16911155E-8F,
    8.8671527E-8F, -4.80513096F, -4.59549189F, -1.27206286E-12F, 2.17944559E-13F,
    -7.71911716F },

  // Variable: C_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 2.57052636F, 5.75823259F, -4.5106578E-8F, -1.79067934F, 6.57722759F,
    2.77559877E-8F, 1.61454654F, 2.15261817F, -9.8549242E-7F, 6.94755888F,
    -2.83114552F, 6.91741207E-8F, 5.19790936F, 1.82292724F, -2.59143658E-8F,
    2.59125447F, 1.42581677F, 7.25156042E-8F, -3.11213853E-7F, -5.9501707E-7F,
    -3.92967319F, 1.51135018E-12F, 6.39199934E-12F, 4.30538368F, -0.90716362F,
    -4.20070314F, -2.73008775E-13F, 4.20070314F, -0.90716362F, 9.79394517E-14F,
    -9.14919114E-14F, -2.71884051E-13F, -0.790503502F },

  // Variable: D_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 2.38511038F, -1.94243815E-14F, 1.85355176E-13F, -1.91648828E-15F,
    2.38511038F, 1.10391806E-12F, 8.97766887E-13F, 4.07541882E-12F, 22.5298939F
  },

  // Expression: 0
  //  Referenced by: '<S21>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Constant7'

  0.0,

  // Expression: 1
  //  Referenced by: '<S21>/Constant10'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Step4'

  0.0,

  // Expression: 1
  //  Referenced by: '<S21>/Step4'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S21>/Constant9'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Step1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S21>/Step1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch4'

  0.0,

  // Expression: 1
  //  Referenced by: '<S21>/Constant11'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Step2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S21>/Step2'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Switch6'

  0.0,

  // Expression: 40
  //  Referenced by: '<S1>/Constant1'

  40.0,

  // Expression: 0
  //  Referenced by: '<S1>/Step'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1>/Step'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/Step'

  0.0,

  // Expression: 40
  //  Referenced by: '<S1>/Constant5'

  40.0,

  // Expression: 0
  //  Referenced by: '<S1>/Step1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1>/Step1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/Step1'

  0.0,

  // Expression: 40
  //  Referenced by: '<S1>/Constant7'

  40.0,

  // Expression: 0
  //  Referenced by: '<S1>/Step2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1>/Step2'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/Step2'

  0.0,

  // Computed Parameter: DiscreteStateSpace_InitialCondi
  //  Referenced by: '<S1>/Discrete State-Space'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition
  //  Referenced by: '<S21>/Delay1'

  1.07526886F,

  // Computed Parameter: Delay2_InitialCondition
  //  Referenced by: '<S21>/Delay2'

  0.0F,

  // Computed Parameter: Delay4_InitialCondition
  //  Referenced by: '<S21>/Delay4'

  0.0F,

  // Computed Parameter: Delay3_InitialCondition
  //  Referenced by: '<S21>/Delay3'

  1.0869565F,

  // Computed Parameter: Delay5_InitialCondition
  //  Referenced by: '<S21>/Delay5'

  0.0F,

  // Computed Parameter: Delay6_InitialCondition
  //  Referenced by: '<S21>/Delay6'

  0.0F,

  // Computed Parameter: Delay7_InitialCondition
  //  Referenced by: '<S21>/Delay7'

  0.0F,

  // Computed Parameter: Delay9_InitialCondition
  //  Referenced by: '<S21>/Delay9'

  0.0F,

  // Computed Parameter: Delay8_InitialCondition
  //  Referenced by: '<S21>/Delay8'

  0.854700863F,

  // Computed Parameter: Delay9_InitialCondition_o
  //  Referenced by: '<S1>/Delay9'

  0.0F,

  // Computed Parameter: Delay2_InitialCondition_l
  //  Referenced by: '<S1>/Delay2'

  0.0F,

  // Computed Parameter: Delay_InitialCondition
  //  Referenced by: '<S1>/Delay'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition_f
  //  Referenced by: '<S1>/Delay1'

  0.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S21>/Gain1'

  0.0F,

  // Computed Parameter: Delay10_InitialCondition
  //  Referenced by: '<S1>/Delay10'

  0.0F,

  // Computed Parameter: Delay5_InitialCondition_l
  //  Referenced by: '<S1>/Delay5'

  0.0F,

  // Computed Parameter: Delay3_InitialCondition_a
  //  Referenced by: '<S1>/Delay3'

  0.0F,

  // Computed Parameter: Delay4_InitialCondition_o
  //  Referenced by: '<S1>/Delay4'

  0.0F,

  // Computed Parameter: Delay11_InitialCondition
  //  Referenced by: '<S1>/Delay11'

  0.0F,

  // Computed Parameter: Delay6_InitialCondition_f
  //  Referenced by: '<S1>/Delay6'

  0.0F,

  // Computed Parameter: Delay7_InitialCondition_c
  //  Referenced by: '<S1>/Delay7'

  0.0F,

  // Computed Parameter: Delay8_InitialCondition_f
  //  Referenced by: '<S1>/Delay8'

  0.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S21>/Gain2'

  0.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S21>/Gain'

  0.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
