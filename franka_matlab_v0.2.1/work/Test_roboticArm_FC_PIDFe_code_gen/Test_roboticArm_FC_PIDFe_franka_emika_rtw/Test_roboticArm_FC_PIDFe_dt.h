//
//  Test_roboticArm_FC_PIDFe_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Test_roboticArm_FC_PIDFe".
//
//  Model version              : 2.49
//  Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
//  C++ source code generated on : Mon Sep 26 08:52:28 2022
//
//  Target selection: franka_emika_panda.tlc
//  Embedded hardware selection: Intel->x86-64 (Linux 64)
//  Code generation objective: Execution efficiency
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Test_roboticArm_FC_PIDFe_B.GetDurationPeriod1), 0, 0, 223 },

  { (char_T *)(&Test_roboticArm_FC_PIDFe_B.UDPReceive_o1[0]), 3, 0, 96 }
  ,

  { (char_T *)(&Test_roboticArm_FC_PIDFe_DW.Delay_DSTATE), 0, 0, 157 },

  { (char_T *)(&Test_roboticArm_FC_PIDFe_DW.ToWorkspace_PWORK.LoggedData), 11, 0,
    24 },

  { (char_T *)(&Test_roboticArm_FC_PIDFe_DW.DelayInput1_DSTATE), 8, 0, 1 },

  { (char_T *)(&Test_roboticArm_FC_PIDFe_DW.TorqueBias_SubsysRanBC), 2, 0, 3 },

  { (char_T *)(&Test_roboticArm_FC_PIDFe_DW.FFFBPIcntrl_MODE), 8, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

// [EOF] Test_roboticArm_FC_PIDFe_dt.h
