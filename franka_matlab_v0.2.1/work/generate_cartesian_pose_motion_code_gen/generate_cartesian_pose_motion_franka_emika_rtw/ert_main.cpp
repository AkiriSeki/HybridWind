//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'generate_cartesian_pose_motion'.
//
// Model version                  : 2.21
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Oct  5 11:02:45 2022
//
// Target selection: franka_emika_panda.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                // This ert_main.c example uses printf/fflush
#include "generate_cartesian_pose_motion.h" // Model's header file
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ext_work.h"                  // External mode header file

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
  static boolean_T OverrunFlag = false;

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(generate_cartesian_pose_moti_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  generate_cartesian_pose_motion_step();

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
  rtExtModeCheckEndTrigger();
}

//
// The example "main" function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific.  This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // External mode

  // Initialize model
  generate_cartesian_pose_motion_initialize();

  // The External Mode option selected; therefore,
  //   simulating the model step behavior (in non real-time).

  while ((rtmGetErrorStatus(generate_cartesian_pose_moti_M) == (NULL)) &&
         !rtmGetStopRequested(generate_cartesian_pose_moti_M)) {
    rt_OneStep();
  }

  // Disable rt_OneStep() here

  // Terminate model
  generate_cartesian_pose_motion_terminate();

  // External mode
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
