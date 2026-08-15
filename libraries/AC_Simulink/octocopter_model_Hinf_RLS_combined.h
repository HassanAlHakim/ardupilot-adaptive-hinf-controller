//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: octocopter_model_Hinf_RLS_combined.h
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
#ifndef octocopter_model_Hinf_RLS_combined_h_
#define octocopter_model_Hinf_RLS_combined_h_
#include <cmath>
#include "rtwtypes.h"
#include "octocopter_model_Hinf_RLS_combined_types.h"

// Class declaration for model octocopter_model_Hinf_RLS_combined
class octocopter_model_Hinf_RLS_combined final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<S1>/MATLAB Function'
  struct DW_MATLABFunction_octocopter__T {
    real32_T x_prev;                   // '<S1>/MATLAB Function'
    real32_T xdot_prev;                // '<S1>/MATLAB Function'
    boolean_T x_prev_not_empty;        // '<S1>/MATLAB Function'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_octocopter_model_Hinf_RLS__T {
    real_T Delay9_DSTATE;              // '<S1>/Delay9'
    real_T DigitalFilter_FILT_STATES[2];// '<S8>/Digital Filter'
    real_T Delay10_DSTATE;             // '<S1>/Delay10'
    real_T DigitalFilter_FILT_STATES_b[2];// '<S9>/Digital Filter'
    real_T Delay11_DSTATE;             // '<S1>/Delay11'
    real_T DigitalFilter_FILT_STATES_l[2];// '<S10>/Digital Filter'
    real32_T DigitalFilter_FILT_STATES_k[2];// '<S2>/Digital Filter'
    real32_T DigitalFilter_FILT_STATES_f[2];// '<S3>/Digital Filter'
    real32_T DigitalFilter_FILT_STATES_m[2];// '<S4>/Digital Filter'
    real32_T DiscreteStateSpace_DSTATE[11];// '<S1>/Discrete State-Space'
    real32_T Delay1_DSTATE;            // '<S21>/Delay1'
    real32_T Delay2_DSTATE;            // '<S21>/Delay2'
    real32_T Delay4_DSTATE;            // '<S21>/Delay4'
    real32_T DigitalFilter_FILT_STATES_e[2];// '<S6>/Digital Filter'
    real32_T DigitalFilter_FILT_STATES_mm[2];// '<S7>/Digital Filter'
    real32_T DigitalFilter_FILT_STATES_lh[2];// '<S5>/Digital Filter'
    real32_T Delay3_DSTATE;            // '<S21>/Delay3'
    real32_T Delay5_DSTATE;            // '<S21>/Delay5'
    real32_T Delay6_DSTATE;            // '<S21>/Delay6'
    real32_T Delay7_DSTATE;            // '<S21>/Delay7'
    real32_T Delay9_DSTATE_o;          // '<S21>/Delay9'
    real32_T Delay8_DSTATE;            // '<S21>/Delay8'
    real32_T Delay_DSTATE;             // '<S1>/Delay'
    real32_T Delay1_DSTATE_m;          // '<S1>/Delay1'
    real32_T Delay2_DSTATE_g;          // '<S1>/Delay2'
    real32_T Delay3_DSTATE_d;          // '<S1>/Delay3'
    real32_T Delay4_DSTATE_f;          // '<S1>/Delay4'
    real32_T Delay5_DSTATE_h;          // '<S1>/Delay5'
    real32_T Delay6_DSTATE_h;          // '<S1>/Delay6'
    real32_T Delay7_DSTATE_o;          // '<S1>/Delay7'
    real32_T Delay8_DSTATE_i;          // '<S1>/Delay8'
    real32_T y_prev;                   // '<S1>/MATLAB Function7'
    real32_T prev_estimate_psi[3];     // '<S1>/MATLAB Function3'
    real32_T prev_P_psi[9];            // '<S1>/MATLAB Function3'
    real32_T prev_error_psi;           // '<S1>/MATLAB Function3'
    real32_T prev_estimate_theta[3];   // '<S1>/MATLAB Function23'
    real32_T prev_P_theta[9];          // '<S1>/MATLAB Function23'
    real32_T prev_error_theta;         // '<S1>/MATLAB Function23'
    real32_T prev_estimate_phi[3];     // '<S1>/MATLAB Function16'
    real32_T prev_P_phi[9];            // '<S1>/MATLAB Function16'
    real32_T prev_error_phi;           // '<S1>/MATLAB Function16'
    real32_T y_prev_g;                 // '<S1>/MATLAB Function14'
    real32_T y_prev_f;                 // '<S1>/MATLAB Function11'
    DW_MATLABFunction_octocopter__T sf_MATLABFunction2;// '<S1>/MATLAB Function2' 
    DW_MATLABFunction_octocopter__T sf_MATLABFunction1;// '<S1>/MATLAB Function1' 
    DW_MATLABFunction_octocopter__T sf_MATLABFunction;// '<S1>/MATLAB Function'
  };

  // Parameters (default storage)
  struct P_octocopter_model_Hinf_RLS_c_T {
    real_T Ixx_m;                      // Variable: Ixx_m
                                          //  Referenced by:
                                          //    '<S21>/Constant'
                                          //    '<S21>/Constant1'
                                          //    '<S21>/Constant4'
                                          //    '<S21>/Constant8'

    real_T Iyy_m;                      // Variable: Iyy_m
                                          //  Referenced by:
                                          //    '<S21>/Constant1'
                                          //    '<S21>/Constant3'
                                          //    '<S21>/Constant4'
                                          //    '<S21>/Constant8'

    real_T Izz_m;                      // Variable: Izz_m
                                          //  Referenced by:
                                          //    '<S21>/Constant1'
                                          //    '<S21>/Constant4'
                                          //    '<S21>/Constant6'
                                          //    '<S21>/Constant8'

    real_T Ts;                         // Variable: Ts
                                          //  Referenced by:
                                          //    '<S1>/Constant'
                                          //    '<S1>/Constant4'
                                          //    '<S1>/Constant6'

    real_T twait_RLS;                  // Variable: twait_RLS
                                          //  Referenced by:
                                          //    '<S21>/Step1'
                                          //    '<S21>/Step2'
                                          //    '<S21>/Step4'

    real32_T A_KR[121];                // Variable: A_KR
                                          //  Referenced by: '<S1>/Discrete State-Space'

    real32_T B_KR[33];                 // Variable: B_KR
                                          //  Referenced by: '<S1>/Discrete State-Space'

    real32_T C_KR[33];                 // Variable: C_KR
                                          //  Referenced by: '<S1>/Discrete State-Space'

    real32_T D_KR[9];                  // Variable: D_KR
                                          //  Referenced by: '<S1>/Discrete State-Space'

    real_T Constant2_Value;            // Expression: 0
                                          //  Referenced by: '<S21>/Constant2'

    real_T Constant5_Value;            // Expression: 0
                                          //  Referenced by: '<S21>/Constant5'

    real_T Constant7_Value;            // Expression: 0
                                          //  Referenced by: '<S21>/Constant7'

    real_T Constant10_Value;           // Expression: 1
                                          //  Referenced by: '<S21>/Constant10'

    real_T Step4_Y0;                   // Expression: 0
                                          //  Referenced by: '<S21>/Step4'

    real_T Step4_YFinal;               // Expression: 1
                                          //  Referenced by: '<S21>/Step4'

    real_T Switch_Threshold;           // Expression: 0
                                          //  Referenced by: '<S21>/Switch'

    real_T Switch1_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch1'

    real_T Switch2_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch2'

    real_T Constant9_Value;            // Expression: 1
                                          //  Referenced by: '<S21>/Constant9'

    real_T Step1_Y0;                   // Expression: 0
                                          //  Referenced by: '<S21>/Step1'

    real_T Step1_YFinal;               // Expression: 1
                                          //  Referenced by: '<S21>/Step1'

    real_T Switch3_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch3'

    real_T Switch4_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch4'

    real_T Constant11_Value;           // Expression: 1
                                          //  Referenced by: '<S21>/Constant11'

    real_T Step2_Y0;                   // Expression: 0
                                          //  Referenced by: '<S21>/Step2'

    real_T Step2_YFinal;               // Expression: 1
                                          //  Referenced by: '<S21>/Step2'

    real_T Switch5_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch5'

    real_T Switch8_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch8'

    real_T Switch7_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch7'

    real_T Switch6_Threshold;          // Expression: 0
                                          //  Referenced by: '<S21>/Switch6'

    real_T Delay9_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S1>/Delay9'

    real_T Constant1_Value;            // Expression: 40
                                          //  Referenced by: '<S1>/Constant1'

    real_T Step_Time;                  // Expression: 0
                                          //  Referenced by: '<S1>/Step'

    real_T Step_Y0;                    // Expression: 1
                                          //  Referenced by: '<S1>/Step'

    real_T Step_YFinal;                // Expression: 0
                                          //  Referenced by: '<S1>/Step'

    real_T Delay10_InitialCondition;   // Expression: 0.0
                                          //  Referenced by: '<S1>/Delay10'

    real_T Constant5_Value_m;          // Expression: 40
                                          //  Referenced by: '<S1>/Constant5'

    real_T Step1_Time;                 // Expression: 0
                                          //  Referenced by: '<S1>/Step1'

    real_T Step1_Y0_e;                 // Expression: 1
                                          //  Referenced by: '<S1>/Step1'

    real_T Step1_YFinal_a;             // Expression: 0
                                          //  Referenced by: '<S1>/Step1'

    real_T Delay11_InitialCondition;   // Expression: 0.0
                                          //  Referenced by: '<S1>/Delay11'

    real_T Constant7_Value_f;          // Expression: 40
                                          //  Referenced by: '<S1>/Constant7'

    real_T Step2_Time;                 // Expression: 0
                                          //  Referenced by: '<S1>/Step2'

    real_T Step2_Y0_o;                 // Expression: 1
                                          //  Referenced by: '<S1>/Step2'

    real_T Step2_YFinal_c;             // Expression: 0
                                          //  Referenced by: '<S1>/Step2'

    real32_T DiscreteStateSpace_InitialCondi;
                          // Computed Parameter: DiscreteStateSpace_InitialCondi
                             //  Referenced by: '<S1>/Discrete State-Space'

    real32_T Delay1_InitialCondition;
                                  // Computed Parameter: Delay1_InitialCondition
                                     //  Referenced by: '<S21>/Delay1'

    real32_T Delay2_InitialCondition;
                                  // Computed Parameter: Delay2_InitialCondition
                                     //  Referenced by: '<S21>/Delay2'

    real32_T Delay4_InitialCondition;
                                  // Computed Parameter: Delay4_InitialCondition
                                     //  Referenced by: '<S21>/Delay4'

    real32_T Delay3_InitialCondition;
                                  // Computed Parameter: Delay3_InitialCondition
                                     //  Referenced by: '<S21>/Delay3'

    real32_T Delay5_InitialCondition;
                                  // Computed Parameter: Delay5_InitialCondition
                                     //  Referenced by: '<S21>/Delay5'

    real32_T Delay6_InitialCondition;
                                  // Computed Parameter: Delay6_InitialCondition
                                     //  Referenced by: '<S21>/Delay6'

    real32_T Delay7_InitialCondition;
                                  // Computed Parameter: Delay7_InitialCondition
                                     //  Referenced by: '<S21>/Delay7'

    real32_T Delay9_InitialCondition_f;
                                // Computed Parameter: Delay9_InitialCondition_f
                                   //  Referenced by: '<S21>/Delay9'

    real32_T Delay8_InitialCondition;
                                  // Computed Parameter: Delay8_InitialCondition
                                     //  Referenced by: '<S21>/Delay8'

    real32_T Delay_InitialCondition;
                                   // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S1>/Delay'

    real32_T Delay1_InitialCondition_f;
                                // Computed Parameter: Delay1_InitialCondition_f
                                   //  Referenced by: '<S1>/Delay1'

    real32_T Delay2_InitialCondition_l;
                                // Computed Parameter: Delay2_InitialCondition_l
                                   //  Referenced by: '<S1>/Delay2'

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S21>/Gain1'

    real32_T Delay3_InitialCondition_a;
                                // Computed Parameter: Delay3_InitialCondition_a
                                   //  Referenced by: '<S1>/Delay3'

    real32_T Delay4_InitialCondition_o;
                                // Computed Parameter: Delay4_InitialCondition_o
                                   //  Referenced by: '<S1>/Delay4'

    real32_T Delay5_InitialCondition_l;
                                // Computed Parameter: Delay5_InitialCondition_l
                                   //  Referenced by: '<S1>/Delay5'

    real32_T Delay6_InitialCondition_f;
                                // Computed Parameter: Delay6_InitialCondition_f
                                   //  Referenced by: '<S1>/Delay6'

    real32_T Delay7_InitialCondition_c;
                                // Computed Parameter: Delay7_InitialCondition_c
                                   //  Referenced by: '<S1>/Delay7'

    real32_T Delay8_InitialCondition_f;
                                // Computed Parameter: Delay8_InitialCondition_f
                                   //  Referenced by: '<S1>/Delay8'

    real32_T Gain2_Gain;               // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S21>/Gain2'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S21>/Gain'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_octocopter_model_Hin_T {
    const char_T * volatile errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
    } Timing;

    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

  // Copy Constructor
  octocopter_model_Hinf_RLS_combined(octocopter_model_Hinf_RLS_combined const&) =
    delete;

  // Assignment Operator
  octocopter_model_Hinf_RLS_combined& operator=
    (octocopter_model_Hinf_RLS_combined const&) & = delete;

  // Move Constructor
  octocopter_model_Hinf_RLS_combined(octocopter_model_Hinf_RLS_combined &&) =
    delete;

  // Move Assignment Operator
  octocopter_model_Hinf_RLS_combined& operator=
    (octocopter_model_Hinf_RLS_combined &&) = delete;

  // Real-Time Model get method
  octocopter_model_Hinf_RLS_combined::RT_MODEL_octocopter_model_Hin_T * getRTM();

  // Tunable parameters
  static P_octocopter_model_Hinf_RLS_c_T octocopter_model_Hinf_RLS_com_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T *arg_tau_y, real32_T *arg_tau_x, real32_T *arg_tau_z,
            real32_T *arg_r, real32_T *arg_psi_des, real32_T *arg_theta,
            real32_T *arg_q, real32_T *arg_theta_des, real32_T *arg_p, real32_T *
            arg_phi, real32_T *arg_psi, real32_T *arg_phi_des, real32_T
            *arg_inverse_Ix_hat, real32_T *arg_inverse_Iy_hat, real32_T
            *arg_inverse_Iz_hat, real_T *arg_real_tau_x, real_T *arg_real_tau_y,
            real_T *arg_real_tau_z);

  // model terminate function
  static void terminate();

  // Constructor
  octocopter_model_Hinf_RLS_combined();

  // Destructor
  ~octocopter_model_Hinf_RLS_combined();

  // private data and function members
 private:
  // Block states
  DW_octocopter_model_Hinf_RLS__T octocopter_model_Hinf_RLS_co_DW;

  // private member function(s) for subsystem '<S1>/MATLAB Function'
  static void octocopter_model_MATLABFunction(real32_T rtu_x, real_T rtu_Ts,
    real_T rtu_fc, real_T rtu_reset, real32_T *rty_xdot,
    DW_MATLABFunction_octocopter__T *localDW);

  // Real-Time Model
  RT_MODEL_octocopter_model_Hin_T octocopter_model_Hinf_RLS_co_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S22>/Check Signal Attributes' : Unused code path elimination
