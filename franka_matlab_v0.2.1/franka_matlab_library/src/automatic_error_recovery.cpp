//  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
//  This file is subject to the terms and conditions defined in the file
//  'LICENSE' , which is part of this package

#include <math.h>
#include <iostream>
#include "mex.h"

#include <franka/exception.h>
#include <franka/robot.h>

void mexFunction(int nlhs, mxArray* [], int nrhs, const mxArray* prhs[]) {
  if (nrhs != 1) {
    mexErrMsgIdAndTxt("MATLAB:mexcpp:nargin", "automatic error recovery requires robot's ip.");
  } else if (nlhs >= 1) {
    mexErrMsgIdAndTxt("MATLAB:mexcpp:nargout",
                      "automatic error recovery requires no output argument.");
  }

  size_t buflen = mxGetN(prhs[0]) + 1;

  char* robot_ip;
  franka::Robot* robot;
  /* Check for proper number of arguments */

  robot_ip = (char*)mxCalloc(buflen, sizeof(char));
  mxGetString(prhs[0], robot_ip, (mwSize)buflen);

  robot = new franka::Robot(robot_ip);

  try {
    robot->automaticErrorRecovery();

  } catch (const franka::Exception& e) {
    std::cout << e.what() << std::endl;
  }
  mexPrintf("\n <=== Automatic error recovery commanded on Panda %s ===> \n\n", robot_ip);
  mxFree(robot_ip);
  return;
}