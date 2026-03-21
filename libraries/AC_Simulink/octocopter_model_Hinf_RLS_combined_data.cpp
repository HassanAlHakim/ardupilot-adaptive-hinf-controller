//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: octocopter_model_Hinf_RLS_combined_data.cpp
//
// Code generated for Simulink model 'octocopter_model_Hinf_RLS_combined'.
//
// Model version                  : 16.130
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Sun Mar 15 22:53:41 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "octocopter_model_Hinf_RLS_combined.h"

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

  { 0.952103555F, 0.0169684775F, 0.0132903643F, 0.00912392233F, 0.00545984227F,
    0.0300815906F, 1.78375572E-8F, -2.01131147E-8F, 0.00574178761F,
    0.0128188385F, -1.20525181E-8F, -0.0185857825F, 0.965337753F, -0.0196194723F,
    -0.0272026379F, 0.00739427144F, 0.0378222689F, -9.42341227E-9F,
    6.22019272E-8F, -0.00849753339F, -0.0183495954F, 3.72737183E-8F,
    -0.0143198445F, 0.0206684284F, 0.972067058F, 0.0402924903F, -0.0256403424F,
    -0.0018543388F, -1.83586657E-8F, -1.12644194E-7F, -0.00349247456F,
    0.0168453511F, -6.75007712E-8F, -0.0141648119F, 0.038520962F, -0.011696537F,
    0.975148439F, -0.00934754126F, -0.00112700218F, -2.82050276E-8F,
    2.36237653E-7F, 0.0315310918F, -0.0377054065F, 1.4156295E-7F, 0.00430429913F,
    0.00377272908F, 0.0112795327F, -0.00943301339F, 0.967766106F, 0.0387116894F,
    -9.64488081E-8F, 7.33012655E-7F, 0.0195119306F, 0.030479271F, 4.39249789E-7F,
    -0.0326880217F, -0.00216162833F, 0.00836237893F, -0.000818232773F,
    -0.0260368232F, 0.978947818F, -6.94275926E-8F, -5.92082792E-8F,
    -0.0417839922F, -0.0101351216F, -3.54801841E-8F, 1.14064509E-8F,
    2.76207182E-8F, 2.28729924E-8F, -6.71331932E-8F, -6.59750938E-8F,
    1.15179532E-7F, 0.995537043F, -0.26956749F, 8.89346E-8F, 3.98321767E-8F,
    -0.161535308F, -6.70933753E-10F, 2.07661222E-9F, -3.7601704E-9F,
    7.88569388E-9F, 2.44682479E-8F, -1.97639927E-9F, -0.00899831951F,
    0.804080725F, -1.6230525E-12F, -2.70755505E-13F, -0.0984558538F,
    -0.0371420532F, -0.0316080488F, -0.00169541151F, 0.0145635344F,
    0.0157909133F, 0.0007388792F, 5.17255181E-8F, -2.69505094E-13F, 0.943530917F,
    2.98580744E-15F, -3.17122088E-13F, -0.0284087732F, 0.024813192F,
    0.00817744154F, -0.0256256852F, 0.00852799509F, -0.0249888953F,
    1.06489209E-8F, -3.3005353E-13F, 5.17527856E-15F, 0.943530917F,
    -2.28842607E-13F, 3.0749483E-9F, -9.50946E-9F, 1.72212147E-8F,
    -3.61164929E-8F, -1.12064093E-7F, 9.05200093E-9F, 0.0412118398F, -0.0517632F,
    -5.5237504E-13F, -1.13726072E-13F, 0.959686577F },

  // Variable: B_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 0.0371380597F, 0.0242556017F, 0.718153894F, 0.102288559F, 0.116940461F,
    0.0689109191F, 9.52231716E-8F, -6.48224259E-13F, 0.000570970529F,
    0.0502216108F, -3.28945828E-13F, -0.0455166847F, -0.299241751F, 0.157429665F,
    -0.240696922F, -0.591450095F, -0.149831831F, -1.91774893E-6F,
    -2.50214367E-12F, -0.0502216108F, 0.000570970529F, -1.79513457E-12F,
    2.0275829E-8F, -6.2705567E-8F, 1.13557796E-7F, -2.38152651E-7F,
    -7.38951201E-7F, 5.96889649E-8F, 0.271750897F, 4.32616663F, 4.89902077E-11F,
    8.25225391E-12F, 1.98859823F },

  // Variable: C_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 6.18596363F, -8.14059258F, 2.30844137E-7F, -4.35883665F, -10.6544733F,
    -7.13910367E-7F, 6.95847034F, 1.52539945F, 1.29285729E-6F, 7.52946854F,
    0.84545821F, -2.7113897E-6F, -1.09268582F, -3.7234447F, -8.41303518E-6F,
    6.35512781F, -2.69586301F, 6.79566256E-7F, -2.14367105E-6F, -1.12803409E-5F,
    3.09391356F, -1.5874262E-11F, 7.92139757E-11F, 0.493081152F, 0.0848210379F,
    -7.46071625F, 6.28507055E-12F, 7.46071625F, 0.0848210379F, 5.64585867E-13F,
    3.53742751E-13F, 1.06891267E-11F, 2.77186179F },

  // Variable: D_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 6.56628513F, 1.03328872E-13F, 4.2128524E-13F, -8.11017919E-14F, 6.56628513F,
    -1.67006556E-12F, -1.54414101E-12F, -4.80825622E-11F, 39.3711205F },

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

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S1>/Saturation2'

  64.5F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S1>/Saturation2'

  -64.5F,

  // Computed Parameter: Delay3_InitialCondition
  //  Referenced by: '<S21>/Delay3'

  1.0869565F,

  // Computed Parameter: Delay5_InitialCondition
  //  Referenced by: '<S21>/Delay5'

  0.0F,

  // Computed Parameter: Delay6_InitialCondition
  //  Referenced by: '<S21>/Delay6'

  0.0F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S1>/Saturation1'

  64.5F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S1>/Saturation1'

  -64.5F,

  // Computed Parameter: Delay7_InitialCondition
  //  Referenced by: '<S21>/Delay7'

  0.0F,

  // Computed Parameter: Delay9_InitialCondition
  //  Referenced by: '<S21>/Delay9'

  0.0F,

  // Computed Parameter: Delay8_InitialCondition
  //  Referenced by: '<S21>/Delay8'

  0.854700863F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S1>/Saturation'

  3.2F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S1>/Saturation'

  -3.2F,

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
