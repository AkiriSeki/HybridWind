//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Test_roboticArm_FC_PIDFe.h
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
#ifndef RTW_HEADER_Test_roboticArm_FC_PIDFe_h_
#define RTW_HEADER_Test_roboticArm_FC_PIDFe_h_
#include <string.h>
#include <math.h>
#include <float.h>
#include <pthread.h>
#include <semaphore.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "robot_api.h"
#include "franka/model.h"
#include "control_modes.h"
#include "gripper_api.h"
#include "DAHostLib_Network.h"
#include "Test_roboticArm_FC_PIDFe_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
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

// Block signals (default storage)
struct B_Test_roboticArm_FC_PIDFe_T {
  real_T GetDurationPeriod1;           // '<S3>/Get Duration Period1'
  real_T GetModel_o1[16];              // '<S2>/Get Model'
  real_T GetModel_o2[42];              // '<S2>/Get Model'
  real_T GetModel_o3[42];              // '<S2>/Get Model'
  real_T GetModel_o4[49];              // '<S2>/Get Model'
  real_T GetModel_o5[7];               // '<S2>/Get Model'
  real_T GetModel_o6[7];               // '<S2>/Get Model'
  real_T GetRobotState[7];             // '<S2>/Get Robot State'
  real_T DurationPeriod;               // '<S2>/Duration Period'
  real_T uDLookupTable1;               // '<S3>/1-D Lookup Table1'
  real_T uDLookupTable2;               // '<S3>/1-D Lookup Table2'
  real_T uDLookupTable5;               // '<S3>/1-D Lookup Table5'
  real_T uDLookupTable3;               // '<S3>/1-D Lookup Table3'
  real_T uDLookupTable4;               // '<S3>/1-D Lookup Table4'
  real_T uDLookupTable6;               // '<S3>/1-D Lookup Table6'
  real_T Product[6];                   // '<S2>/Product'
  real_T ByteUnpack[12];               // '<Root>/Byte Unpack'
  real_T Add[7];                       // '<S9>/Add'
  real_T tau_im_in[7];                 // '<S8>/tau_im_in'
  real_T DiscreteTimeIntegrator1[6];   // '<S4>/Discrete-Time Integrator1'
  real_T Product_i[7];                 // '<S4>/Product'
  uint8_T UDPReceive_o1[96];           // '<Root>/UDP Receive'
};

// Block states (default storage) for system '<Root>'
struct DW_Test_roboticArm_FC_PIDFe_T {
  real_T Delay_DSTATE;                 // '<S10>/Delay'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S2>/Discrete-Time Integrator'
  real_T UD_DSTATE[6];                 // '<S5>/UD'
  real_T DiscreteTimeIntegrator1_DSTATE[6];// '<S4>/Discrete-Time Integrator1'
  real_T GetDurationPeriod1_DWORK1;    // '<S3>/Get Duration Period1'
  real_T GetModel_DWORK1;              // '<S2>/Get Model'
  real_T GetRobotState_DWORK1;         // '<S2>/Get Robot State'
  real_T DurationPeriod_DWORK1;        // '<S2>/Duration Period'
  real_T ApplyControl_DWORK1;          // '<Root>/Apply Control'
  real_T ApplyControl_DWORK2;          // '<Root>/Apply Control'
  real_T UDPReceive_NetworkLib[137];   // '<Root>/UDP Receive'
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 // '<Root>/To Workspace'

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                // '<Root>/To Workspace1'

  struct {
    void *LoggedData;
  } ToWorkspace10_PWORK;               // '<Root>/To Workspace10'

  struct {
    void *LoggedData;
  } ToWorkspace11_PWORK;               // '<Root>/To Workspace11'

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                // '<Root>/To Workspace2'

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                // '<Root>/To Workspace3'

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                // '<Root>/To Workspace4'

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                // '<Root>/To Workspace5'

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                // '<Root>/To Workspace6'

  struct {
    void *LoggedData;
  } ToWorkspace7_PWORK;                // '<Root>/To Workspace7'

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;                // '<Root>/To Workspace8'

  struct {
    void *LoggedData;
  } ToWorkspace9_PWORK;                // '<Root>/To Workspace9'

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_h;               // '<S2>/To Workspace'

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_l;              // '<S2>/To Workspace1'

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_m;              // '<S2>/To Workspace2'

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK_l;              // '<S2>/To Workspace3'

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK_e;              // '<S2>/To Workspace4'

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK_o;              // '<S2>/To Workspace5'

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK_f;              // '<S3>/To Workspace5'

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK_d;              // '<S3>/To Workspace4'

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK_lc;             // '<S3>/To Workspace3'

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_i;              // '<S3>/To Workspace2'

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_j;              // '<S3>/To Workspace1'

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_p;               // '<S3>/To Workspace'

  boolean_T DelayInput1_DSTATE;        // '<S6>/Delay Input1'
  int8_T TorqueBias_SubsysRanBC;       // '<S2>/Torque Bias'
  int8_T Subsystem_SubsysRanBC;        // '<S2>/Subsystem'
  int8_T FFFBPIcntrl_SubsysRanBC;      // '<S1>/FF + FB (PI)  cntrl'
  boolean_T FFFBPIcntrl_MODE;          // '<S1>/FF + FB (PI)  cntrl'
};

