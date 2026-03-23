//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: octocopter_model_Hinf_RLS_combined.cpp
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
#include "rtwtypes.h"
#include <cmath>

//
// Output and update for atomic system:
//    '<S1>/MATLAB Function'
//    '<S1>/MATLAB Function1'
//    '<S1>/MATLAB Function2'
//
void octocopter_model_Hinf_RLS_combined::octocopter_model_MATLABFunction
  (real32_T rtu_x, real_T rtu_Ts, real_T rtu_fc, real_T rtu_reset, real32_T
   *rty_xdot, DW_MATLABFunction_octocopter__T *localDW)
{
  real32_T Ts;
  real32_T alpha;
  if ((!localDW->x_prev_not_empty) || (rtu_reset > 0.0)) {
    localDW->x_prev = rtu_x;
    localDW->x_prev_not_empty = true;
    localDW->xdot_prev = 0.0F;
  }

  Ts = std::fmax(static_cast<real32_T>(rtu_Ts), 1.0E-9F);
  alpha = std::exp(-6.28318548F * std::fmax(static_cast<real32_T>(rtu_fc),
    1.0E-6F) * Ts);
  *rty_xdot = (rtu_x - localDW->x_prev) / Ts * (1.0F - alpha) + alpha *
    localDW->xdot_prev;
  localDW->x_prev = rtu_x;
  localDW->xdot_prev = *rty_xdot;
}

