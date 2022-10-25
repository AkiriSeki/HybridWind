//
//  initial_pose_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "initial_pose".
//
//  Model version              : 2.54
//  Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
//  C++ source code generated on : Tue Oct 25 14:33:00 2022
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
  { (char_T *)(&initial_pose_B.GetInitialRobotState[0]), 0, 0, 66 }
  ,

  { (char_T *)(&initial_pose_DW.Delay_DSTATE), 0, 0, 7 },

  { (char_T *)(&initial_pose_DW.ControlObjectiveScope_PWORK.LoggedData[0]), 11,
    0, 3 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  3U,
  rtBTransitions
};

// [EOF] initial_pose_dt.h
