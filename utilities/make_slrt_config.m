function makeInfo = make_slrt_config()
%RTWMAKECFG adds include and source directories to Simulink Coder make files.
%   makeInfo=RTWMAKECFG returns a structured array containing build info.
%   Please refer to the rtwmakecfg API section in the Simulink Coder
%   Documentation for details on the format of this structure.
%

%   Copyright 2009-2010 The MathWorks, Inc.

makeInfo = lct_rtwmakecfg();

% makeInfo.linkLibsObjs = {};
% makeInfo.includePath{1} = '/home/HybridWind/openfast/install/include';
% makeInfo.linkLibsObjs{1} = '/home/HybridWind/openfast/install/lib';

makeInfo.precompile = 1;
makeInfo.library(1).Name = 'libopenfastlib';
makeInfo.library(1).Location = '/home/HybridWind/openfast/install/lib';
