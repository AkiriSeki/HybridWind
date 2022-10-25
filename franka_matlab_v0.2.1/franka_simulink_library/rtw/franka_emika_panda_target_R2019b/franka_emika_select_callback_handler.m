%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function franka_emika_select_callback_handler(varargin)
  % The following parameters enable toolchain compliance.
  
  hDlg = varargin{1};
  hSrc = varargin{2};
  
  slConfigUISetVal(hDlg, hSrc, 'TargetLang', 'C++');
  slConfigUISetEnabled(hDlg, hSrc, 'TargetLang', 'on');
  
  slConfigUISetVal(hDlg, hSrc, 'ProdHWDeviceType', 'Intel->x86-64 (Linux 64)');
  
  slConfigUISetVal(hDlg, hSrc, 'UseToolchainInfoCompliant', 'on');
  slConfigUISetVal(hDlg, hSrc, 'GenerateMakefile','on');
  
  slConfigUISetVal(hDlg, hSrc, 'Toolchain', 'Franka Simulink | gmake (64-bit linux)');   % Toolchain
  slConfigUISetVal(hDlg, hSrc, 'BuildConfiguration', 'Faster Runs');   % Build configuration
  
  slConfigUISetVal(hDlg, hSrc, 'DefaultParameterBehavior', 'Tunable');
  
  slConfigUISetVal(hDlg, hSrc, 'MatlabRoot', matlabroot);
  
  slConfigUISetVal(hDlg, hSrc, 'Solver', 'FixedStepDiscrete');
  slConfigUISetEnabled(hDlg, hSrc, 'Solver', true);
  slConfigUISetVal(hDlg, hSrc, 'SolverType', 'Fixed-step');
  slConfigUISetEnabled(hDlg, hSrc, 'SolverType', false);
  slConfigUISetVal(hDlg, hSrc, 'SolverType', 'Fixed-step');
  slConfigUISetVal(hDlg, hSrc, 'SampleTimeConstraint', 'Unconstrained');
  slConfigUISetVal(hDlg, hSrc, 'SolverMode', 'Auto');
  slConfigUISetVal(hDlg, hSrc, 'AutoInsertRateTranBlk', 'off');
  
  slConfigUISetVal(hDlg, hSrc, 'ERTCustomFileTemplate', 'franka_emika_panda_file_process.tlc');
  slConfigUISetEnabled(hDlg, hSrc, 'ERTCustomFileTemplate',false);
  slConfigUISetVal(hDlg, hSrc, 'GenerateSampleERTMain', 'on');
  slConfigUISetEnabled(hDlg, hSrc, 'GenerateSampleERTMain',false);
  
%   slConfigUISetVal(hDlg, hSrc, 'ExtMode', 'on');   % External mode
  if strcmp(slConfigUIGetVal(hDlg, hSrc, 'OnTargetWaitForStartPaneOption'), 'on')
    slConfigUISetVal(hDlg, hSrc, 'OnTargetWaitForStart', 'on');
  else
    slConfigUISetVal(hDlg, hSrc, 'OnTargetWaitForStart', 'off');
  end
  
  slConfigUISetVal(hDlg, hSrc, 'StartTime', '0.0');   % Start time
  slConfigUISetVal(hDlg, hSrc, 'StopTime', 'inf');   % Stop time
  slConfigUISetVal(hDlg, hSrc, 'SampleTimeConstraint', 'Unconstrained');   % Periodic sample time constraint
  slConfigUISetVal(hDlg, hSrc, 'SolverType', 'Fixed-step');   % Type
  slConfigUISetVal(hDlg, hSrc, 'FixedStep', '0.001');   % Fixed-step size (fundamental sample time)
  slConfigUISetVal(hDlg, hSrc, 'EnableMultiTasking', 'on');   % Treat each discrete rate as a separate task
  slConfigUISetVal(hDlg, hSrc, 'PositivePriorityOrder', 'off');   % Higher priority value indicates higher task priority
  slConfigUISetVal(hDlg, hSrc, 'AutoInsertRateTranBlk', 'off');   % Automatically handle rate transition for data transfer
  
%   % The following parameters are not required for toolchain compliance.
%   % But, it is recommended practice to set these default values and 
%   % disable the parameters (as shown).
%   slConfigUISetVal(hDlg, hSrc, 'RTWCompilerOptimization','off');
%   slConfigUISetVal(hDlg, hSrc, 'MakeCommand','make_rtw');
%   slConfigUISetEnabled(hDlg, hSrc, 'RTWCompilerOptimization',false);
%   slConfigUISetEnabled(hDlg, hSrc, 'MakeCommand',false);
