#ifndef RTW_HEADER_untitled_cal_h_
#define RTW_HEADER_untitled_cal_h_
#include "rtwtypes.h"

/* Storage class 'PageSwitching', for system '<Root>' */
struct untitled_cal_type {
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Storage class 'PageSwitching' */
extern untitled_cal_type untitled_cal_impl;
extern untitled_cal_type *untitled_cal;

#endif                                 /* RTW_HEADER_untitled_cal_h_ */
