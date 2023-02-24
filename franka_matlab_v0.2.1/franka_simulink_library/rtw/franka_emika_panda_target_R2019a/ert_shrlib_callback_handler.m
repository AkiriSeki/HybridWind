function ert_shrlib_callback_handler(varargin)
%

% Copyright 2006-2013 The MathWorks, Inc.
%   
% Abstract: Set default configuration for ert_shrlib.tlc STF
  
  hDlg = varargin{1};
  hSrc = varargin{2};

  % Setup these options as desired and gray them out
  slConfigUISetVal(hDlg, hSrc, 'CreateSILPILBlock','None');
  slConfigUISetEnabled(hDlg, hSrc, 'CreateSILPILBlock','off');

  slConfigUISetVal(hDlg, hSrc, 'GRTInterface','off');
  slConfigUISetEnabled(hDlg, hSrc, 'GRTInterface','off');

%   slConfigUISetVal(hDlg, hSrc, 'TargetLang', 'C');
%   slConfigUISetEnabled(hDlg, hSrc, 'TargetLang', 'off');
  
  slConfigUISetVal(hDlg, hSrc,'TargetOS' ,'BareBoardExample');
  slConfigUISetEnabled(hDlg, hSrc,'TargetOS' ,'off');
  
  % Support model blocks
  slConfigUISetVal(hDlg, hSrc, 'ModelReferenceCompliant', 'on');
  slConfigUISetEnabled(hDlg, hSrc, 'ModelReferenceCompliant', false);
  slConfigUISetVal(hDlg, hSrc, 'ModelStepFunctionPrototypeControlCompliant', 'on');
  slConfigUISetEnabled(hDlg, hSrc, 'ModelStepFunctionPrototypeControlCompliant', false);
  
  % Default configuration
  slConfigUISetVal(hDlg, hSrc, 'ProdEqTarget', 'off');
  slConfigUISetVal(hDlg, hSrc, 'PortableWordSizes', 'off');
  slConfigUISetVal(hDlg, hSrc, 'TargetHWDeviceType', 'MATLAB Host');
  
  % this supports CompOptLevel
  slConfigUISetVal(hDlg, hSrc,'CompOptLevelCompliant' ,'on');
  slConfigUISetEnabled(hDlg, hSrc,'CompOptLevelCompliant' ,'off');
  
  
  % this supports ParMdlRefBuildCompliant
  slConfigUISetVal(hDlg, hSrc,'ParMdlRefBuildCompliant' ,'on');
  slConfigUISetEnabled(hDlg, hSrc,'ParMdlRefBuildCompliant' ,'off');