// Model step function
void octocopter_model_Hinf_RLS_combined::step(real32_T *arg_tau_y, real32_T
  *arg_tau_x, real32_T *arg_tau_z, real32_T *arg_r, real32_T *arg_psi_des,
  real32_T *arg_theta, real32_T *arg_q, real32_T *arg_theta_des, real32_T *arg_p,
  real32_T *arg_phi, real32_T *arg_psi, real32_T *arg_phi_des, real32_T
  *arg_inverse_Ix_hat, real32_T *arg_inverse_Iy_hat, real32_T
  *arg_inverse_Iz_hat)
{
  real_T rtb_Subtract2;
  real_T rtb_Subtract2_tmp;
  real_T rtb_Switch3;
  real_T rtb_Switch4;
  real_T tmp;
  int_T i;
  int_T j;
  real32_T xnew[11];
  real32_T b_I_0[9];
  real32_T b_I_1[9];
  real32_T K_phi[3];
  real32_T K_psi[3];
  real32_T rtb_DiscreteStateSpace[3];
  real32_T Ix;
  real32_T Iz;
  real32_T K_phi_0;
  real32_T rtb_DigitalFilter;
  real32_T rtb_DigitalFilter_d;
  real32_T rtb_DigitalFilter_lt;
  real32_T rtb_DigitalFilter_p;
  real32_T rtb_DiscreteStateSpace_0;
  int8_T b_I[9];
  static const int8_T c[9]{ 20, 0, 0, 0, 20, 0, 0, 0, 20 };

  static const int8_T c_0[9]{ 10, 0, 0, 0, 10, 0, 0, 0, 10 };

  static const int8_T c_1[9]{ 90, 0, 0, 0, 90, 0, 0, 0, 90 };

  // S-Function (sdspbiquad): '<S2>/Digital Filter' incorporates:
  //   Inport: '<Root>/phi'
  //   Inport: '<Root>/phi_des'
  //   Sum: '<S1>/Add1'

  Ix = ((*arg_phi_des - *arg_phi) * 0.00554271741F - -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[1];

  // S-Function (sdspbiquad): '<S2>/Digital Filter'
  *arg_inverse_Ix_hat = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[1];

  // S-Function (sdspbiquad): '<S2>/Digital Filter'
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES[0] = Ix;

  // S-Function (sdspbiquad): '<S3>/Digital Filter' incorporates:
  //   Inport: '<Root>/theta'
  //   Inport: '<Root>/theta_des'
  //   Sum: '<S1>/Add2'

  Ix = ((*arg_theta_des - *arg_theta) * 0.00554271741F - -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[1];

  // S-Function (sdspbiquad): '<S3>/Digital Filter'
  *arg_inverse_Iy_hat = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[1];

  // S-Function (sdspbiquad): '<S3>/Digital Filter'
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_f[0] = Ix;

  // S-Function (sdspbiquad): '<S4>/Digital Filter' incorporates:
  //   Inport: '<Root>/psi'
  //   Inport: '<Root>/psi_des'
  //   Sum: '<S1>/Add3'

  Ix = ((*arg_psi_des - *arg_psi) * 0.00554271741F - -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[1];

  // S-Function (sdspbiquad): '<S4>/Digital Filter'
  *arg_inverse_Iz_hat = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[1];

  // S-Function (sdspbiquad): '<S4>/Digital Filter'
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_m[0] = Ix;

  // DiscreteStateSpace: '<S1>/Discrete State-Space' incorporates:
  //   SignalConversion generated from: '<S1>/Discrete State-Space'

  for (i = 0; i < 3; i++) {
    Ix = 0.0F;
    for (j = 0; j < 11; j++) {
      Ix += octocopter_model_Hinf_RLS_com_P.C_KR[3 * j + i] *
        octocopter_model_Hinf_RLS_co_DW.DiscreteStateSpace_DSTATE[j];
    }

    rtb_DiscreteStateSpace[i] = ((octocopter_model_Hinf_RLS_com_P.D_KR[i] *
      *arg_inverse_Ix_hat + Ix) + octocopter_model_Hinf_RLS_com_P.D_KR[i + 3] * *
      arg_inverse_Iy_hat) + octocopter_model_Hinf_RLS_com_P.D_KR[i + 6] *
      *arg_inverse_Iz_hat;
  }

  // End of DiscreteStateSpace: '<S1>/Discrete State-Space'

  // Step: '<S21>/Step4' incorporates:
  //   Step: '<S1>/Step'
  //   Step: '<S1>/Step1'
  //   Step: '<S1>/Step2'
  //   Step: '<S21>/Step1'
  //   Step: '<S21>/Step2'

  rtb_Subtract2_tmp = (((&octocopter_model_Hinf_RLS_co_M)->Timing.clockTick0) *
                       0.0025);
  if (rtb_Subtract2_tmp < octocopter_model_Hinf_RLS_com_P.twait_RLS) {
    tmp = octocopter_model_Hinf_RLS_com_P.Step4_Y0;
  } else {
    tmp = octocopter_model_Hinf_RLS_com_P.Step4_YFinal;
  }

  // Sum: '<S21>/Subtract1' incorporates:
  //   Constant: '<S21>/Constant10'
  //   Step: '<S21>/Step4'

  rtb_Subtract2 = octocopter_model_Hinf_RLS_com_P.Constant10_Value - tmp;

  // S-Function (sdspbiquad): '<S6>/Digital Filter' incorporates:
  //   Inport: '<Root>/q'

  Ix = (0.00554271741F * *arg_q - -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e[1];
  rtb_DigitalFilter = (2.0F *
                       octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e
                       [0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e[1];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_e[0] = Ix;

  // S-Function (sdspbiquad): '<S7>/Digital Filter' incorporates:
  //   Inport: '<Root>/r'

  Ix = (0.00554271741F * *arg_r - -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm
    [1];
  rtb_DigitalFilter_d = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm[1];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_mm[0] = Ix;

  // Switch: '<S21>/Switch' incorporates:
  //   Constant: '<S21>/Constant'
  //   Delay: '<S21>/Delay1'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch_Threshold) {
    tmp = 1.0 / octocopter_model_Hinf_RLS_com_P.Ixx_m;
  } else {
    tmp = octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE;
  }

  // Switch: '<S21>/Switch1' incorporates:
  //   Constant: '<S21>/Constant1'
  //   Delay: '<S21>/Delay2'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch1_Threshold) {
    rtb_Switch3 = (-octocopter_model_Hinf_RLS_com_P.Izz_m +
                   octocopter_model_Hinf_RLS_com_P.Iyy_m) /
      octocopter_model_Hinf_RLS_com_P.Ixx_m;
  } else {
    rtb_Switch3 = octocopter_model_Hinf_RLS_co_DW.Delay2_DSTATE;
  }

  // Switch: '<S21>/Switch2' incorporates:
  //   Constant: '<S21>/Constant2'
  //   Delay: '<S21>/Delay4'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch2_Threshold) {
    rtb_Subtract2 = octocopter_model_Hinf_RLS_com_P.Constant2_Value;
  } else {
    rtb_Subtract2 = octocopter_model_Hinf_RLS_co_DW.Delay4_DSTATE;
  }

  // MATLAB Function: '<S21>/MATLAB Function' incorporates:
  //   Switch: '<S21>/Switch'
  //   Switch: '<S21>/Switch1'
  //   Switch: '<S21>/Switch2'

  *arg_tau_x = ((static_cast<real32_T>(-rtb_Switch3) * rtb_DigitalFilter *
                 rtb_DigitalFilter_d + rtb_DiscreteStateSpace[0]) + static_cast<
                real32_T>(rtb_Subtract2)) * static_cast<real32_T>(1.0 / tmp);

  // S-Function (sdspbiquad): '<S5>/Digital Filter' incorporates:
  //   Inport: '<Root>/p'

  Ix = (0.00554271741F * *arg_p - -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[1];
  rtb_DigitalFilter_lt = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[1];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_l[0] = Ix;

  // Step: '<S21>/Step1'
  if (rtb_Subtract2_tmp < octocopter_model_Hinf_RLS_com_P.twait_RLS) {
    tmp = octocopter_model_Hinf_RLS_com_P.Step1_Y0;
  } else {
    tmp = octocopter_model_Hinf_RLS_com_P.Step1_YFinal;
  }

  // Sum: '<S21>/Subtract' incorporates:
  //   Constant: '<S21>/Constant9'
  //   Step: '<S21>/Step1'

  rtb_Subtract2 = octocopter_model_Hinf_RLS_com_P.Constant9_Value - tmp;

  // Switch: '<S21>/Switch3' incorporates:
  //   Constant: '<S21>/Constant3'
  //   Delay: '<S21>/Delay3'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch3_Threshold) {
    rtb_Switch3 = 1.0 / octocopter_model_Hinf_RLS_com_P.Iyy_m;
  } else {
    rtb_Switch3 = octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE;
  }

  // End of Switch: '<S21>/Switch3'

  // Switch: '<S21>/Switch4' incorporates:
  //   Constant: '<S21>/Constant4'
  //   Delay: '<S21>/Delay5'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch4_Threshold) {
    rtb_Switch4 = (octocopter_model_Hinf_RLS_com_P.Izz_m -
                   octocopter_model_Hinf_RLS_com_P.Ixx_m) /
      octocopter_model_Hinf_RLS_com_P.Iyy_m;
  } else {
    rtb_Switch4 = octocopter_model_Hinf_RLS_co_DW.Delay5_DSTATE;
  }

  // End of Switch: '<S21>/Switch4'

  // Step: '<S21>/Step2'
  if (rtb_Subtract2_tmp < octocopter_model_Hinf_RLS_com_P.twait_RLS) {
    tmp = octocopter_model_Hinf_RLS_com_P.Step2_Y0;
  } else {
    tmp = octocopter_model_Hinf_RLS_com_P.Step2_YFinal;
  }

  // Sum: '<S21>/Subtract2' incorporates:
  //   Constant: '<S21>/Constant11'
  //   Step: '<S21>/Step2'

  rtb_Subtract2 = octocopter_model_Hinf_RLS_com_P.Constant11_Value - tmp;

  // Switch: '<S21>/Switch5' incorporates:
  //   Constant: '<S21>/Constant5'
  //   Delay: '<S21>/Delay6'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch5_Threshold) {
    tmp = octocopter_model_Hinf_RLS_com_P.Constant5_Value;
  } else {
    tmp = octocopter_model_Hinf_RLS_co_DW.Delay6_DSTATE;
  }

  // MATLAB Function: '<S21>/MATLAB Function1' incorporates:
  //   Switch: '<S21>/Switch5'

  *arg_tau_y = ((static_cast<real32_T>(-rtb_Switch4) * rtb_DigitalFilter_lt *
                 rtb_DigitalFilter_d + rtb_DiscreteStateSpace[1]) - static_cast<
                real32_T>(tmp)) * static_cast<real32_T>(1.0 / rtb_Switch3);

  // Switch: '<S21>/Switch6' incorporates:
  //   Constant: '<S21>/Constant6'
  //   Delay: '<S21>/Delay8'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch6_Threshold) {
    tmp = 1.0 / octocopter_model_Hinf_RLS_com_P.Izz_m;
  } else {
    tmp = octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE;
  }

  // Switch: '<S21>/Switch8' incorporates:
  //   Constant: '<S21>/Constant8'
  //   Delay: '<S21>/Delay7'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch8_Threshold) {
    rtb_Switch3 = (octocopter_model_Hinf_RLS_com_P.Ixx_m -
                   octocopter_model_Hinf_RLS_com_P.Iyy_m) /
      octocopter_model_Hinf_RLS_com_P.Izz_m;
  } else {
    rtb_Switch3 = octocopter_model_Hinf_RLS_co_DW.Delay7_DSTATE;
  }

  // Switch: '<S21>/Switch7' incorporates:
  //   Constant: '<S21>/Constant7'
  //   Delay: '<S21>/Delay9'

  if (rtb_Subtract2 > octocopter_model_Hinf_RLS_com_P.Switch7_Threshold) {
    rtb_Subtract2 = octocopter_model_Hinf_RLS_com_P.Constant7_Value;
  } else {
    rtb_Subtract2 = octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE;
  }

  // MATLAB Function: '<S21>/MATLAB Function2' incorporates:
  //   Switch: '<S21>/Switch6'
  //   Switch: '<S21>/Switch7'
  //   Switch: '<S21>/Switch8'

  *arg_tau_z = ((static_cast<real32_T>(-rtb_Switch3) * rtb_DigitalFilter *
                 rtb_DigitalFilter_lt + rtb_DiscreteStateSpace[2]) -
                static_cast<real32_T>(rtb_Subtract2)) * static_cast<real32_T>
    (1.0 / tmp);

  // S-Function (sdspbiquad): '<S8>/Digital Filter' incorporates:
  //   Delay: '<S1>/Delay9'

  Ix = (0.00554271741F * octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a -
        -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[1];
  rtb_DigitalFilter_p = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[1];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_a[0] = Ix;

  // Step: '<S1>/Step'
  if (rtb_Subtract2_tmp < octocopter_model_Hinf_RLS_com_P.Step_Time) {
    tmp = octocopter_model_Hinf_RLS_com_P.Step_Y0;
  } else {
    tmp = octocopter_model_Hinf_RLS_com_P.Step_YFinal;
  }

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   Constant: '<S1>/Constant'
  //   Constant: '<S1>/Constant1'
  //   Delay: '<S1>/Delay2'
  //   Delay: '<S1>/Delay9'
  //   Step: '<S1>/Step'

  octocopter_model_MATLABFunction
    (octocopter_model_Hinf_RLS_co_DW.Delay2_DSTATE_g,
     octocopter_model_Hinf_RLS_com_P.Ts,
     octocopter_model_Hinf_RLS_com_P.Constant1_Value, tmp,
     &octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a,
     &octocopter_model_Hinf_RLS_co_DW.sf_MATLABFunction);

  // MATLAB Function: '<S1>/MATLAB Function16' incorporates:
  //   Delay: '<S1>/Delay'
  //   Delay: '<S1>/Delay1'
  //   Delay: '<S1>/Delay9'
  //   Product: '<S1>/Product7'

  if (std::abs(octocopter_model_Hinf_RLS_co_DW.prev_error_phi) > 0.5F) {
    for (i = 0; i < 9; i++) {
      octocopter_model_Hinf_RLS_co_DW.prev_P_phi[i] = c[i];
    }
  }

  rtb_DiscreteStateSpace[0] = octocopter_model_Hinf_RLS_co_DW.Delay_DSTATE *
    octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE_m;
  rtb_DiscreteStateSpace[1] = rtb_DigitalFilter_p;
  rtb_DiscreteStateSpace[2] = 1.0F;
  Ix = 0.0F;
  for (i = 0; i < 3; i++) {
    Ix += ((octocopter_model_Hinf_RLS_co_DW.prev_P_phi[3 * i + 1] *
            rtb_DigitalFilter_p + octocopter_model_Hinf_RLS_co_DW.prev_P_phi[3 *
            i] * rtb_DiscreteStateSpace[0]) +
           octocopter_model_Hinf_RLS_co_DW.prev_P_phi[3 * i + 2]) *
      rtb_DiscreteStateSpace[i];
  }

  rtb_DiscreteStateSpace_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    K_phi[i] = ((octocopter_model_Hinf_RLS_co_DW.prev_P_phi[i + 3] *
                 rtb_DigitalFilter_p +
                 octocopter_model_Hinf_RLS_co_DW.prev_P_phi[i] *
                 rtb_DiscreteStateSpace[0]) +
                octocopter_model_Hinf_RLS_co_DW.prev_P_phi[i + 6]) / (Ix +
      0.9999F);
    rtb_DiscreteStateSpace_0 += rtb_DiscreteStateSpace[i] *
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[i];
  }

  Ix = octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a -
    rtb_DiscreteStateSpace_0;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[0] += K_phi[0] * Ix;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[1] += K_phi[1] * Ix;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[2] += K_phi[2] * Ix;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }

  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  Iz = K_phi[0];
  rtb_DiscreteStateSpace_0 = K_phi[1];
  K_phi_0 = K_phi[2];
  for (i = 0; i < 3; i++) {
    Ix = rtb_DiscreteStateSpace[i];
    b_I_0[3 * i] = static_cast<real32_T>(b_I[3 * i]) - Iz * Ix;
    j = 3 * i + 1;
    b_I_0[j] = static_cast<real32_T>(b_I[j]) - rtb_DiscreteStateSpace_0 * Ix;
    j = 3 * i + 2;
    b_I_0[j] = static_cast<real32_T>(b_I[j]) - K_phi_0 * Ix;
  }

  for (i = 0; i < 9; i++) {
    b_I_1[i] = 1.0001F * b_I_0[i];
  }

  for (i = 0; i < 3; i++) {
    Ix = octocopter_model_Hinf_RLS_co_DW.prev_P_phi[3 * i + 1];
    Iz = octocopter_model_Hinf_RLS_co_DW.prev_P_phi[3 * i];
    rtb_DiscreteStateSpace_0 = octocopter_model_Hinf_RLS_co_DW.prev_P_phi[3 * i
      + 2];
    for (j = 0; j < 3; j++) {
      b_I_0[j + 3 * i] = (b_I_1[j + 3] * Ix + Iz * b_I_1[j]) + b_I_1[j + 6] *
        rtb_DiscreteStateSpace_0;
    }
  }

  for (i = 0; i < 9; i++) {
    octocopter_model_Hinf_RLS_co_DW.prev_P_phi[i] = b_I_0[i];
  }

  octocopter_model_Hinf_RLS_co_DW.prev_error_phi = std::abs
    (octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a - ((rtb_DiscreteStateSpace
       [0] * octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[0] +
       rtb_DigitalFilter_p * octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[1])
      + octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[2]));

  // MATLAB Function: '<S1>/MATLAB Function7' incorporates:
  //   Delay: '<S21>/Delay1'
  //   MATLAB Function: '<S1>/MATLAB Function16'

  if (std::abs(K_phi[1]) > 0.005F) {
    octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE =
      octocopter_model_Hinf_RLS_co_DW.y_prev;
  } else {
    octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE = 0.95F *
      octocopter_model_Hinf_RLS_co_DW.y_prev + 0.05F *
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[1];
  }

  octocopter_model_Hinf_RLS_co_DW.y_prev =
    octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE;

  // End of MATLAB Function: '<S1>/MATLAB Function7'

  // Gain: '<S21>/Gain1' incorporates:
  //   Delay: '<S21>/Delay4'
  //   MATLAB Function: '<S1>/MATLAB Function16'

  octocopter_model_Hinf_RLS_co_DW.Delay4_DSTATE =
    octocopter_model_Hinf_RLS_com_P.Gain1_Gain *
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[2];

  // Delay: '<S1>/Delay10' incorporates:
  //   Delay: '<S1>/Delay9'

  octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a =
    octocopter_model_Hinf_RLS_co_DW.Delay10_DSTATE;

  // S-Function (sdspbiquad): '<S9>/Digital Filter' incorporates:
  //   Delay: '<S1>/Delay9'

  Ix = (0.00554271741F * octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a -
        -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[1];
  rtb_DigitalFilter_p = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[1];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_b[0] = Ix;

  // Step: '<S1>/Step1'
  if (rtb_Subtract2_tmp < octocopter_model_Hinf_RLS_com_P.Step1_Time) {
    tmp = octocopter_model_Hinf_RLS_com_P.Step1_Y0_e;
  } else {
    tmp = octocopter_model_Hinf_RLS_com_P.Step1_YFinal_a;
  }

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Constant: '<S1>/Constant4'
  //   Constant: '<S1>/Constant5'
  //   Delay: '<S1>/Delay5'
  //   Delay: '<S1>/Delay9'
  //   Step: '<S1>/Step1'

  octocopter_model_MATLABFunction
    (octocopter_model_Hinf_RLS_co_DW.Delay5_DSTATE_h,
     octocopter_model_Hinf_RLS_com_P.Ts,
     octocopter_model_Hinf_RLS_com_P.Constant5_Value_m, tmp,
     &octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a,
     &octocopter_model_Hinf_RLS_co_DW.sf_MATLABFunction1);

  // MATLAB Function: '<S1>/MATLAB Function23' incorporates:
  //   Delay: '<S1>/Delay3'
  //   Delay: '<S1>/Delay4'
  //   Delay: '<S1>/Delay9'
  //   MATLAB Function: '<S1>/MATLAB Function16'
  //   Product: '<S1>/Product8'

  if (std::abs(octocopter_model_Hinf_RLS_co_DW.prev_error_theta) > 0.5F) {
    for (i = 0; i < 9; i++) {
      octocopter_model_Hinf_RLS_co_DW.prev_P_theta[i] = c_0[i];
    }
  }

  K_phi[0] = octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE_d *
    octocopter_model_Hinf_RLS_co_DW.Delay4_DSTATE_f;
  K_phi[1] = rtb_DigitalFilter_p;
  K_phi[2] = 1.0F;
  Iz = 0.0F;
  for (i = 0; i < 3; i++) {
    Iz += ((octocopter_model_Hinf_RLS_co_DW.prev_P_theta[3 * i + 1] *
            rtb_DigitalFilter_p + octocopter_model_Hinf_RLS_co_DW.prev_P_theta[3
            * i] * K_phi[0]) + octocopter_model_Hinf_RLS_co_DW.prev_P_theta[3 *
           i + 2]) * K_phi[i];
  }

  rtb_DiscreteStateSpace_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_DiscreteStateSpace[i] = ((octocopter_model_Hinf_RLS_co_DW.prev_P_theta[i
      + 3] * rtb_DigitalFilter_p +
      octocopter_model_Hinf_RLS_co_DW.prev_P_theta[i] * K_phi[0]) +
      octocopter_model_Hinf_RLS_co_DW.prev_P_theta[i + 6]) / (Iz + 0.9999F);
    rtb_DiscreteStateSpace_0 += K_phi[i] *
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[i];
  }

  Ix = octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a -
    rtb_DiscreteStateSpace_0;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[0] +=
    rtb_DiscreteStateSpace[0] * Ix;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[1] +=
    rtb_DiscreteStateSpace[1] * Ix;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[2] +=
    rtb_DiscreteStateSpace[2] * Ix;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }

  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  Ix = rtb_DiscreteStateSpace[0];
  rtb_DiscreteStateSpace_0 = rtb_DiscreteStateSpace[1];
  K_phi_0 = rtb_DiscreteStateSpace[2];
  for (i = 0; i < 3; i++) {
    Iz = K_phi[i];
    b_I_0[3 * i] = static_cast<real32_T>(b_I[3 * i]) - Ix * Iz;
    j = 3 * i + 1;
    b_I_0[j] = static_cast<real32_T>(b_I[j]) - rtb_DiscreteStateSpace_0 * Iz;
    j = 3 * i + 2;
    b_I_0[j] = static_cast<real32_T>(b_I[j]) - K_phi_0 * Iz;
  }

  for (i = 0; i < 3; i++) {
    Ix = b_I_0[i + 3];
    Iz = b_I_0[i];
    rtb_DiscreteStateSpace_0 = b_I_0[i + 6];
    for (j = 0; j < 3; j++) {
      b_I_1[i + 3 * j] = ((octocopter_model_Hinf_RLS_co_DW.prev_P_theta[3 * j +
                           1] * Ix +
                           octocopter_model_Hinf_RLS_co_DW.prev_P_theta[3 * j] *
                           Iz) + octocopter_model_Hinf_RLS_co_DW.prev_P_theta[3 *
                          j + 2] * rtb_DiscreteStateSpace_0) / 0.9999F;
    }
  }

  for (i = 0; i < 9; i++) {
    octocopter_model_Hinf_RLS_co_DW.prev_P_theta[i] = b_I_1[i];
  }

  octocopter_model_Hinf_RLS_co_DW.prev_error_theta = std::abs
    (octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a - ((K_phi[0] *
       octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[0] +
       rtb_DigitalFilter_p *
       octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[1]) +
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[2]));

  // Delay: '<S1>/Delay11' incorporates:
  //   Delay: '<S1>/Delay9'

  octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a =
    octocopter_model_Hinf_RLS_co_DW.Delay11_DSTATE;

  // S-Function (sdspbiquad): '<S10>/Digital Filter' incorporates:
  //   Delay: '<S1>/Delay9'

  Ix = (0.00554271741F * octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a -
        -1.77863181F *
        octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf[0]) -
    0.800802648F * octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf
    [1];
  rtb_DigitalFilter_p = (2.0F *
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf[0] + Ix) +
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf[1];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf[1] =
    octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf[0];
  octocopter_model_Hinf_RLS_co_DW.DigitalFilter_FILT_STATES_lf[0] = Ix;

  // Step: '<S1>/Step2'
  if (rtb_Subtract2_tmp < octocopter_model_Hinf_RLS_com_P.Step2_Time) {
    tmp = octocopter_model_Hinf_RLS_com_P.Step2_Y0_o;
  } else {
    tmp = octocopter_model_Hinf_RLS_com_P.Step2_YFinal_c;
  }

  // MATLAB Function: '<S1>/MATLAB Function2' incorporates:
  //   Constant: '<S1>/Constant6'
  //   Constant: '<S1>/Constant7'
  //   Delay: '<S1>/Delay8'
  //   Delay: '<S1>/Delay9'
  //   Step: '<S1>/Step2'

  octocopter_model_MATLABFunction
    (octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE_i,
     octocopter_model_Hinf_RLS_com_P.Ts,
     octocopter_model_Hinf_RLS_com_P.Constant7_Value_f, tmp,
     &octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a,
     &octocopter_model_Hinf_RLS_co_DW.sf_MATLABFunction2);

  // MATLAB Function: '<S1>/MATLAB Function3' incorporates:
  //   Delay: '<S1>/Delay6'
  //   Delay: '<S1>/Delay7'
  //   Delay: '<S1>/Delay9'
  //   MATLAB Function: '<S1>/MATLAB Function16'
  //   Product: '<S1>/Product9'

  if (std::abs(octocopter_model_Hinf_RLS_co_DW.prev_error_psi) > 1.0F) {
    for (i = 0; i < 9; i++) {
      octocopter_model_Hinf_RLS_co_DW.prev_P_psi[i] = c_1[i];
    }
  }

  K_phi[0] = octocopter_model_Hinf_RLS_co_DW.Delay6_DSTATE_h *
    octocopter_model_Hinf_RLS_co_DW.Delay7_DSTATE_o;
  K_phi[1] = rtb_DigitalFilter_p;
  K_phi[2] = 1.0F;
  Iz = 0.0F;
  for (i = 0; i < 3; i++) {
    Iz += ((octocopter_model_Hinf_RLS_co_DW.prev_P_psi[3 * i + 1] *
            rtb_DigitalFilter_p + octocopter_model_Hinf_RLS_co_DW.prev_P_psi[3 *
            i] * K_phi[0]) + octocopter_model_Hinf_RLS_co_DW.prev_P_psi[3 * i +
           2]) * K_phi[i];
  }

  rtb_DiscreteStateSpace_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    K_psi[i] = ((octocopter_model_Hinf_RLS_co_DW.prev_P_psi[i + 3] *
                 rtb_DigitalFilter_p +
                 octocopter_model_Hinf_RLS_co_DW.prev_P_psi[i] * K_phi[0]) +
                octocopter_model_Hinf_RLS_co_DW.prev_P_psi[i + 6]) / (Iz +
      0.9999F);
    rtb_DiscreteStateSpace_0 += K_phi[i] *
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[i];
  }

  Ix = octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a -
    rtb_DiscreteStateSpace_0;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[0] += K_psi[0] * Ix;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[1] += K_psi[1] * Ix;
  octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[2] += K_psi[2] * Ix;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }

  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  Ix = K_psi[0];
  rtb_DiscreteStateSpace_0 = K_psi[1];
  K_phi_0 = K_psi[2];
  for (i = 0; i < 3; i++) {
    Iz = K_phi[i];
    b_I_0[3 * i] = static_cast<real32_T>(b_I[3 * i]) - Ix * Iz;
    j = 3 * i + 1;
    b_I_0[j] = static_cast<real32_T>(b_I[j]) - rtb_DiscreteStateSpace_0 * Iz;
    j = 3 * i + 2;
    b_I_0[j] = static_cast<real32_T>(b_I[j]) - K_phi_0 * Iz;
  }

  for (i = 0; i < 3; i++) {
    Ix = b_I_0[i + 3];
    Iz = b_I_0[i];
    rtb_DiscreteStateSpace_0 = b_I_0[i + 6];
    for (j = 0; j < 3; j++) {
      b_I_1[i + 3 * j] = ((octocopter_model_Hinf_RLS_co_DW.prev_P_psi[3 * j + 1]
                           * Ix + octocopter_model_Hinf_RLS_co_DW.prev_P_psi[3 *
                           j] * Iz) +
                          octocopter_model_Hinf_RLS_co_DW.prev_P_psi[3 * j + 2] *
                          rtb_DiscreteStateSpace_0) / 0.9999F;
    }
  }

  for (i = 0; i < 9; i++) {
    octocopter_model_Hinf_RLS_co_DW.prev_P_psi[i] = b_I_1[i];
  }

  octocopter_model_Hinf_RLS_co_DW.prev_error_psi = std::abs
    (octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a - ((K_phi[0] *
       octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[0] +
       rtb_DigitalFilter_p * octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[1])
      + octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[2]));

  // MATLAB Function: '<S1>/MATLAB Function9' incorporates:
  //   Delay: '<S21>/Delay2'
  //   Delay: '<S21>/Delay5'
  //   Delay: '<S21>/Delay7'
  //   MATLAB Function: '<S1>/MATLAB Function16'
  //   MATLAB Function: '<S1>/MATLAB Function23'
  //   MATLAB Function: '<S1>/MATLAB Function3'

  Ix = 1.0F / octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[1];
  rtb_DigitalFilter_p = 1.0F /
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[1];
  Iz = 1.0F / octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[1];
  octocopter_model_Hinf_RLS_co_DW.Delay2_DSTATE = (rtb_DigitalFilter_p - Iz) /
    Ix;
  octocopter_model_Hinf_RLS_co_DW.Delay5_DSTATE = (Iz - Ix) /
    rtb_DigitalFilter_p;
  octocopter_model_Hinf_RLS_co_DW.Delay7_DSTATE = (Ix - rtb_DigitalFilter_p) /
    Iz;

  // MATLAB Function: '<S1>/MATLAB Function14' incorporates:
  //   Delay: '<S21>/Delay8'
  //   MATLAB Function: '<S1>/MATLAB Function3'

  if (std::abs(K_psi[1]) > 0.005F) {
    octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE =
      octocopter_model_Hinf_RLS_co_DW.y_prev_g;
  } else {
    octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE = 0.95F *
      octocopter_model_Hinf_RLS_co_DW.y_prev_g + 0.05F *
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[1];
  }

  octocopter_model_Hinf_RLS_co_DW.y_prev_g =
    octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE;

  // End of MATLAB Function: '<S1>/MATLAB Function14'

  // Gain: '<S21>/Gain2' incorporates:
  //   Delay: '<S21>/Delay9'
  //   MATLAB Function: '<S1>/MATLAB Function3'

  octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE =
    octocopter_model_Hinf_RLS_com_P.Gain2_Gain *
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[2];

  // MATLAB Function: '<S1>/MATLAB Function11' incorporates:
  //   Delay: '<S21>/Delay3'
  //   MATLAB Function: '<S1>/MATLAB Function23'

  if (std::abs(rtb_DiscreteStateSpace[1]) > 0.005F) {
    octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE =
      octocopter_model_Hinf_RLS_co_DW.y_prev_f;
  } else {
    octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE = 0.95F *
      octocopter_model_Hinf_RLS_co_DW.y_prev_f + 0.05F *
      octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[1];
  }

  octocopter_model_Hinf_RLS_co_DW.y_prev_f =
    octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE;

  // End of MATLAB Function: '<S1>/MATLAB Function11'

  // Gain: '<S21>/Gain' incorporates:
  //   Delay: '<S21>/Delay6'
  //   MATLAB Function: '<S1>/MATLAB Function23'

  octocopter_model_Hinf_RLS_co_DW.Delay6_DSTATE =
    octocopter_model_Hinf_RLS_com_P.Gain_Gain *
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[2];

  // Update for DiscreteStateSpace: '<S1>/Discrete State-Space' incorporates:
  //   SignalConversion generated from: '<S1>/Discrete State-Space'

  for (i = 0; i < 11; i++) {
    Ix = 0.0F;
    for (j = 0; j < 11; j++) {
      Ix += octocopter_model_Hinf_RLS_com_P.A_KR[11 * j + i] *
        octocopter_model_Hinf_RLS_co_DW.DiscreteStateSpace_DSTATE[j];
    }

    xnew[i] = ((octocopter_model_Hinf_RLS_com_P.B_KR[i] * *arg_inverse_Ix_hat +
                Ix) + octocopter_model_Hinf_RLS_com_P.B_KR[i + 11] *
               *arg_inverse_Iy_hat) + octocopter_model_Hinf_RLS_com_P.B_KR[i +
      22] * *arg_inverse_Iz_hat;
  }

  for (i = 0; i < 11; i++) {
    octocopter_model_Hinf_RLS_co_DW.DiscreteStateSpace_DSTATE[i] = xnew[i];
  }

  // End of Update for DiscreteStateSpace: '<S1>/Discrete State-Space'

  // Update for Delay: '<S1>/Delay9'
  octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a = *arg_tau_x;

  // Update for Delay: '<S1>/Delay2'
  octocopter_model_Hinf_RLS_co_DW.Delay2_DSTATE_g = rtb_DigitalFilter_lt;

  // Update for Delay: '<S1>/Delay'
  octocopter_model_Hinf_RLS_co_DW.Delay_DSTATE = rtb_DigitalFilter;

  // Update for Delay: '<S1>/Delay1'
  octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE_m = rtb_DigitalFilter_d;

  // Update for Delay: '<S1>/Delay10'
  octocopter_model_Hinf_RLS_co_DW.Delay10_DSTATE = *arg_tau_y;

  // Update for Delay: '<S1>/Delay5'
  octocopter_model_Hinf_RLS_co_DW.Delay5_DSTATE_h = rtb_DigitalFilter;

  // Update for Delay: '<S1>/Delay3'
  octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE_d = rtb_DigitalFilter_d;

  // Update for Delay: '<S1>/Delay4'
  octocopter_model_Hinf_RLS_co_DW.Delay4_DSTATE_f = rtb_DigitalFilter_lt;

  // Update for Delay: '<S1>/Delay11'
  octocopter_model_Hinf_RLS_co_DW.Delay11_DSTATE = *arg_tau_z;

  // Update for Delay: '<S1>/Delay6'
  octocopter_model_Hinf_RLS_co_DW.Delay6_DSTATE_h = rtb_DigitalFilter_lt;

  // Update for Delay: '<S1>/Delay7'
  octocopter_model_Hinf_RLS_co_DW.Delay7_DSTATE_o = rtb_DigitalFilter;

  // Update for Delay: '<S1>/Delay8'
  octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE_i = rtb_DigitalFilter_d;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.0025, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  (&octocopter_model_Hinf_RLS_co_M)->Timing.clockTick0++;
}

