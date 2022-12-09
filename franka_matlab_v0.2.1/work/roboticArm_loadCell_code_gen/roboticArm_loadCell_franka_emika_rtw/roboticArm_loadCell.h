//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: roboticArm_loadCell.h
//
// Code generated for Simulink model 'roboticArm_loadCell'.
//
// Model version                  : 2.144
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Nov 18 16:03:15 2022
//
// Target selection: franka_emika_panda.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_roboticArm_loadCell_h_
#define RTW_HEADER_roboticArm_loadCell_h_
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
#include "roboticArm_loadCell_types.h"

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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_roboticArm_loadCell_T {
  real_T GetDurationPeriod1;           // '<S4>/Get Duration Period1'
  real_T ByteUnpack[6];                // '<S2>/Byte Unpack'
  real_T GetModel_o1[16];              // '<S3>/Get Model'
  real_T GetModel_o2[42];              // '<S3>/Get Model'
  real_T GetModel_o3[42];              // '<S3>/Get Model'
  real_T GetModel_o4[49];              // '<S3>/Get Model'
  real_T GetModel_o5[7];               // '<S3>/Get Model'
  real_T GetModel_o6[7];               // '<S3>/Get Model'
  real_T Switch;                       // '<S16>/Switch'
  real_T Gain;                         // '<S2>/Gain'
  real_T Switch_a;                     // '<S15>/Switch'
  real_T Subtract2;                    // '<S2>/Subtract2'
  real_T Switch_m;                     // '<S14>/Switch'
  real_T Subtract1;                    // '<S2>/Subtract1'
  real_T Switch_l;                     // '<S13>/Switch'
  real_T Gain1;                        // '<S2>/Gain1'
  real_T Switch_d;                     // '<S17>/Switch'
  real_T Subtract4;                    // '<S2>/Subtract4'
  real_T Switch_mj;                    // '<S18>/Switch'
  real_T Subtract5;                    // '<S2>/Subtract5'
  real_T DurationPeriod;               // '<S3>/Duration Period'
  real_T uDLookupTable1;               // '<S4>/1-D Lookup Table1'
  real_T uDLookupTable2;               // '<S4>/1-D Lookup Table2'
  real_T uDLookupTable5;               // '<S4>/1-D Lookup Table5'
  real_T uDLookupTable3;               // '<S4>/1-D Lookup Table3'
  real_T uDLookupTable4;               // '<S4>/1-D Lookup Table4'
  real_T uDLookupTable6;               // '<S4>/1-D Lookup Table6'
  real_T GetRobotState[7];             // '<S3>/Get Robot State'
  real_T Product[6];                   // '<S3>/Product'
  real_T Add[7];                       // '<S22>/Add'
  real_T tau_im_in[7];                 // '<S21>/tau_im_in'
  real_T DiscreteTimeIntegrator1[6];   // '<S5>/Discrete-Time Integrator1'
  real_T Product_i[7];                 // '<S5>/Product'
  real_T Product1[6];                  // '<S5>/Product1'
  uint8_T UDPReceive_o1[48];           // '<S2>/UDP Receive'
};

// Block states (default storage) for system '<Root>'
struct DW_roboticArm_loadCell_T {
  real_T DiscreteTimeIntegrator_DSTATE;// '<S3>/Discrete-Time Integrator'
  real_T Delay_DSTATE;                 // '<S23>/Delay'
  real_T UD_DSTATE[6];                 // '<S6>/UD'
  real_T DiscreteTimeIntegrator1_DSTATE[6];// '<S5>/Discrete-Time Integrator1'
  real_T GetDurationPeriod1_DWORK1;    // '<S4>/Get Duration Period1'
  real_T UDPReceive_NetworkLib[137];   // '<S2>/UDP Receive'
  real_T GetModel_DWORK1;              // '<S3>/Get Model'
  real_T ICic_PreviousInput;           // '<S16>/IC=ic'
  real_T ICic_PreviousInput_d;         // '<S15>/IC=ic'
  real_T ICic_PreviousInput_e;         // '<S14>/IC=ic'
  real_T ICic_PreviousInput_dd;        // '<S13>/IC=ic'
  real_T ICic_PreviousInput_ej;        // '<S17>/IC=ic'
  real_T ICic_PreviousInput_n;         // '<S18>/IC=ic'
  real_T DurationPeriod_DWORK1;        // '<S3>/Duration Period'
  real_T ApplyControl_DWORK1;          // '<Root>/Apply Control'
  real_T ApplyControl_DWORK2;          // '<Root>/Apply Control'
  real_T GetRobotState_DWORK1;         // '<S3>/Get Robot State'
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 // '<S3>/To Workspace'

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                // '<S3>/To Workspace1'

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                // '<S3>/To Workspace2'

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                // '<S3>/To Workspace3'

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                // '<S3>/To Workspace4'

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                // '<S3>/To Workspace5'

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK_f;              // '<S4>/To Workspace5'

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK_d;              // '<S4>/To Workspace4'

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK_l;              // '<S4>/To Workspace3'

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_i;              // '<S4>/To Workspace2'

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_j;              // '<S4>/To Workspace1'

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_p;               // '<S4>/To Workspace'

