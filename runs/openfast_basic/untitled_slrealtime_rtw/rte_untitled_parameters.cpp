#include "rte_untitled_parameters.h"
#include "untitled.h"
#include "untitled_cal.h"

extern untitled_cal_type untitled_cal_impl;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    { (void*)&untitled_cal_impl, (void**)&untitled_cal, sizeof(untitled_cal_type),
      2 }
  };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
