//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: octocopter_model_Hinf_RLS_combined_data.cpp
//
// Code generated for Simulink model 'octocopter_model_Hinf_RLS_combined'.
//
// Model version                  : 16.134
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Apr 16 17:30:47 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "octocopter_model_Hinf_RLS_combined.h"

// model 10

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

  5000000.0,

  // Variable: A_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 0.975575089F, 0.00203631795F, 0.00117078878F, -0.0044266195F, 0.00653618434F,
    0.0117644882F, -0.00122131826F, 0.00526458723F, 0.00708164042F, 0.181962326F,
    -0.000697099138F, 0.00311769382F, 0.972550809F, 0.000298694591F,
    0.00532437349F, -0.00655026641F, 0.0128505286F, 0.0142000057F,
    -0.0169203114F, -0.0227602962F, -0.12189649F, -0.00168895698F, 0.0039747972F,
    -0.00348177459F, 0.984633565F, -0.00660969969F, 0.00554300798F, 0.0132202F,
    0.0139541F, 0.00466704974F, 0.00627786526F, 0.0495261736F, -0.00195377506F,
    0.00185435778F, -0.0114676226F, -0.000583171728F, 0.970349371F,
    0.00360521371F, 0.0274456888F, 0.0294767618F, 0.00164176896F, 0.00220841961F,
    2.96766436E-13F, -0.00337475538F, -0.00517631136F, -0.00558650075F,
    0.00605546916F, -0.002718F, 0.990800858F, 0.000356093748F, -0.00631560851F,
    -0.00874511432F, -0.0117634591F, 0.200378045F, 0.000149074491F,
    0.00222850568F, 0.00604780763F, 0.00791014358F, -0.0246443748F,
    -0.00736690825F, 0.970657766F, -0.00368721457F, 0.00542995101F,
    0.0073040789F, -0.154716447F, 0.000516446191F, 0.00399317313F,
    0.00519509148F, 0.00439942861F, -0.0241071638F, -0.00219788798F,
    -0.00575787714F, 0.963280857F, -0.0106910402F, -0.0143810147F, 0.0616583973F,
    0.00109899568F, -0.00217660191F, 0.00699556898F, -0.00192955486F,
    -0.000678776414F, 0.00361559843F, -0.0022449703F, 0.00442012632F,
    0.993211865F, 0.0014399389F, 7.25937431E-13F, 4.65943719E-15F,
    -0.0088442862F, 0.028425416F, -0.00784044899F, -0.00275810342F,
    0.0146914274F, -0.00912209135F, 0.0179605018F, -0.000410053646F, 0.94738394F,
    -1.38102678E-13F, 1.30944888E-16F, 0.0163547508F, 0.0176533926F,
    -0.0208672117F, 8.53075545E-14F, -0.0286806617F, 0.0100548F,
    -0.000427972613F, 9.61244756E-13F, -1.60077138E-13F, 0.0383108184F,
    -1.26677721E-13F, 0.000272895384F, 0.000375308417F, 0.000663736602F,
    -0.000138817748F, -4.19793687E-5F, 0.000151524349F, -7.98784895E-5F,
    -4.00988023E-15F, 2.09030476E-17F, -1.21209813E-12F, 0.975281656F },

  // Variable: B_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 0.162990808F, -0.465956926F, 0.163969755F, 0.238495782F, -0.251268774F,
    0.163467914F, -0.307136923F, -0.154983819F, -0.373569787F, -8.62194647E-13F,
    0.00766151492F, -0.00208048755F, -0.229542673F, -0.0813253298F,
    -0.766409457F, -0.0760251209F, 0.0167977F, -0.0931178629F, -0.0379822701F,
    -0.0915516689F, -9.91205E-13F, -0.0312622413F, -0.267968833F, 0.0414820574F,
    0.0310944598F, -1.34868397E-12F, 0.0706276372F, 0.185392946F, -0.147645816F,
    -1.10054257E-11F, 1.73865122E-12F, 11.1902008F, 1.48205417E-12F },

  // Variable: C_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 1.08804154F, -1.00034547F, 3.99987411F, -1.38718939F, -5.39362669F,
    -1.17758799F, 1.69164836F, -3.85368633F, -0.0967430472F, 2.14073443F,
    -7.66254854F, 1.79085848E-12F, -1.49158323F, 0.373157114F, 0.839562893F,
    -0.204937935F, 4.38359213F, -2.72326183F, -2.97905397F, 5.17140722F,
    1.72126234F, -0.610167921F, -0.149535358F, 8.72140467E-13F, -11.4842091F,
    -2.81446338F, -8.1064246E-13F, 9.93582061E-13F, -3.04395073E-13F,
    0.320242137F, -0.00877423771F, 0.0358026214F, 4.12196427E-13F },

  // Variable: D_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 7.79585934F, -0.000292791898F, -1.45183648E-12F, -0.000292791898F,
    7.79698229F, -5.82251651E-12F, -4.92552743E-12F, -3.02748104E-11F, 78.08741F
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
