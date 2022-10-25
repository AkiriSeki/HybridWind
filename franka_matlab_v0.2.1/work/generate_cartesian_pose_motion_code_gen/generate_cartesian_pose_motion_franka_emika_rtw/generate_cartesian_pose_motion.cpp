//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: generate_cartesian_pose_motion.cpp
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
#include "generate_cartesian_pose_motion.h"
#include "generate_cartesian_pose_motion_private.h"
#include "generate_cartesian_pose_motion_dt.h"

SimulinkPandaRobot simulinkPandaRobot_1721602;

// Block signals (default storage)
B_generate_cartesian_pose_mot_T generate_cartesian_pose_motio_B;

// Block states (default storage)
DW_generate_cartesian_pose_mo_T generate_cartesian_pose_moti_DW;

// Real-time model
RT_MODEL_generate_cartesian_p_T generate_cartesian_pose_moti_M_ =
  RT_MODEL_generate_cartesian_p_T();
RT_MODEL_generate_cartesian_p_T *const generate_cartesian_pose_moti_M =
  &generate_cartesian_pose_moti_M_;
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
      rtExtModeOneStep(generate_cartesian_pose_moti_M->extModeInfo, 1,
                       &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(generate_cartesian_pose_moti_M, true);
      }
    }

    rtExtModeCheckEndTrigger();
    extModeServerStepFinished = true;
  }
}