  struct {
    void *LoggedData;
  } ToWorkspace11_PWORK;               // '<S2>/To Workspace11'

  struct {
    void *LoggedData;
  } ToWorkspace10_PWORK;               // '<S2>/To Workspace10'

  struct {
    void *LoggedData;
  } ToWorkspace9_PWORK;                // '<S2>/To Workspace9'

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;                // '<S2>/To Workspace8'

  struct {
    void *LoggedData;
  } ToWorkspace7_PWORK;                // '<S2>/To Workspace7'

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                // '<S2>/To Workspace6'

  boolean_T DelayInput1_DSTATE;        // '<S19>/Delay Input1'
  int8_T TorqueBias_SubsysRanBC;       // '<S3>/Torque Bias'
  int8_T Subsystem_SubsysRanBC;        // '<S3>/Subsystem'
  int8_T FFFBPIcntrl_SubsysRanBC;      // '<S1>/FF + FB (PI)  cntrl'
  boolean_T FFFBPIcntrl_MODE;          // '<S1>/FF + FB (PI)  cntrl'
};

// Constant parameters (default storage)
struct ConstP_roboticArm_loadCell_T {
  // Expression: Kp_matr
  //  Referenced by: '<S5>/Kp'

  real_T Kp_Gain[36];

  // Expression: Ki_matr
  //  Referenced by: '<S5>/Ki'

  real_T Ki_Gain[36];

  // Expression: scaled_array(1:10000,2)
  //  Referenced by: '<S4>/1-D Lookup Table1'

  real_T uDLookupTable1_tableData[10000];

  // Pooled Parameter (Expression: scaled_array(1:10000,1))
  //  Referenced by:
  //    '<S4>/1-D Lookup Table1'
  //    '<S4>/1-D Lookup Table2'
  //    '<S4>/1-D Lookup Table3'
  //    '<S4>/1-D Lookup Table4'
  //    '<S4>/1-D Lookup Table5'
  //    '<S4>/1-D Lookup Table6'

  real_T pooled5[10000];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/1-D Lookup Table2'
  //    '<S4>/1-D Lookup Table3'
  //    '<S4>/1-D Lookup Table4'
  //    '<S4>/1-D Lookup Table5'
  //    '<S4>/1-D Lookup Table6'

  real_T pooled6[10000];

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
struct tag_RTM_roboticArm_loadCell_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_roboticArm_loadCell_T roboticArm_loadCell_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_roboticArm_loadCell_T roboticArm_loadCell_DW;

// Constant parameters (default storage)
extern const ConstP_roboticArm_loadCell_T roboticArm_loadCell_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void roboticArm_loadCell_initialize(void);
  extern void roboticArm_loadCell_step(void);
  extern void roboticArm_loadCell_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_roboticArm_loadCell_T *const roboticArm_loadCell_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Data Type Duplicate' : Unused code path elimination
//  Block '<S5>/Reshape' : Reshape block reduction
//  Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S3>/Reshape' : Reshape block reduction
//  Block '<S23>/Constant' : Unused code path elimination
//  Block '<S23>/Constant2' : Unused code path elimination
//  Block '<S4>/velocity_amplitude10' : Unused code path elimination
//  Block '<S4>/velocity_amplitude11' : Unused code path elimination


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
//  '<Root>' : 'roboticArm_loadCell'
//  '<S1>'   : 'roboticArm_loadCell/Explicit Force Control Algorithm'
//  '<S2>'   : 'roboticArm_loadCell/Load Cells'
//  '<S3>'   : 'roboticArm_loadCell/Measurements'
//  '<S4>'   : 'roboticArm_loadCell/Reference Signals'
//  '<S5>'   : 'roboticArm_loadCell/Explicit Force Control Algorithm/FF + FB (PI)  cntrl'
//  '<S6>'   : 'roboticArm_loadCell/Explicit Force Control Algorithm/FF + FB (PI)  cntrl/Discrete Derivative'
//  '<S7>'   : 'roboticArm_loadCell/Load Cells/Sample and Hold'
//  '<S8>'   : 'roboticArm_loadCell/Load Cells/Sample and Hold1'
//  '<S9>'   : 'roboticArm_loadCell/Load Cells/Sample and Hold2'
//  '<S10>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold3'
//  '<S11>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold4'
//  '<S12>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold5'
//  '<S13>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold/Model'
//  '<S14>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold1/Model'
//  '<S15>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold2/Model'
//  '<S16>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold3/Model'
//  '<S17>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold4/Model'
//  '<S18>'  : 'roboticArm_loadCell/Load Cells/Sample and Hold5/Model'
//  '<S19>'  : 'roboticArm_loadCell/Measurements/Detect Increase'
//  '<S20>'  : 'roboticArm_loadCell/Measurements/JT2J_star'
//  '<S21>'  : 'roboticArm_loadCell/Measurements/Subsystem'
//  '<S22>'  : 'roboticArm_loadCell/Measurements/Torque Bias'
//  '<S23>'  : 'roboticArm_loadCell/Reference Signals/counter1'

#endif                                 // RTW_HEADER_roboticArm_loadCell_h_

//
// File trailer for generated code.
//
// [EOF]
//
