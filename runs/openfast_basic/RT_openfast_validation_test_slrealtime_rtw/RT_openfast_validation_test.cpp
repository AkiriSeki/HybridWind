/*
 * RT_openfast_validation_test.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RT_openfast_validation_test".
 *
 * Model version              : 24.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Thu Nov 17 16:01:25 2022
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RT_openfast_validation_test.h"
#include "RT_openfast_validation_test_cal.h"
#include "RT_openfast_validation_test_private.h"
#include <cstring>

extern "C"
{

#include "rt_nonfinite.h"

}

/* Block signals (default storage) */
B_RT_openfast_validation_test_T RT_openfast_validation_test_B;

/* Block states (default storage) */
DW_RT_openfast_validation_test_T RT_openfast_validation_test_DW;

/* Real-time model */
RT_MODEL_RT_openfast_validation_test_T RT_openfast_validation_test_M_ =
  RT_MODEL_RT_openfast_validation_test_T();
RT_MODEL_RT_openfast_validation_test_T *const RT_openfast_validation_test_M =
  &RT_openfast_validation_test_M_;

/* Model step function */
void RT_openfast_validation_test_step(void)
{
  /* Clock: '<Root>/Clock' */
  RT_openfast_validation_test_B.Clock = RT_openfast_validation_test_M->Timing.t
    [0];

  /* S-Function (FAST_SFunc): '<S1>/S-Function1' */

  /* Level2 S-Function Block: '<S1>/S-Function1' (FAST_SFunc) */
  {
    SimStruct *rts = RT_openfast_validation_test_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Constant' */
  RT_openfast_validation_test_B.in_surgedisp =
    RT_openfast_validation_test_cal->Constant_Value;

  /* Constant: '<Root>/Constant1' */
  RT_openfast_validation_test_B.in_swaydisp =
    RT_openfast_validation_test_cal->Constant1_Value;

  /* Constant: '<Root>/Constant10' */
  RT_openfast_validation_test_B.in_pitchvel =
    RT_openfast_validation_test_cal->Constant10_Value;

  /* Constant: '<Root>/Constant11' */
  RT_openfast_validation_test_B.in_yawvel =
    RT_openfast_validation_test_cal->Constant11_Value;

  /* Constant: '<Root>/Constant2' */
  RT_openfast_validation_test_B.in_heavedisp =
    RT_openfast_validation_test_cal->Constant2_Value;

  /* Constant: '<Root>/Constant3' */
  RT_openfast_validation_test_B.in_rolldisp =
    RT_openfast_validation_test_cal->Constant3_Value;

  /* Constant: '<Root>/Constant4' */
  RT_openfast_validation_test_B.in_pitchdisp =
    RT_openfast_validation_test_cal->Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  RT_openfast_validation_test_B.in_yawdisp =
    RT_openfast_validation_test_cal->Constant5_Value;

  /* Constant: '<Root>/Constant6' */
  RT_openfast_validation_test_B.in_surgevel =
    RT_openfast_validation_test_cal->Constant6_Value;

  /* Constant: '<Root>/Constant7' */
  RT_openfast_validation_test_B.in_swayvel =
    RT_openfast_validation_test_cal->Constant7_Value;

  /* Constant: '<Root>/Constant8' */
  RT_openfast_validation_test_B.in_heavevel =
    RT_openfast_validation_test_cal->Constant8_Value;

  /* Constant: '<Root>/Constant9' */
  RT_openfast_validation_test_B.in_rollvel =
    RT_openfast_validation_test_cal->Constant9_Value;

  /* Update for S-Function (FAST_SFunc): '<S1>/S-Function1' */
  /* Level2 S-Function Block: '<S1>/S-Function1' (FAST_SFunc) */
  {
    SimStruct *rts = RT_openfast_validation_test_M->childSfunctions[0];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
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
  if (!(++RT_openfast_validation_test_M->Timing.clockTick0)) {
    ++RT_openfast_validation_test_M->Timing.clockTickH0;
  }

  RT_openfast_validation_test_M->Timing.t[0] =
    RT_openfast_validation_test_M->Timing.clockTick0 *
    RT_openfast_validation_test_M->Timing.stepSize0 +
    RT_openfast_validation_test_M->Timing.clockTickH0 *
    RT_openfast_validation_test_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++RT_openfast_validation_test_M->Timing.clockTick1)) {
      ++RT_openfast_validation_test_M->Timing.clockTickH1;
    }

    RT_openfast_validation_test_M->Timing.t[1] =
      RT_openfast_validation_test_M->Timing.clockTick1 *
      RT_openfast_validation_test_M->Timing.stepSize1 +
      RT_openfast_validation_test_M->Timing.clockTickH1 *
      RT_openfast_validation_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void RT_openfast_validation_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RT_openfast_validation_test_M->solverInfo,
                          &RT_openfast_validation_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&RT_openfast_validation_test_M->solverInfo, &rtmGetTPtr
                (RT_openfast_validation_test_M));
    rtsiSetStepSizePtr(&RT_openfast_validation_test_M->solverInfo,
                       &RT_openfast_validation_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&RT_openfast_validation_test_M->solverInfo,
                          (&rtmGetErrorStatus(RT_openfast_validation_test_M)));
    rtsiSetRTModelPtr(&RT_openfast_validation_test_M->solverInfo,
                      RT_openfast_validation_test_M);
  }

  rtsiSetSimTimeStep(&RT_openfast_validation_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&RT_openfast_validation_test_M->solverInfo,
                    "FixedStepDiscrete");
  RT_openfast_validation_test_M->solverInfoPtr =
    (&RT_openfast_validation_test_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      RT_openfast_validation_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "RT_openfast_validation_test_M points to
       static memory which is guaranteed to be non-NULL" */
    RT_openfast_validation_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RT_openfast_validation_test_M->Timing.sampleTimes =
      (&RT_openfast_validation_test_M->Timing.sampleTimesArray[0]);
    RT_openfast_validation_test_M->Timing.offsetTimes =
      (&RT_openfast_validation_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RT_openfast_validation_test_M->Timing.sampleTimes[0] = (0.0);
    RT_openfast_validation_test_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    RT_openfast_validation_test_M->Timing.offsetTimes[0] = (0.0);
    RT_openfast_validation_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(RT_openfast_validation_test_M,
             &RT_openfast_validation_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RT_openfast_validation_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    RT_openfast_validation_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RT_openfast_validation_test_M, -1);
  RT_openfast_validation_test_M->Timing.stepSize0 = 0.01;
  RT_openfast_validation_test_M->Timing.stepSize1 = 0.01;
  RT_openfast_validation_test_M->solverInfoPtr =
    (&RT_openfast_validation_test_M->solverInfo);
  RT_openfast_validation_test_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&RT_openfast_validation_test_M->solverInfo, 0.01);
  rtsiSetSolverMode(&RT_openfast_validation_test_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) std::memset((static_cast<void *>(&RT_openfast_validation_test_B)), 0,
                     sizeof(B_RT_openfast_validation_test_T));

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&RT_openfast_validation_test_DW), 0,
                     sizeof(DW_RT_openfast_validation_test_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &RT_openfast_validation_test_M->NonInlinedSFcns.sfcnInfo;
    RT_openfast_validation_test_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (RT_openfast_validation_test_M)));
    RT_openfast_validation_test_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &RT_openfast_validation_test_M->Sizes.numSampTimes);
    RT_openfast_validation_test_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(RT_openfast_validation_test_M)[0]);
    RT_openfast_validation_test_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(RT_openfast_validation_test_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   RT_openfast_validation_test_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RT_openfast_validation_test_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RT_openfast_validation_test_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (RT_openfast_validation_test_M));
    rtssSetStepSizePtr(sfcnInfo, &RT_openfast_validation_test_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (RT_openfast_validation_test_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &RT_openfast_validation_test_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &RT_openfast_validation_test_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &RT_openfast_validation_test_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &RT_openfast_validation_test_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &RT_openfast_validation_test_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RT_openfast_validation_test_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RT_openfast_validation_test_M->solverInfoPtr);
  }

  RT_openfast_validation_test_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) std::memset(static_cast<void *>
                       (&RT_openfast_validation_test_M->NonInlinedSFcns.childSFunctions
                        [0]), 0,
                       1*sizeof(SimStruct));
    RT_openfast_validation_test_M->childSfunctions =
      (&RT_openfast_validation_test_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    RT_openfast_validation_test_M->childSfunctions[0] =
      (&RT_openfast_validation_test_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: RT_openfast_validation_test/<S1>/S-Function1 (FAST_SFunc) */
    {
      SimStruct *rts = RT_openfast_validation_test_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &RT_openfast_validation_test_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RT_openfast_validation_test_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RT_openfast_validation_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &RT_openfast_validation_test_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &RT_openfast_validation_test_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &RT_openfast_validation_test_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &RT_openfast_validation_test_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &RT_openfast_validation_test_B.in_surgedisp;
          sfcnUPtrs[1] = &RT_openfast_validation_test_B.in_swaydisp;
          sfcnUPtrs[2] = &RT_openfast_validation_test_B.in_heavedisp;
          sfcnUPtrs[3] = &RT_openfast_validation_test_B.in_rolldisp;
          sfcnUPtrs[4] = &RT_openfast_validation_test_B.in_pitchdisp;
          sfcnUPtrs[5] = &RT_openfast_validation_test_B.in_yawdisp;
          sfcnUPtrs[6] = &RT_openfast_validation_test_B.in_surgevel;
          sfcnUPtrs[7] = &RT_openfast_validation_test_B.in_swayvel;
          sfcnUPtrs[8] = &RT_openfast_validation_test_B.in_heavevel;
          sfcnUPtrs[9] = &RT_openfast_validation_test_B.in_rollvel;
          sfcnUPtrs[10] = &RT_openfast_validation_test_B.in_pitchvel;
          sfcnUPtrs[11] = &RT_openfast_validation_test_B.in_yawvel;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 12);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 88);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            RT_openfast_validation_test_B.SFunction1));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "RT_openfast_validation_test/FAST Nonlinear Wind Turbine/S-Function1");
      ssSetRTModel(rts,RT_openfast_validation_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RT_openfast_validation_test_cal->SFunction1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RT_openfast_validation_test_cal->SFunction1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       RT_openfast_validation_test_cal->SFunction1_P3_Size);
      }

      /* work vectors */
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RT_openfast_validation_test_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* DWORK1 */
        ssSetDWorkWidthAsInt(rts, 0, 88);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RT_openfast_validation_test_DW.SFunction1_DWORK1[0]);

        /* DWORK2 */
        ssSetDWorkWidthAsInt(rts, 1, 12);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &RT_openfast_validation_test_DW.SFunction1_DWORK2[0]);
      }

      /* registration */
      FAST_SFunc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for S-Function (FAST_SFunc): '<S1>/S-Function1' */
  /* Level2 S-Function Block: '<S1>/S-Function1' (FAST_SFunc) */
  {
    SimStruct *rts = RT_openfast_validation_test_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant' */
  RT_openfast_validation_test_B.in_surgedisp =
    RT_openfast_validation_test_cal->Constant_Value;

  /* Start for Constant: '<Root>/Constant1' */
  RT_openfast_validation_test_B.in_swaydisp =
    RT_openfast_validation_test_cal->Constant1_Value;

  /* Start for Constant: '<Root>/Constant10' */
  RT_openfast_validation_test_B.in_pitchvel =
    RT_openfast_validation_test_cal->Constant10_Value;

  /* Start for Constant: '<Root>/Constant11' */
  RT_openfast_validation_test_B.in_yawvel =
    RT_openfast_validation_test_cal->Constant11_Value;

  /* Start for Constant: '<Root>/Constant2' */
  RT_openfast_validation_test_B.in_heavedisp =
    RT_openfast_validation_test_cal->Constant2_Value;

  /* Start for Constant: '<Root>/Constant3' */
  RT_openfast_validation_test_B.in_rolldisp =
    RT_openfast_validation_test_cal->Constant3_Value;

  /* Start for Constant: '<Root>/Constant4' */
  RT_openfast_validation_test_B.in_pitchdisp =
    RT_openfast_validation_test_cal->Constant4_Value;

  /* Start for Constant: '<Root>/Constant5' */
  RT_openfast_validation_test_B.in_yawdisp =
    RT_openfast_validation_test_cal->Constant5_Value;

  /* Start for Constant: '<Root>/Constant6' */
  RT_openfast_validation_test_B.in_surgevel =
    RT_openfast_validation_test_cal->Constant6_Value;

  /* Start for Constant: '<Root>/Constant7' */
  RT_openfast_validation_test_B.in_swayvel =
    RT_openfast_validation_test_cal->Constant7_Value;

  /* Start for Constant: '<Root>/Constant8' */
  RT_openfast_validation_test_B.in_heavevel =
    RT_openfast_validation_test_cal->Constant8_Value;

  /* Start for Constant: '<Root>/Constant9' */
  RT_openfast_validation_test_B.in_rollvel =
    RT_openfast_validation_test_cal->Constant9_Value;
}

/* Model terminate function */
void RT_openfast_validation_test_terminate(void)
{
  /* Terminate for S-Function (FAST_SFunc): '<S1>/S-Function1' */
  /* Level2 S-Function Block: '<S1>/S-Function1' (FAST_SFunc) */
  {
    SimStruct *rts = RT_openfast_validation_test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