// Model step function
void generate_cartesian_pose_motion_step(void)
{
  real_T rtb_Add3;
  real_T rtb_Product6;

  // S-Function (get_initial_robot_state): '<S1>/Get Initial Robot State'
  {
    // Wait for the control thread signal
    if ((bool)generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK2 &&
        simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      simulinkPandaRobot_1721602.waitForControlThreadStep();
    }

    // If control loop threw exeption terminate execution
    simulinkPandaRobot_1721602.checkIfAndHandleException();
    if (!simulinkPandaRobot_1721602.getCurrentlyInFirstControlStep() && !(bool)
        generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK1) {
      std::vector<std::string> output_signals;
      signalsStringToSignalsVector(output_signals,"O_T_EE_c");

      //copy outputs
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 0,
        &generate_cartesian_pose_motio_B.GetInitialRobotState[0]);
      generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK1 = 1;
    }
  }

  // SignalConversion generated from: '<S1>/Assignment'
  memcpy(&generate_cartesian_pose_motio_B.Assignment1[0],
         &generate_cartesian_pose_motio_B.GetInitialRobotState[0], sizeof(real_T)
         << 4U);

  // S-Function (get_duration_period): '<S1>/Get Duration Period'
  {
    if (simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      // Wait for the control thread signal
      if ((bool)generate_cartesian_pose_moti_DW.GetDurationPeriod_DWORK1) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();
      generate_cartesian_pose_motio_B.GetDurationPeriod =
        simulinkPandaRobot_1721602.getSampleTime();
    }
  }

  // Sum: '<S2>/Sum' incorporates:
  //   Delay: '<S2>/Delay'

  generate_cartesian_pose_moti_DW.Delay_DSTATE +=
    generate_cartesian_pose_motio_B.GetDurationPeriod;

  // Product: '<S1>/Product1' incorporates:
  //   Constant: '<S1>/velocity_amplitude5'
  //   Constant: '<S1>/velocity_amplitude8'
  //   RelationalOperator: '<S1>/Relational Operator'
  //   Switch: '<S2>/Switch'

  rtb_Add3 = static_cast<real_T>(!(generate_cartesian_pose_moti_DW.Delay_DSTATE >=
    30.0)) * 0.3;

  // Product: '<S1>/Product6' incorporates:
  //   Constant: '<S1>/velocity_amplitude2'
  //   Constant: '<S1>/velocity_amplitude3'
  //   Constant: '<S1>/velocity_amplitude4'
  //   Product: '<S1>/Product7'
  //   Sum: '<S1>/Add'
  //   Switch: '<S2>/Switch'
  //   Trigonometry: '<S1>/Trigonometric Function'

  rtb_Product6 = (1.0 - cos(0.62831853071795862 *
    generate_cartesian_pose_moti_DW.Delay_DSTATE)) * 0.78539816339744828;

  // Product: '<S1>/Product8' incorporates:
  //   Sum: '<S1>/Add2'
  //   Trigonometry: '<S1>/Trigonometric Function1'

  generate_cartesian_pose_motio_B.Assignment1[12] = rtb_Add3 * sin(rtb_Product6);

  // Sum: '<S1>/Add2'
  generate_cartesian_pose_motio_B.Assignment1[12] +=
    generate_cartesian_pose_motio_B.GetInitialRobotState[12];

  // Assignment: '<S1>/Assignment1' incorporates:
  //   Constant: '<S1>/velocity_amplitude6'
  //   Product: '<S1>/Product9'
  //   Sum: '<S1>/Add1'
  //   Sum: '<S1>/Add3'
  //   Trigonometry: '<S1>/Trigonometric Function2'

  generate_cartesian_pose_motio_B.Assignment1[14] = (cos(rtb_Product6) - 1.0) *
    rtb_Add3 + generate_cartesian_pose_motio_B.GetInitialRobotState[14];

  // S-Function (apply_control): '<Root>/Apply Control'
  {
    // S-Function Block: <Root>/Apply Control
    if ((bool)generate_cartesian_pose_moti_DW.ApplyControl_DWORK1) {
      // Wait for the control thread signal
      if ((bool)generate_cartesian_pose_moti_DW.ApplyControl_DWORK2) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();

      // copy inputs
      simulinkPandaRobot_1721602.copyInputSignal
        (&generate_cartesian_pose_motio_B.Assignment1[0], 0);

      // notify control thread that the inputs have been read
      simulinkPandaRobot_1721602.notifyControlThreadToContinue();
    } else if (!(bool)generate_cartesian_pose_moti_DW.ApplyControl_DWORK1) {
      // Its the first time _step() function is called -->
      // Initialize according to settings parsed from the mask
      // and spawn control thread
      simulinkPandaRobot_1721602.applyRobotSettings();
      simulinkPandaRobot_1721602.spawnControlThread();
      generate_cartesian_pose_moti_DW.ApplyControl_DWORK1 = 1;
    }
  }

  // S-Function (get_robot_state): '<Root>/Get Robot State'
  {
    // Wait for the control thread signal
    if ((bool)generate_cartesian_pose_moti_DW.GetRobotState_DWORK1 &&
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
        &generate_cartesian_pose_motio_B.GetRobotState_o1[0]);
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 1,
        &generate_cartesian_pose_motio_B.GetRobotState_o2[0]);
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 2,
        &generate_cartesian_pose_motio_B.GetRobotState_o3);
    }
  }

  // External mode
  if (extModeServerStepFinished) {
    rtExtModeUploadCheckTrigger(1);

    {                                  // Sample time: [0.001s, 0.0s]
      rtExtModeUpload(0, (real_T)
                      generate_cartesian_pose_moti_M->Timing.taskTime0);
    }

    sem_post(&ext_mode_main_step_sem);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(generate_cartesian_pose_moti_M)!=-1) &&
        !((rtmGetTFinal(generate_cartesian_pose_moti_M)-
           generate_cartesian_pose_moti_M->Timing.taskTime0) >
          generate_cartesian_pose_moti_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(generate_cartesian_pose_moti_M, "Simulation finished");
    }

    if (rtmGetStopRequested(generate_cartesian_pose_moti_M)) {
      rtmSetErrorStatus(generate_cartesian_pose_moti_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  generate_cartesian_pose_moti_M->Timing.taskTime0 =
    ((time_T)(++generate_cartesian_pose_moti_M->Timing.clockTick0)) *
    generate_cartesian_pose_moti_M->Timing.stepSize0;
}

// Model initialize function
void generate_cartesian_pose_motion_initialize(void)
{
  // Registration code
  rtmSetTFinal(generate_cartesian_pose_moti_M, -1);
  generate_cartesian_pose_moti_M->Timing.stepSize0 = 0.001;

  // External mode info
  rtParseArgsForExtMode(0,NULL);
  generate_cartesian_pose_moti_M->Sizes.checksums[0] = (779313999U);
  generate_cartesian_pose_moti_M->Sizes.checksums[1] = (336140898U);
  generate_cartesian_pose_moti_M->Sizes.checksums[2] = (2004420760U);
  generate_cartesian_pose_moti_M->Sizes.checksums[3] = (3692368171U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    generate_cartesian_pose_moti_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(generate_cartesian_pose_moti_M->extModeInfo,
      &generate_cartesian_pose_moti_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(generate_cartesian_pose_moti_M->extModeInfo,
                        generate_cartesian_pose_moti_M->Sizes.checksums);
    rteiSetTPtr(generate_cartesian_pose_moti_M->extModeInfo, rtmGetTPtr
                (generate_cartesian_pose_moti_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    generate_cartesian_pose_moti_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;
  }

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(generate_cartesian_pose_moti_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(generate_cartesian_pose_moti_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(generate_cartesian_pose_moti_M, true);
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
        generate_cartesian_pose__ConstP.ApplyControl_P1,
        generate_cartesian_pose__ConstP.ApplyControl_P2,
        generate_cartesian_pose__ConstP.ApplyControl_P3,
        generate_cartesian_pose__ConstP.ApplyControl_P4,
        generate_cartesian_pose__ConstP.ApplyControl_P5,
        1,
        generate_cartesian_pose__ConstP.ApplyControl_P6,
        0);
    }
  }

  // Start for S-Function (get_initial_robot_state): '<S1>/Get Initial Robot State' 
  {
    generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK1 = 0;
    generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK2 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  // Start for S-Function (get_duration_period): '<S1>/Get Duration Period'
  {
    generate_cartesian_pose_moti_DW.GetDurationPeriod_DWORK1 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  // Start for S-Function (apply_control): '<Root>/Apply Control'
  {
    //Flag for performing initialization in first run of main _step();
    generate_cartesian_pose_moti_DW.ApplyControl_DWORK1 = 0;
    generate_cartesian_pose_moti_DW.ApplyControl_DWORK2 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  // Start for S-Function (get_robot_state): '<Root>/Get Robot State'
  {
    generate_cartesian_pose_moti_DW.GetRobotState_DWORK1 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }
}

// Model terminate function
void generate_cartesian_pose_motion_terminate(void)
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