//  Block '<S23>/Check Signal Attributes' : Unused code path elimination
//  Block '<S24>/Check Signal Attributes' : Unused code path elimination
//  Block '<S25>/Check Signal Attributes' : Unused code path elimination
//  Block '<S26>/Check Signal Attributes' : Unused code path elimination
//  Block '<S27>/Check Signal Attributes' : Unused code path elimination
//  Block '<S28>/Check Signal Attributes' : Unused code path elimination
//  Block '<S29>/Check Signal Attributes' : Unused code path elimination
//  Block '<S30>/Check Signal Attributes' : Unused code path elimination
//  Block '<S21>/Scope' : Unused code path elimination
//  Block '<S21>/Scope1' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'octocopter_model_Hinf_RLS_combined'
//  '<S1>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem'
//  '<S2>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design'
//  '<S3>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design1'
//  '<S4>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design2'
//  '<S5>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design3'
//  '<S6>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design4'
//  '<S7>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design5'
//  '<S8>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design6'
//  '<S9>'   : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design7'
//  '<S10>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design8'
//  '<S11>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function'
//  '<S12>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function1'
//  '<S13>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function11'
//  '<S14>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function14'
//  '<S15>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function16'
//  '<S16>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function2'
//  '<S17>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function23'
//  '<S18>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function3'
//  '<S19>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function7'
//  '<S20>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/MATLAB Function9'
//  '<S21>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Torque control'
//  '<S22>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design/Check Signal Attributes'
//  '<S23>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design1/Check Signal Attributes'
//  '<S24>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design2/Check Signal Attributes'
//  '<S25>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design3/Check Signal Attributes'
//  '<S26>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design4/Check Signal Attributes'
//  '<S27>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design5/Check Signal Attributes'
//  '<S28>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design6/Check Signal Attributes'
//  '<S29>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design7/Check Signal Attributes'
//  '<S30>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Digital Filter Design8/Check Signal Attributes'
//  '<S31>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Torque control/MATLAB Function'
//  '<S32>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Torque control/MATLAB Function1'
//  '<S33>'  : 'octocopter_model_Hinf_RLS_combined/Subsystem/Torque control/MATLAB Function2'

#endif                                 // octocopter_model_Hinf_RLS_combined_h_

//
// File trailer for generated code.
//
// [EOF]
//
