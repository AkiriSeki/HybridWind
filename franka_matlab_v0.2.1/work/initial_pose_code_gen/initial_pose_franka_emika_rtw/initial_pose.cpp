//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: initial_pose.cpp
//
// Code generated for Simulink model 'initial_pose'.
//
// Model version                  : 2.58
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Oct 26 09:11:29 2022
//
// Target selection: franka_emika_panda.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#include "initial_pose.h"
#include "initial_pose_private.h"
#include "initial_pose_dt.h"

SimulinkPandaRobot simulinkPandaRobot_1721602;

// Block signals (default storage)
B_initial_pose_T initial_pose_B;

// Block states (default storage)
DW_initial_pose_T initial_pose_DW;

// Real-time model
RT_MODEL_initial_pose_T initial_pose_M_ = RT_MODEL_initial_pose_T();
RT_MODEL_initial_pose_T *const initial_pose_M = &initial_pose_M_;
pthread_t rtExtModeServerStepThr;
static sem_t ext_mode_main_step_sem;
boolean_T extModeServerStepFinished= true;
void* rtExtModeServerStepThread(void *argv)
{
  for (;;) {
    sem_wait(&ext_mode_main_step_sem);
    extModeServerStepFinished = false;

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(initial_pose_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(initial_pose_M, true);
      }
    }

    rtExtModeCheckEndTrigger();
    extModeServerStepFinished = true;
  }
}

