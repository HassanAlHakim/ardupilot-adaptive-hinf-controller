//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>              // This example main program uses printf/fflush
#include "octocopter_model_Hinf_RLS_combined.h" // Model header file

static octocopter_model_Hinf_RLS_combined octocopter_model_Hinf_RLS_c_Obj;// Instance of model class 

// '<Root>/r'
static real32_T arg_r{ 0.0F };

// '<Root>/psi_des'
static real32_T arg_psi_des{ 0.0F };

// '<Root>/theta'
static real32_T arg_theta{ 0.0F };

// '<Root>/q'
static real32_T arg_q{ 0.0F };

// '<Root>/theta_des'
static real32_T arg_theta_des{ 0.0F };

// '<Root>/p'
static real32_T arg_p{ 0.0F };

// '<Root>/phi'
static real32_T arg_phi{ 0.0F };

// '<Root>/psi'
static real32_T arg_psi{ 0.0F };

// '<Root>/phi_des'
static real32_T arg_phi_des{ 0.0F };

// '<Root>/tau_y'
static real32_T arg_tau_y;

// '<Root>/tau_x'
static real32_T arg_tau_x;

// '<Root>/tau_z'
static real32_T arg_tau_z;

// '<Root>/inverse_Ix_hat'
static real32_T arg_inverse_Ix_hat;

// '<Root>/inverse_Iy_hat'
static real32_T arg_inverse_Iy_hat;

// '<Root>/inverse_Iz_hat'
static real32_T arg_inverse_Iz_hat;

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    octocopter_model_Hinf_RLS_c_Obj.getRTM()->setErrorStatus("Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  octocopter_model_Hinf_RLS_c_Obj.step(&arg_tau_y, &arg_tau_x, &arg_tau_z,
    &arg_r, &arg_psi_des, &arg_theta, &arg_q, &arg_theta_des, &arg_p, &arg_phi,
    &arg_psi, &arg_phi_des, &arg_inverse_Ix_hat, &arg_inverse_Iy_hat,
    &arg_inverse_Iz_hat);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  octocopter_model_Hinf_RLS_c_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.0025 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((nullptr));
  while (octocopter_model_Hinf_RLS_c_Obj.getRTM()->getErrorStatus() == (nullptr))
  {
    //  Perform application tasks here
  }

  // Terminate model
  octocopter_model_Hinf_RLS_c_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
