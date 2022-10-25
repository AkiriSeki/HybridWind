//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Test_roboticArm_FC_PIDFe_private.h
//
// Code generated for Simulink model 'Test_roboticArm_FC_PIDFe'.
//
// Model version                  : 2.49
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Sep 26 08:52:28 2022
//
// Target selection: franka_emika_panda.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_Test_roboticArm_FC_PIDFe_private_h_
#define RTW_HEADER_Test_roboticArm_FC_PIDFe_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

#endif                        // RTW_HEADER_Test_roboticArm_FC_PIDFe_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