// Constant parameters (default storage)
struct ConstP_Test_roboticArm_FC_PID_T {
  // Expression: Kd_matr
  //  Referenced by: '<S4>/Kd'

  real_T Kd_Gain[36];

  // Expression: Kp_matr
  //  Referenced by: '<S4>/Kp'

  real_T Kp_Gain[36];

  // Expression: Ki_matr
  //  Referenced by: '<S4>/Ki'

  real_T Ki_Gain[36];

  // Expression: scaled_array(1:10000,2)
  //  Referenced by: '<S3>/1-D Lookup Table1'

  real_T uDLookupTable1_tableData[10000];

  // Pooled Parameter (Expression: scaled_array(1:10000,1))
  //  Referenced by:
  //    '<S3>/1-D Lookup Table1'
  //    '<S3>/1-D Lookup Table2'
  //    '<S3>/1-D Lookup Table3'
  //    '<S3>/1-D Lookup Table4'
  //    '<S3>/1-D Lookup Table5'
  //    '<S3>/1-D Lookup Table6'

  real_T pooled4[10000];

  // Expression: scaled_array(1:10000,3)
  //  Referenced by: '<S3>/1-D Lookup Table2'

  real_T uDLookupTable2_tableData[10000];

  // Expression: scaled_array(1:10000,4)
  //  Referenced by: '<S3>/1-D Lookup Table5'

  real_T uDLookupTable5_tableData[10000];

  // Expression: scaled_array(1:10000,5)
  //  Referenced by: '<S3>/1-D Lookup Table3'

  real_T uDLookupTable3_tableData[10000];

  // Expression: scaled_array(1:10000,6)
  //  Referenced by: '<S3>/1-D Lookup Table4'

  real_T uDLookupTable4_tableData[10000];

  // Expression: scaled_array(1:10000,7)
  //  Referenced by: '<S3>/1-D Lookup Table6'

  real_T uDLookupTable6_tableData[10000];

  // Expression: collision_thresholds
  //  Referenced by: '<Root>/Apply Control'

  real_T ApplyControl_P1[52];

  // Expression: joint_impedance
  //  Referenced by: '<Root>/Apply Control'

  real_T ApplyControl_P2[7];

  // Expression: cartesian_impedance
  //  Referenced by: '<Root>/Apply Control'

  real_T ApplyControl_P3[6];

  // Expression: load_inertia
  //  Referenced by: '<Root>/Apply Control'

  real_T ApplyControl_P4[13];

  // Expression: EE_T_K
  //  Referenced by: '<Root>/Apply Control'

  real_T ApplyControl_P5[16];

  // Expression: init_joint_configuration
  //  Referenced by: '<Root>/Apply Control'

  real_T ApplyControl_P6[7];
};

// Real-time Model Data Structure
struct tag_RTM_Test_roboticArm_FC_PI_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_Test_roboticArm_FC_PIDFe_T Test_roboticArm_FC_PIDFe_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_Test_roboticArm_FC_PIDFe_T Test_roboticArm_FC_PIDFe_DW;

// Constant parameters (default storage)
extern const ConstP_Test_roboticArm_FC_PID_T Test_roboticArm_FC_PIDFe_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Test_roboticArm_FC_PIDFe_initialize(void);
  extern void Test_roboticArm_FC_PIDFe_step(void);
  extern void Test_roboticArm_FC_PIDFe_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Test_roboticArm_FC_P_T *const Test_roboticArm_FC_PIDFe_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/Reshape' : Reshape block reduction
//  Block '<S2>/Reshape' : Reshape block reduction
//  Block '<S10>/Constant' : Unused code path elimination
//  Block '<S10>/Constant2' : Unused code path elimination
//  Block '<S3>/velocity_amplitude10' : Unused code path elimination
//  Block '<S3>/velocity_amplitude11' : Unused code path elimination


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
//  '<Root>' : 'Test_roboticArm_FC_PIDFe'
//  '<S1>'   : 'Test_roboticArm_FC_PIDFe/Explicit Force Control Algorithm'
//  '<S2>'   : 'Test_roboticArm_FC_PIDFe/Measurements'
//  '<S3>'   : 'Test_roboticArm_FC_PIDFe/Reference Signals'
//  '<S4>'   : 'Test_roboticArm_FC_PIDFe/Explicit Force Control Algorithm/FF + FB (PI)  cntrl'
//  '<S5>'   : 'Test_roboticArm_FC_PIDFe/Explicit Force Control Algorithm/FF + FB (PI)  cntrl/Discrete Derivative'
//  '<S6>'   : 'Test_roboticArm_FC_PIDFe/Measurements/Detect Increase'
//  '<S7>'   : 'Test_roboticArm_FC_PIDFe/Measurements/JT2J_star'
//  '<S8>'   : 'Test_roboticArm_FC_PIDFe/Measurements/Subsystem'
//  '<S9>'   : 'Test_roboticArm_FC_PIDFe/Measurements/Torque Bias'
//  '<S10>'  : 'Test_roboticArm_FC_PIDFe/Reference Signals/counter1'

#endif                                // RTW_HEADER_Test_roboticArm_FC_PIDFe_h_

//
// File trailer for generated code.
//
// [EOF]
//
