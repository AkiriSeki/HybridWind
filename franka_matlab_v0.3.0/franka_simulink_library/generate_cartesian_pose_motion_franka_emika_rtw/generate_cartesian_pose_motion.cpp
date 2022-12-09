/*
 * generate_cartesian_pose_motion.cpp
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

#include "generate_cartesian_pose_motion.h"
#include "generate_cartesian_pose_motion_private.h"

SimulinkPandaRobot simulinkPandaRobot_1721602;

/* Block signals (default storage) */
B_generate_cartesian_pose_mot_T generate_cartesian_pose_motio_B;

/* Block states (default storage) */
DW_generate_cartesian_pose_mo_T generate_cartesian_pose_moti_DW;

/* Real-time model */
RT_MODEL_generate_cartesian_p_T generate_cartesian_pose_moti_M_ =
  RT_MODEL_generate_cartesian_p_T();
RT_MODEL_generate_cartesian_p_T *const generate_cartesian_pose_moti_M =
  &generate_cartesian_pose_moti_M_;

/* Model step function */
void generate_cartesian_pose_motion_step(void)
{
  real_T rtb_Add3;
  real_T rtb_Product6;

  /* S-Function (get_initial_robot_state): '<S1>/Get Initial Robot State' */
  {
    // Wait for the control thread signal
    if ((bool)generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK2 &&
        simulinkPandaRobot_1721602.getControlThreadHasBeenSpawned()) {
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

  /* SignalConversion generated from: '<S1>/Assignment' */
  memcpy(&generate_cartesian_pose_motio_B.Assignment1[0],
         &generate_cartesian_pose_motio_B.GetInitialRobotState[0], sizeof(real_T)
         << 4U);

  /* S-Function (get_duration_period): '<S1>/Get Duration Period' */
  {
    if (simulinkPandaRobot_1721602.getControlThreadHasBeenSpawned()) {
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

  /* Sum: '<S2>/Sum' incorporates:
   *  Delay: '<S2>/Delay'
   */
  generate_cartesian_pose_moti_DW.Delay_DSTATE +=
    generate_cartesian_pose_motio_B.GetDurationPeriod;

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/velocity_amplitude5'
   *  Constant: '<S1>/velocity_amplitude8'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  Switch: '<S2>/Switch'
   */
  rtb_Add3 = static_cast<real_T>(!(generate_cartesian_pose_moti_DW.Delay_DSTATE >=
    30.0)) * 0.3;

  /* Product: '<S1>/Product6' incorporates:
   *  Constant: '<S1>/velocity_amplitude2'
   *  Constant: '<S1>/velocity_amplitude3'
   *  Constant: '<S1>/velocity_amplitude4'
   *  Product: '<S1>/Product7'
   *  Sum: '<S1>/Add'
   *  Switch: '<S2>/Switch'
   *  Trigonometry: '<S1>/Trigonometric Function'
   */
  rtb_Product6 = (1.0 - cos(0.62831853071795862 *
    generate_cartesian_pose_moti_DW.Delay_DSTATE)) * 0.78539816339744828;

  /* Product: '<S1>/Product8' incorporates:
   *  Sum: '<S1>/Add2'
   *  Trigonometry: '<S1>/Trigonometric Function1'
   */
  generate_cartesian_pose_motio_B.Assignment1[12] = rtb_Add3 * sin(rtb_Product6);

  /* Sum: '<S1>/Add2' */
  generate_cartesian_pose_motio_B.Assignment1[12] +=
    generate_cartesian_pose_motio_B.GetInitialRobotState[12];

  /* Assignment: '<S1>/Assignment1' incorporates:
   *  Constant: '<S1>/velocity_amplitude6'
   *  Product: '<S1>/Product9'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add3'
   *  Trigonometry: '<S1>/Trigonometric Function2'
   */
  generate_cartesian_pose_motio_B.Assignment1[14] = (cos(rtb_Product6) - 1.0) *
    rtb_Add3 + generate_cartesian_pose_motio_B.GetInitialRobotState[14];

  /* S-Function (apply_control): '<Root>/Apply Control' */
  {
    /* S-Function Block: <Root>/Apply Control */
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

  /* S-Function (get_robot_state): '<Root>/Get Robot State' */
  {
    // Wait for the control thread signal
    if ((bool)generate_cartesian_pose_moti_DW.GetRobotState_DWORK1 &&
        simulinkPandaRobot_1721602.getControlThreadHasBeenSpawned()) {
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

  /* SignalConversion generated from: '<Root>/Mux2' */
  generate_cartesian_pose_motio_B.x_dx[0] =
    generate_cartesian_pose_motio_B.GetRobotState_o1[12];
  generate_cartesian_pose_motio_B.x_dx[1] =
    generate_cartesian_pose_motio_B.GetRobotState_o2[12];

  /* SignalConversion generated from: '<Root>/Mux4' */
  generate_cartesian_pose_motio_B.z_dz[0] =
    generate_cartesian_pose_motio_B.GetRobotState_o1[14];
  generate_cartesian_pose_motio_B.z_dz[1] =
    generate_cartesian_pose_motio_B.GetRobotState_o2[14];

  /* Matfile logging */
  rt_UpdateTXYLogVars(generate_cartesian_pose_moti_M->rtwLogInfo,
                      (&generate_cartesian_pose_moti_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)generate_cartesian_pose_moti_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
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

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++generate_cartesian_pose_moti_M->Timing.clockTick0)) {
    ++generate_cartesian_pose_moti_M->Timing.clockTickH0;
  }

  generate_cartesian_pose_moti_M->Timing.taskTime0 =
    generate_cartesian_pose_moti_M->Timing.clockTick0 *
    generate_cartesian_pose_moti_M->Timing.stepSize0 +
    generate_cartesian_pose_moti_M->Timing.clockTickH0 *
    generate_cartesian_pose_moti_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void generate_cartesian_pose_motion_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(generate_cartesian_pose_moti_M, -1);
  generate_cartesian_pose_moti_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    generate_cartesian_pose_moti_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(generate_cartesian_pose_moti_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(generate_cartesian_pose_moti_M->rtwLogInfo, (NULL));
    rtliSetLogT(generate_cartesian_pose_moti_M->rtwLogInfo, "tout");
    rtliSetLogX(generate_cartesian_pose_moti_M->rtwLogInfo, "");
    rtliSetLogXFinal(generate_cartesian_pose_moti_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(generate_cartesian_pose_moti_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(generate_cartesian_pose_moti_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(generate_cartesian_pose_moti_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(generate_cartesian_pose_moti_M->rtwLogInfo, 1);
    rtliSetLogY(generate_cartesian_pose_moti_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(generate_cartesian_pose_moti_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(generate_cartesian_pose_moti_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  generate_cartesian_pose_moti_M->Sizes.checksums[0] = (59220935U);
  generate_cartesian_pose_moti_M->Sizes.checksums[1] = (1357307446U);
  generate_cartesian_pose_moti_M->Sizes.checksums[2] = (1769690433U);
  generate_cartesian_pose_moti_M->Sizes.checksums[3] = (2472759501U);

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

  /* block I/O */
  (void) memset((static_cast<void *>(&generate_cartesian_pose_motio_B)), 0,
                sizeof(B_generate_cartesian_pose_mot_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&generate_cartesian_pose_moti_DW), 0,
                sizeof(DW_generate_cartesian_pose_mo_T));

  /* block instance data */
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

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(generate_cartesian_pose_moti_M->rtwLogInfo,
    0.0, rtmGetTFinal(generate_cartesian_pose_moti_M),
    generate_cartesian_pose_moti_M->Timing.stepSize0, (&rtmGetErrorStatus
    (generate_cartesian_pose_moti_M)));

  /* Start for S-Function (get_initial_robot_state): '<S1>/Get Initial Robot State' */
  {
    generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK1 = 0;
    generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK2 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  /* Start for S-Function (get_duration_period): '<S1>/Get Duration Period' */
  {
    generate_cartesian_pose_moti_DW.GetDurationPeriod_DWORK1 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  /* Start for S-Function (apply_control): '<Root>/Apply Control' */
  {
    //Flag for performing initialization in first run of main _step();
    generate_cartesian_pose_moti_DW.ApplyControl_DWORK1 = 0;
    generate_cartesian_pose_moti_DW.ApplyControl_DWORK2 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  /* Start for S-Function (get_robot_state): '<Root>/Get Robot State' */
  {
    generate_cartesian_pose_moti_DW.GetRobotState_DWORK1 = (double)
      simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
  }

  /* InitializeConditions for Sum: '<S2>/Sum' incorporates:
   *  Delay: '<S2>/Delay'
   */
  generate_cartesian_pose_moti_DW.Delay_DSTATE = 0.0;
}

/* Model terminate function */
void generate_cartesian_pose_motion_terminate(void)
{
  /* Terminate for S-Function (apply_control): '<Root>/Apply Control' */
  {
    /* S-Function Block: <Root>/Apply Control */
  }
}
