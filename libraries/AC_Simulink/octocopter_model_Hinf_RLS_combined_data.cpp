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
// C/C++ source code generated on : Mon Mar 23 17:44:45 2026
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

  { 0.976894915F, 0.0104147531F, 0.0105914036F, -0.0146083506F, -0.00224320521F,
    0.011525129F, 5.32540567E-10F, 5.02150044E-10F, 3.27201183E-10F,
    0.00269214506F, -0.00153291645F, -0.00591253163F, 0.972451806F,
    0.00554286083F, 0.00204149F, -0.0156797525F, 0.0116345324F, 6.68565203E-9F,
    2.49740539E-9F, 1.62727842E-9F, -0.000897170568F, -0.00173381658F,
    -0.0118027506F, -0.00103789323F, 0.970679104F, -0.000695617287F,
    -0.0105326334F, 0.0060157897F, 1.71317516E-9F, 9.70725189E-9F,
    6.32499697E-9F, 0.00129044848F, 0.000152674271F, 0.0166856628F,
    -0.000984476F, -0.00996320508F, 0.980438948F, 0.0072459979F, 0.0135590341F,
    -3.25144511E-9F, 6.81925072E-10F, 4.44252274E-10F, -0.000863289402F,
    0.00153625838F, 0.00627772044F, 0.00260906434F, 0.00364532042F,
    -0.0123469979F, 0.977931917F, -0.0143973641F, -4.4761812E-8F, 1.10718027E-7F,
    7.21405E-8F, 8.69727155E-5F, 0.00187459739F, -0.0110965017F, -0.0148658492F,
    -0.000301763677F, -0.0162995774F, 0.0111311246F, 0.977962077F,
    -3.97998523E-9F, -3.07694292E-9F, -2.00481165E-9F, 0.00198758137F,
    0.0017797926F, -2.90983304E-9F, -2.40025E-9F, -5.42975842E-9F,
    5.59942803E-9F, -4.36404584E-8F, 7.84974397E-9F, 0.887508154F, 0.225471169F,
    0.146910235F, -6.48201909E-11F, -8.84596563E-10F, 5.50342216E-10F,
    2.73812506E-9F, 1.06453566E-8F, 7.47456541E-10F, 1.21417472E-7F,
    -3.37426953E-9F, 0.247261494F, 0.373341888F, -0.374979138F, 5.40277E-13F,
    -5.43509356E-13F, 6.79643971E-12F, 3.40135871E-11F, 1.31855291E-10F,
    9.38198217E-12F, 1.50393775E-9F, -4.17887912E-11F, 0.0030623707F,
    -0.094814375F, 0.928401709F, 8.61478654E-14F, -8.44670674E-14F,
    0.00221091439F, -0.00320203532F, 0.000365505344F, 0.00488769915F,
    -0.00222149095F, -0.00312551321F, 1.04826425E-9F, 1.09048919E-13F,
    7.25522412E-14F, 0.986850262F, -6.93889804E-18F, -0.00125890214F,
    0.00368810422F, 0.00532896584F, 0.00245500822F, -0.00177354051F,
    0.00105398567F, 6.10365869E-10F, -1.11237862E-13F, -7.5017351E-14F,
    1.09781124E-15F, 0.986850262F },

  // Variable: B_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { -0.190884963F, 0.0219338331F, 0.0127120148F, 0.00397997955F, 0.0113206292F,
    0.0261328071F, -5.57941782E-9F, -1.26690433E-13F, 3.04387944E-13F,
    0.0545861796F, -0.0385601372F, -0.0186504181F, 0.0479694381F, -0.0625540242F,
    -0.11919456F, 0.00654618163F, -0.130746201F, -2.43509501E-9F,
    -5.55121704E-13F, -3.98584106E-13F, 0.0385601372F, 0.0545861796F,
    2.38037545E-9F, 1.18431327E-8F, 4.60440113E-8F, 3.23305049E-9F,
    5.25163955E-7F, -1.45947547E-8F, 1.06947386F, -2.54762268F, -1.53375697F,
    2.25111358E-12F, -2.27668101E-12F },

  // Variable: C_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { -7.09235144F, -0.692958295F, 1.01778541E-8F, -5.02815104F, -0.825303614F,
    5.06291649E-8F, 1.47209239F, 4.65956163F, 1.96948008E-7F, -2.7586937F,
    -4.09161377F, 1.38096823E-8F, -5.44612503F, 3.99430084F, 2.24636983E-6F,
    0.704895258F, -7.74272442F, -6.24307503E-8F, 2.70032479E-6F, -2.24461564E-6F,
    4.57470369F, -3.03677153E-11F, 3.54182525E-12F, 3.71273112F, 2.80484767E-11F,
    -6.19892419E-12F, -5.46465302F, 1.32407582F, 0.935338318F, 1.38573935E-11F,
    -0.935338318F, 1.32407582F, -1.55039332E-11F },

  // Variable: D_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 1.34248507F, -6.98549596E-15F, 1.17809855E-13F, -1.18700622E-14F,
    1.34248507F, 2.76535695E-12F, 1.19668424E-12F, 4.18118058E-12F, 17.0482349F
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
