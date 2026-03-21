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
// C/C++ source code generated on : Sat Mar 21 20:30:24 2026
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

  { 0.97158134F, 0.0341927819F, -0.0122806495F, -0.000768388971F,
    -0.00328877312F, -0.0311881378F, 7.56185254E-5F, 3.48898334E-6F,
    -0.0205607135F, -0.000823525072F, 3.65071946E-6F, -0.00485412F, 0.956717968F,
    -0.00738648186F, 0.0103069544F, -0.00541326497F, 0.00335835F, 3.74645E-5F,
    7.11641042E-5F, 0.00295213051F, -0.0239297841F, 7.4463E-5F, -0.00501916325F,
    0.0302321129F, 0.96333766F, 0.0379677936F, -0.0179259721F, 0.016452577F,
    -0.000303433131F, 0.00137368229F, 0.0106024584F, 0.00351302023F,
    0.001437361F, -0.00180748012F, 0.00426909607F, -0.00622438593F, 0.950258315F,
    -0.00152484595F, -0.00336959236F, 2.56363965E-5F, 0.000151125918F,
    -0.00698111393F, -0.0134259304F, 0.000158131545F, 0.0118440213F,
    0.00736761279F, 0.0159256309F, 0.000666677486F, 0.94905144F, -0.00300118281F,
    -0.0001308754F, 7.66429366E-5F, 0.0028643955F, 0.0434486195F, 8.01958086E-5F,
    0.0309125204F, 0.00382969179F, -0.0177214779F, -0.00493112393F,
    0.00433777086F, 0.944529F, 0.000133103516F, -1.93905598E-5F, 0.0455248356F,
    -0.0044309604F, -2.02894335E-5F, 3.79544472E-5F, -0.000241832415F,
    -0.000270458928F, -0.000304638F, 0.000127244188F, -0.000116564523F,
    0.926815F, 0.185716972F, -6.9915608E-5F, -2.42675796E-5F, 0.194326118F,
    7.34559251E-7F, 1.49826592E-5F, 0.000289210613F, 3.18175589E-5F,
    1.6136155E-5F, -4.08242522E-6F, 0.0391002484F, 0.73473537F, 1.79719846E-13F,
    8.64788872E-13F, -0.254974276F, 0.0255090203F, 0.0415130146F, -0.0206878167F,
    -0.0387092791F, 0.0121061904F, -0.00933884364F, 0.00016216228F,
    1.01229544E-13F, 0.945566297F, -3.20378947E-15F, 1.18701381E-13F,
    -0.00225513661F, 0.0426530167F, 0.00577725F, 0.0474248752F, 0.0206555724F,
    0.000842787384F, -0.000106061874F, 7.77763054E-13F, -4.95189818E-15F,
    0.945566297F, 7.60396249E-13F, 1.78987705E-6F, 3.65077649E-5F,
    0.000704710255F, 7.75288354E-5F, 3.93184528E-5F, -9.94751554E-6F,
    0.0952743217F, -0.182466388F, 1.49605263E-13F, 5.51020546E-13F, 0.689541F },

  // Variable: B_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { -0.12035986F, 0.271201074F, -0.365303397F, 0.185918868F, -0.665946543F,
    0.00557812909F, 0.00272447919F, -6.18960352E-12F, -0.0167888813F,
    -0.185078517F, -2.04222793E-12F, 0.0282684583F, -0.043359749F,
    -0.00998653937F, 0.0514989942F, -0.00988974329F, -0.83309269F,
    -3.48574758E-5F, -2.2937327E-12F, -0.185078517F, 0.0167888813F,
    -2.80244447E-12F, 2.40024528E-5F, 0.000489573285F, 0.00945024379F,
    0.00103967043F, 0.0005272649F, -0.000133397305F, 1.27763939F, -4.64673376F,
    3.66183733E-12F, 1.38850086E-11F, -4.85201883F },

  // Variable: C_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { -1.81123877F, -0.93175137F, -6.50857764E-5F, 2.82244897F, 2.57525754F,
    -0.00132754166F, -3.48163199F, -0.00498874625F, -0.025625566F, 3.00107098F,
    -2.90640545F, -0.00281920144F, -0.413025588F, 0.374499828F, -0.00142974732F,
    0.0237955786F, -4.05697823F, 0.000361724145F, 0.0224357285F, 0.000854533F,
    -3.46448565F, -1.89818959E-11F, -8.29782206E-13F, -3.04912639F,
    -0.503011346F, -5.54513359F, 1.35484809E-12F, -5.54513359F, 0.503011346F,
    9.05394596E-12F, 5.80838139E-14F, -2.68738319E-13F, 0.0854850858F },

  // Variable: D_KR
  //  Referenced by: '<S1>/Discrete State-Space'

  { 4.1349411F, 2.40726899E-13F, 2.53191608E-12F, 4.0301997E-14F, 4.1349411F,
    1.00261813E-12F, 1.06865463E-11F, 4.68050642E-12F, 19.6398F },

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