// Model step function
void initial_pose_step(void)
{
  real_T rtb_Product1;
  real_T rtb_Product6;

  // S-Function (get_initial_robot_state): '<S1>/Get Initial Robot State'
  {
    // Wait for the control thread signal
    if ((bool)initial_pose_DW.GetInitialRobotState_DWORK2 &&
        simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      simulinkPandaRobot_1721602.waitForControlThreadStep();
    }

    // If control loop threw exeption terminate execution
    simulinkPandaRobot_1721602.checkIfAndHandleException();
    if (!simulinkPandaRobot_1721602.getCurrentlyInFirstControlStep() && !(bool)
        initial_pose_DW.GetInitialRobotState_DWORK1) {
      std::vector<std::string> output_signals;
      signalsStringToSignalsVector(output_signals,"O_T_EE_c");

      //copy outputs
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 0,
        &initial_pose_B.GetInitialRobotState[0]);
      initial_pose_DW.GetInitialRobotState_DWORK1 = 1;
    }
  }

  // Assignment: '<S1>/Assignment1' incorporates:
  //   SignalConversion generated from: '<S1>/Assignment'

  memcpy(&initial_pose_B.Assignment1[0], &initial_pose_B.GetInitialRobotState[0],
         sizeof(real_T) << 4U);

  // S-Function (get_duration_period): '<S1>/Get Duration Period'
  {
    if (simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      // Wait for the control thread signal
      if ((bool)initial_pose_DW.GetDurationPeriod_DWORK1) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();
      initial_pose_B.GetDurationPeriod =
        simulinkPandaRobot_1721602.getSampleTime();
    }
  }

  // Sum: '<S2>/Sum' incorporates:
  //   Delay: '<S2>/Delay'

  initial_pose_DW.Delay_DSTATE += initial_pose_B.GetDurationPeriod;

  // Product: '<S1>/Product1' incorporates:
  //   Constant: '<S1>/velocity_amplitude5'
  //   Constant: '<S1>/velocity_amplitude8'
  //   RelationalOperator: '<S1>/Relational Operator'
  //   Switch: '<S2>/Switch'

  rtb_Product1 = static_cast<real_T>(!(initial_pose_DW.Delay_DSTATE >= 30.0)) *
    0.3;

  // Product: '<S1>/Product6' incorporates:
  //   Constant: '<S1>/velocity_amplitude2'
  //   Constant: '<S1>/velocity_amplitude3'
  //   Constant: '<S1>/velocity_amplitude4'
  //   Product: '<S1>/Product7'
  //   Sum: '<S1>/Add'
  //   Switch: '<S2>/Switch'
  //   Trigonometry: '<S1>/Trigonometric Function'

  rtb_Product6 = (1.0 - cos(0.62831853071795862 * initial_pose_DW.Delay_DSTATE))
    * 0.78539816339744828;

  // Assignment: '<S1>/Assignment' incorporates:
  //   Assignment: '<S1>/Assignment1'
  //   Constant: '<S1>/Constant'
  //   Product: '<S1>/Product2'
  //   Product: '<S1>/Product8'
  //   Sum: '<S1>/Add2'
  //   Trigonometry: '<S1>/Trigonometric Function1'

  initial_pose_B.Assignment1[12] = rtb_Product1 * sin(rtb_Product6) * 0.0 +
    initial_pose_B.GetInitialRobotState[12];

  // Assignment: '<S1>/Assignment1' incorporates:
  //   Constant: '<S1>/Constant1'
  //   Constant: '<S1>/velocity_amplitude6'
  //   Product: '<S1>/Product3'
  //   Product: '<S1>/Product9'
  //   Sum: '<S1>/Add1'
  //   Sum: '<S1>/Add3'
  //   Trigonometry: '<S1>/Trigonometric Function2'

  initial_pose_B.Assignment1[14] = (cos(rtb_Product6) - 1.0) * rtb_Product1 *
    0.0 + initial_pose_B.GetInitialRobotState[14];

  // S-Function (apply_control): '<Root>/Apply Control'
  {
    // S-Function Block: <Root>/Apply Control
    if ((bool)initial_pose_DW.ApplyControl_DWORK1) {
      // Wait for the control thread signal
      if ((bool)initial_pose_DW.ApplyControl_DWORK2) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();

      // copy inputs
      simulinkPandaRobot_1721602.copyInputSignal(&initial_pose_B.Assignment1[0],
        0);

      // notify control thread that the inputs have been read
      simulinkPandaRobot_1721602.notifyControlThreadToContinue();
    } else if (!(bool)initial_pose_DW.ApplyControl_DWORK1) {
      // Its the first time _step() function is called -->
      // Initialize according to settings parsed from the mask
      // and spawn control thread
      simulinkPandaRobot_1721602.applyRobotSettings();
      simulinkPandaRobot_1721602.spawnControlThread();
      initial_pose_DW.ApplyControl_DWORK1 = 1;
    }
  }

  // S-Function (get_robot_state): '<Root>/Get Robot State'
  {
    // Wait for the control thread signal
    if ((bool)initial_pose_DW.GetRobotState_DWORK1 &&
        simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      simulinkPandaRobot_1721602.waitForControlThreadStep();
    }

    // If control loop threw exeption terminate execution
    simulinkPandaRobot_1721602.checkIfAndHandleException();
    if (!simulinkPandaRobot_1721602.getCurrentlyInFirstControlStep()) {
      std::vector<std::string> output_signals;
      signalsStringToSignalsVector(output_signals,
        "O_T_EE_d O_T_EE control_command_success_rate");

      //copy outputs
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 0,
        &initial_pose_B.GetRobotState_o1[0]);
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 1,
        &initial_pose_B.GetRobotState_o2[0]);
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 2,
        &initial_pose_B.GetRobotState_o3);
    }
  }

  // External mode
  if (extModeServerStepFinished) {
    rtExtModeUploadCheckTrigger(1);

    {                                  // Sample time: [0.001s, 0.0s]
      rtExtModeUpload(0, (real_T)initial_pose_M->Timing.taskTime0);
    }

    sem_post(&ext_mode_main_step_sem);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(initial_pose_M)!=-1) &&
        !((rtmGetTFinal(initial_pose_M)-initial_pose_M->Timing.taskTime0) >
          initial_pose_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(initial_pose_M, "Simulation finished");
    }

    if (rtmGetStopRequested(initial_pose_M)) {
      rtmSetErrorStatus(initial_pose_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  initial_pose_M->Timing.taskTime0 =
    ((time_T)(++initial_pose_M->Timing.clockTick0)) *
    initial_pose_M->Timing.stepSize0;
}

// Model initialize function
void initial_pose_initialize(void)
{
  // Registration code
  rtmSetTFinal(initial_pose_M, -1);
  initial_pose_M->Timing.stepSize0 = 0.001;

  // External mode info
  rtParseArgsForExtMode(0,NULL);
  initial_pose_M->Sizes.checksums[0] = (1710632144U);
  initial_pose_M->Sizes.checksums[1] = (3329756707U);
  initial_pose_M->Sizes.checksums[2] = (2149252189U);
  initial_pose_M->Sizes.checksums[3] = (3609592139U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    initial_pose_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(initial_pose_M->extModeInfo,
      &initial_pose_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(initial_pose_M->extModeInfo,
                        initial_pose_M->Sizes.checksums);
    rteiSetTPtr(initial_pose_M->extModeInfo, rtmGetTPtr(initial_pose_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    initial_pose_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;
  }

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(initial_pose_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(initial_pose_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(initial_pose_M, true);
    }
  }

  rtERTExtModeStartMsg();
  sem_init(&ext_mode_main_step_sem, 0, 0);
  pthread_create( &rtExtModeServerStepThr, NULL, &rtExtModeServerStepThread,
                 (void*) NULL);

  // block instance data
  {
    {
      simulinkPandaRobot_1721602 = SimulinkPandaRobot( "172.16.0.2",
        0,
        7,
        0,
        initial_pose_ConstP.ApplyControl_P1,
        initial_pose_ConstP.ApplyControl_P2,
        initial_pose_ConstP.ApplyControl_P3,
        initial_pose_ConstP.ApplyControl_P4,
        initial_pose_ConstP.ApplyControl_P5,
        1,
        initial_pose_ConstP.ApplyControl_P6,
        0);
    }
  }

  // Start for S-Function (get_initial_robot_state): '<S1>/Get Initial Robot State' 
  {
    initial_pose_DW.GetInitialRobotState_DWORK1 = 0;
    initial_pose_DW.GetInitialRobotState_DWORK2 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  // Start for S-Function (get_duration_period): '<S1>/Get Duration Period'
  {
    initial_pose_DW.GetDurationPeriod_DWORK1 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  // Start for S-Function (apply_control): '<Root>/Apply Control'
  {
    //Flag for performing initialization in first run of main _step();
    initial_pose_DW.ApplyControl_DWORK1 = 0;
    initial_pose_DW.ApplyControl_DWORK2 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  // Start for S-Function (get_robot_state): '<Root>/Get Robot State'
  {
    initial_pose_DW.GetRobotState_DWORK1 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }
}

// Model terminate function
void initial_pose_terminate(void)
{
  // Terminate for S-Function (apply_control): '<Root>/Apply Control'
  {
    // S-Function Block: <Root>/Apply Control
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
