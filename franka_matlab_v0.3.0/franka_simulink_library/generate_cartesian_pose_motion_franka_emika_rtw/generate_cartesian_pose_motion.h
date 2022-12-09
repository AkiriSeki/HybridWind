/*
 * generate_cartesian_pose_motion.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "generate_cartesian_pose_motion".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Tue Nov 22 08:33:33 2022
 *
 * Target selection: franka_emika_panda.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_generate_cartesian_pose_motion_h_
#define RTW_HEADER_generate_cartesian_pose_motion_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "ext_work.h"
#include "robot_api.h"
#include "control_modes.h"
#include "gripper_api.h"
#include "generate_cartesian_pose_motion_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define generate_cartesian_pose_motion_M (generate_cartesian_pose_moti_M)

/* Block signals (default storage) */
struct B_generate_cartesian_pose_mot_T {
  real_T GetInitialRobotState[16];     /* '<S1>/Get Initial Robot State' */
  real_T GetDurationPeriod;            /* '<S1>/Get Duration Period' */
  real_T Assignment1[16];              /* '<S1>/Assignment1' */
  real_T GetRobotState_o1[16];         /* '<Root>/Get Robot State' */
  real_T GetRobotState_o2[16];         /* '<Root>/Get Robot State' */
  real_T GetRobotState_o3;             /* '<Root>/Get Robot State' */
  real_T x_dx[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T z_dz[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux4_at_outport_0Inport1' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_generate_cartesian_pose_mo_T {
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  real_T GetInitialRobotState_DWORK1;  /* '<S1>/Get Initial Robot State' */
  real_T GetInitialRobotState_DWORK2;  /* '<S1>/Get Initial Robot State' */
  real_T GetDurationPeriod_DWORK1;     /* '<S1>/Get Duration Period' */
  real_T ApplyControl_DWORK1;          /* '<Root>/Apply Control' */
  real_T ApplyControl_DWORK2;          /* '<Root>/Apply Control' */
  real_T GetRobotState_DWORK1;         /* '<Root>/Get Robot State' */
  struct {
    void *LoggedData[2];
  } ControlObjectiveScope_PWORK;       /* '<Root>/Control Objective Scope' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mux4_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mux2_;   /* synthesized block */

  struct {
    void *LoggedData;
  } ControlCommandSuccessRate_PWORK; /* '<Root>/Control Command Success Rate' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_GetRo;   /* synthesized block */
};

/* Constant parameters (default storage) */
struct ConstP_generate_cartesian_pos_T {
  /* Expression: collision_thresholds
   * Referenced by: '<Root>/Apply Control'
   */
  real_T ApplyControl_P1[52];

  /* Expression: joint_impedance
   * Referenced by: '<Root>/Apply Control'
   */
  real_T ApplyControl_P2[7];

  /* Expression: cartesian_impedance
   * Referenced by: '<Root>/Apply Control'
   */
  real_T ApplyControl_P3[6];

  /* Expression: load_inertia
   * Referenced by: '<Root>/Apply Control'
   */
  real_T ApplyControl_P4[13];

  /* Expression: EE_T_K
   * Referenced by: '<Root>/Apply Control'
   */
  real_T ApplyControl_P5[16];

  /* Expression: init_joint_configuration
   * Referenced by: '<Root>/Apply Control'
   */
  real_T ApplyControl_P6[7];
};

/* Real-time Model Data Structure */
struct tag_RTM_generate_cartesian_po_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_generate_cartesian_pose_mot_T generate_cartesian_pose_motio_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern struct DW_generate_cartesian_pose_mo_T generate_cartesian_pose_moti_DW;

/* Constant parameters (default storage) */
extern const ConstP_generate_cartesian_pos_T generate_cartesian_pose__ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void generate_cartesian_pose_motion_initialize(void);
  extern void generate_cartesian_pose_motion_step(void);
  extern void generate_cartesian_pose_motion_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_generate_cartesian_p_T *const generate_cartesian_pose_moti_M;

#ifdef __cplusplus

}
#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant2' : Unused code path elimination
 * Block '<S1>/velocity_amplitude1' : Unused code path elimination
 * Block '<S1>/velocity_amplitude7' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'generate_cartesian_pose_motion'
 * '<S1>'   : 'generate_cartesian_pose_motion/Motion Gen Cartesian Space Draw Arc'
 * '<S2>'   : 'generate_cartesian_pose_motion/Motion Gen Cartesian Space Draw Arc/counter'
 * '<S3>'   : 'generate_cartesian_pose_motion/Motion Gen Cartesian Space Draw Arc/counter/DocBlock'
 */
#endif                        /* RTW_HEADER_generate_cartesian_pose_motion_h_ */
