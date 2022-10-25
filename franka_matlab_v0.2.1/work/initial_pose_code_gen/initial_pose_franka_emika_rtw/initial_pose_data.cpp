//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: initial_pose_data.cpp
//
// Code generated for Simulink model 'initial_pose'.
//
// Model version                  : 2.54
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Oct 25 14:33:00 2022
//
// Target selection: franka_emika_panda.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#include "initial_pose.h"
#include "initial_pose_private.h"

// Constant parameters (default storage)
const ConstP_initial_pose_T initial_pose_ConstP = {
  // Expression: collision_thresholds
  //  Referenced by: '<Root>/Apply Control'

  { 25.0, 25.0, 22.0, 20.0, 19.0, 17.0, 14.0, 35.0, 35.0, 32.0, 30.0, 29.0, 27.0,
    24.0, 25.0, 25.0, 22.0, 20.0, 19.0, 17.0, 14.0, 35.0, 35.0, 32.0, 30.0, 29.0,
    27.0, 24.0, 30.0, 30.0, 30.0, 25.0, 25.0, 25.0, 40.0, 40.0, 40.0, 35.0, 35.0,
    35.0, 30.0, 30.0, 30.0, 25.0, 25.0, 25.0, 40.0, 40.0, 40.0, 35.0, 35.0, 35.0
  },

  // Expression: joint_impedance
  //  Referenced by: '<Root>/Apply Control'

  { 3000.0, 3000.0, 3000.0, 2500.0, 2500.0, 2000.0, 2000.0 },

  // Expression: cartesian_impedance
  //  Referenced by: '<Root>/Apply Control'

  { 3000.0, 3000.0, 3000.0, 300.0, 300.0, 300.0 },

  // Expression: load_inertia
  //  Referenced by: '<Root>/Apply Control'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: EE_T_K
  //  Referenced by: '<Root>/Apply Control'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  // Expression: init_joint_configuration
  //  Referenced by: '<Root>/Apply Control'

  { 1.5707963267948966, 0.555, 0.0, -0.78539816339744828, 0.0, 1.4,
    0.78539816339744828 }
};

//
// File trailer for generated code.
//
// [EOF]
//
