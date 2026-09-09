//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: octocopter_model_Hinf_RLS_combined_data.cpp
//
// Code generated for Simulink model 'octocopter_model_Hinf_RLS_combined'.
//
// Model version                  : 16.138
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Sun Sep  6 20:16:24 2026
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
  //    '<S1>/Constant2'
  //    '<S1>/Constant3'
  //    '<S21>/Constant'
  //    '<S21>/Constant1'
  //    '<S21>/Constant4'
  //    '<S21>/Constant8'

  0.015,

  // Variable: Iyy_m
  //  Referenced by:
  //    '<S1>/Constant10'
  //    '<S1>/Constant8'
  //    '<S21>/Constant1'
  //    '<S21>/Constant3'
  //    '<S21>/Constant4'
  //    '<S21>/Constant8'

  0.015,

  // Variable: Izz_m
  //  Referenced by:
  //    '<S1>/Constant11'
  //    '<S1>/Constant9'
  //    '<S21>/Constant1'
  //    '<S21>/Constant4'
  //    '<S21>/Constant6'
  //    '<S21>/Constant8'

  0.031,

  // Variable: Ts
  //  Referenced by:
  //    '<S1>/Constant'
  //    '<S1>/Constant4'
  //    '<S1>/Constant6'

  0.0025,

  // Variable: epsilon_pitch
  //  Referenced by: '<S1>/Constant13'

  1000.0,

  // Variable: epsilon_roll
  //  Referenced by: '<S1>/Constant12'

  1000.0,

  // Variable: epsilon_yaw
  //  Referenced by: '<S1>/Constant14'

  2000.0,

  // Variable: twait_RLS
  //  Referenced by:
  //    '<S21>/Step1'
  //    '<S21>/Step2'
  //    '<S21>/Step4'

  10,

  // Variable: A_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 0.965644121F, -0.00348783052F, 0.0112046413F, 0.00527469488F, 0.00921288505F,
    -0.00587939145F, 0.00486301119F, 0.0131211486F, -0.095611982F,
    0.000958543329F, 0.00402173633F, 0.00799916F, 0.993643463F, 0.00317857577F,
    0.0144287115F, -0.0227541681F, 0.0243255924F, -0.000684822036F,
    -8.18573753E-5F, -1.43889241E-12F, -0.00371568697F, -2.50899338E-5F,
    0.012144695F, -0.00114733F, 0.98061794F, -0.0068539842F, -0.000137382F,
    -0.0211741738F, -0.0116369221F, -0.00293466239F, 0.0715416893F,
    0.000296623097F, -0.000899497303F, -0.00794343464F, -0.00679098163F,
    0.012404128F, 0.980882287F, 0.0262792129F, 0.00405316F, 0.0138993654F,
    -0.00522559742F, -0.117939569F, 0.00183276669F, -0.00160168705F,
    -0.000807845092F, 0.0115269711F, 0.00150380726F, 0.00350740948F,
    0.981278539F, -0.00392935798F, -0.0117586851F, 0.00583176408F, 0.0665162504F,
    -0.00313865254F, 0.00178748195F, 0.00135680207F, -0.0119644329F,
    -0.014235287F, -0.00675763749F, -0.0102238F, 0.969199777F, -0.0154794091F,
    0.00482969079F, 0.152249038F, 0.00326564582F, 0.0014803384F, -0.00605641445F,
    -3.51507697E-5F, 0.00667528622F, 0.00263583288F, -0.00907586329F,
    0.00989788398F, 0.995162547F, 0.00383569906F, -0.0717047229F, 2.5618885E-5F,
    0.00117567217F, -0.0286611412F, 0.000178804912F, 0.00641032076F,
    0.0114145176F, -0.0127385966F, -0.0105497204F, -0.00837849826F, 0.993501782F,
    -1.52193568E-12F, -5.32782504E-14F, 0.0107003432F, -0.0425282344F,
    -1.04367177E-12F, 0.0376553F, 0.00248040212F, 0.0482525F, 0.0537595041F,
    0.0366158821F, -1.41900489E-12F, 0.413735807F, -3.82212E-12F, -9.1805E-13F,
    -0.00179392216F, 0.00105919351F, -0.00280409632F, -0.00244590081F,
    -0.00131558848F, 8.42423542E-5F, 0.00257579936F, 1.77072153E-14F,
    -4.03236385E-12F, 0.976973057F, -1.01613996E-13F, -0.00826785807F,
    5.15797146E-5F, 0.00184918032F, 0.0032927373F, -0.00367469317F,
    -0.00304326974F, -0.00241693878F, -0.00640979595F, -7.64227223E-13F,
    -9.95703221E-14F, 1.00365674F },

  // Variable: B_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 0.067661576F, -0.0486161821F, 0.0242734533F, 0.00679714186F, 0.0473385677F,
    0.00669648079F, -0.0190507546F, 0.20989728F, -7.50674696E-13F,
    -0.0184597075F, 0.255448163F, 0.0709183663F, -0.200393721F, 0.147631526F,
    0.111755453F, 0.103154659F, -0.0494416915F, -0.140370354F, -0.0505913384F,
    1.28608604E-12F, -0.0765870735F, -0.0615704209F, -0.260144681F,
    -3.49762211E-12F, 0.262910903F, -0.108950302F, 0.250110507F, 0.353084117F,
    0.117774852F, -5.03266656E-12F, -1.88512111F, -1.27600144E-11F,
    -2.55413095E-12F },

  // Variable: C_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 2.94625688F, 0.681910157F, -0.524217F, -0.876945198F, -3.56633425F,
    -4.30126811E-12F, -0.233877271F, 1.61108744F, -0.244267374F, -0.549920559F,
    2.31503654F, 0.590175211F, 0.942552507F, -1.21925676F, 0.833205342F,
    1.34783542F, 1.34366608F, 0.643019438F, 0.478764117F, -1.38766026F,
    0.333932072F, 3.69545674F, -0.89071238F, -6.12882531E-12F, -9.46615182E-12F,
    8.44947376E-12F, -1.97817075F, 0.060756091F, 0.252069592F, -1.39067429E-11F,
    1.12277555F, -0.270621508F, -2.39379393E-12F },

  // Variable: D_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 1.14266706F, 0.0494284555F, -7.00352184E-14F, 0.0494284555F, 1.33582604F,
    -9.76058644E-13F, -2.40737812E-12F, -1.131455E-11F, 11.0323849F },

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

  // Expression: 0.0
  //  Referenced by: '<S1>/Delay9'

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

  // Expression: 0.0
  //  Referenced by: '<S1>/Delay10'

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

  // Expression: 0.0
  //  Referenced by: '<S1>/Delay11'

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

  // Computed Parameter: Delay9_InitialCondition_f
  //  Referenced by: '<S21>/Delay9'

  0.0F,

  // Computed Parameter: Delay8_InitialCondition
  //  Referenced by: '<S21>/Delay8'

  0.854700863F,

  // Computed Parameter: Delay_InitialCondition
  //  Referenced by: '<S1>/Delay'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition_f
  //  Referenced by: '<S1>/Delay1'

  0.0F,

  // Computed Parameter: Delay2_InitialCondition_l
  //  Referenced by: '<S1>/Delay2'

  0.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S21>/Gain1'

  0.0F,

  // Computed Parameter: Delay3_InitialCondition_a
  //  Referenced by: '<S1>/Delay3'

  0.0F,

  // Computed Parameter: Delay4_InitialCondition_o
  //  Referenced by: '<S1>/Delay4'

  0.0F,

  // Computed Parameter: Delay5_InitialCondition_l
  //  Referenced by: '<S1>/Delay5'

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