// Model initialize function
void octocopter_model_Hinf_RLS_combined::initialize()
{
  {
    int32_T i;
    static const int8_T tmp[9]{ 20, 0, 0, 0, 20, 0, 0, 0, 20 };

    static const int8_T tmp_0[9]{ 10, 0, 0, 0, 10, 0, 0, 0, 10 };

    static const int8_T tmp_1[9]{ 90, 0, 0, 0, 90, 0, 0, 0, 90 };

    // InitializeConditions for DiscreteStateSpace: '<S1>/Discrete State-Space'
    for (i = 0; i < 11; i++) {
      octocopter_model_Hinf_RLS_co_DW.DiscreteStateSpace_DSTATE[i] =
        octocopter_model_Hinf_RLS_com_P.DiscreteStateSpace_InitialCondi;
    }

    // End of InitializeConditions for DiscreteStateSpace: '<S1>/Discrete State-Space' 

    // InitializeConditions for Delay: '<S21>/Delay1'
    octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay2'
    octocopter_model_Hinf_RLS_co_DW.Delay2_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay4'
    octocopter_model_Hinf_RLS_co_DW.Delay4_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay3'
    octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay5'
    octocopter_model_Hinf_RLS_co_DW.Delay5_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay6'
    octocopter_model_Hinf_RLS_co_DW.Delay6_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay7'
    octocopter_model_Hinf_RLS_co_DW.Delay7_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay9'
    octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S21>/Delay8'
    octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay9'
    octocopter_model_Hinf_RLS_co_DW.Delay9_DSTATE_a =
      octocopter_model_Hinf_RLS_com_P.Delay9_InitialCondition_o;

    // InitializeConditions for Delay: '<S1>/Delay2'
    octocopter_model_Hinf_RLS_co_DW.Delay2_DSTATE_g =
      octocopter_model_Hinf_RLS_com_P.Delay2_InitialCondition_l;

    // InitializeConditions for Delay: '<S1>/Delay'
    octocopter_model_Hinf_RLS_co_DW.Delay_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay1'
    octocopter_model_Hinf_RLS_co_DW.Delay1_DSTATE_m =
      octocopter_model_Hinf_RLS_com_P.Delay1_InitialCondition_f;

    // InitializeConditions for Delay: '<S1>/Delay10'
    octocopter_model_Hinf_RLS_co_DW.Delay10_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay5'
    octocopter_model_Hinf_RLS_co_DW.Delay5_DSTATE_h =
      octocopter_model_Hinf_RLS_com_P.Delay5_InitialCondition_l;

    // InitializeConditions for Delay: '<S1>/Delay3'
    octocopter_model_Hinf_RLS_co_DW.Delay3_DSTATE_d =
      octocopter_model_Hinf_RLS_com_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S1>/Delay4'
    octocopter_model_Hinf_RLS_co_DW.Delay4_DSTATE_f =
      octocopter_model_Hinf_RLS_com_P.Delay4_InitialCondition_o;

    // InitializeConditions for Delay: '<S1>/Delay11'
    octocopter_model_Hinf_RLS_co_DW.Delay11_DSTATE =
      octocopter_model_Hinf_RLS_com_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay6'
    octocopter_model_Hinf_RLS_co_DW.Delay6_DSTATE_h =
      octocopter_model_Hinf_RLS_com_P.Delay6_InitialCondition_f;

    // InitializeConditions for Delay: '<S1>/Delay7'
    octocopter_model_Hinf_RLS_co_DW.Delay7_DSTATE_o =
      octocopter_model_Hinf_RLS_com_P.Delay7_InitialCondition_c;

    // InitializeConditions for Delay: '<S1>/Delay8'
    octocopter_model_Hinf_RLS_co_DW.Delay8_DSTATE_i =
      octocopter_model_Hinf_RLS_com_P.Delay8_InitialCondition_f;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function16'
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[0] = 0.3F;
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[1] = 1.5F;
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_phi[2] = 0.0F;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function7'
    octocopter_model_Hinf_RLS_co_DW.y_prev = 1.5F;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function23'
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[0] = 0.0F;
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[1] = 1.0869565F;
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_theta[2] = 0.0F;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3'
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[0] = 0.0F;
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[1] = 0.854700863F;
    octocopter_model_Hinf_RLS_co_DW.prev_estimate_psi[2] = 0.0F;
    for (i = 0; i < 9; i++) {
      // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function16'
      octocopter_model_Hinf_RLS_co_DW.prev_P_phi[i] = tmp[i];

      // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function23'
      octocopter_model_Hinf_RLS_co_DW.prev_P_theta[i] = tmp_0[i];

      // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3'
      octocopter_model_Hinf_RLS_co_DW.prev_P_psi[i] = tmp_1[i];
    }

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function14'
    octocopter_model_Hinf_RLS_co_DW.y_prev_g = 0.854700863F;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function11'
    octocopter_model_Hinf_RLS_co_DW.y_prev_f = 1.0869565F;
  }
}

// Model terminate function
void octocopter_model_Hinf_RLS_combined::terminate()
{
  // (no terminate code required)
}

const char_T* octocopter_model_Hinf_RLS_combined::
  RT_MODEL_octocopter_model_Hin_T::getErrorStatus() const
{
  return (errorStatus);
}

void octocopter_model_Hinf_RLS_combined::RT_MODEL_octocopter_model_Hin_T::
  setErrorStatus(const char_T* const volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
octocopter_model_Hinf_RLS_combined::octocopter_model_Hinf_RLS_combined() :
  octocopter_model_Hinf_RLS_co_DW(),
  octocopter_model_Hinf_RLS_co_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
octocopter_model_Hinf_RLS_combined::~octocopter_model_Hinf_RLS_combined() =
  default;

// Real-Time Model get method
octocopter_model_Hinf_RLS_combined::RT_MODEL_octocopter_model_Hin_T
  * octocopter_model_Hinf_RLS_combined::getRTM()
{
  return (&octocopter_model_Hinf_RLS_co_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
