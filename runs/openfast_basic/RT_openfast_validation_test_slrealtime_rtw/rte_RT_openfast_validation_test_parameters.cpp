#include "rte_RT_openfast_validation_test_parameters.h"
#include "RT_openfast_validation_test.h"
#include "RT_openfast_validation_test_cal.h"

extern RT_openfast_validation_cal_type RT_openfast_validation_cal_impl;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    { (void*)&RT_openfast_validation_cal_impl, (void**)
      &RT_openfast_validation_test_cal, sizeof(RT_openfast_validation_cal_type),
      2 }
  };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
