%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function init_franka_matlab(libfranka_path)

fprintf('--Initializing Franka Matlab\n');

%% Project Root Path
project_root = fileparts(which('init_franka_matlab'));

%% Get MATLAB version
matlab_version = regexp(version,  '[^()]*', 'match');
matlab_version = matlab_version{2};

%% Abort init if matlab_version is unsupported 
if ~(strcmp(matlab_version,'R2019a') || strcmp(matlab_version,'R2019b') || strcmp(matlab_version,'R2020a') || strcmp(matlab_version,'R2020b') || strcmp(matlab_version,'R2021a'))
    error(['Matlab version ', matlab_version, ' is not supported by franka_matlab. Currently supported versions for franka_matlab are the: R2019a, R2019b, R2020a, R2020b, R2021a']);
end

%% Add subfolders
addpath(fullfile(project_root, 'demos'));
addpath(fullfile(project_root, fullfile('demos',['MATLAB_',matlab_version])));
addpath(genpath(fullfile(project_root, 'franka_matlab_library')));
addpath(fullfile(project_root, 'franka_simulink_library'));
addpath(fullfile(project_root, 'franka_simulink_library','blocks'));
addpath(fullfile(project_root, 'franka_simulink_library','src'));
addpath(fullfile(project_root, 'franka_simulink_library','rtw'));
addpath(fullfile(project_root, 'franka_simulink_library','rtw','franka_emika_panda_target_64_linux'));
addpath(fullfile(project_root, fullfile('franka_simulink_library','rtw',['franka_emika_panda_target_',matlab_version])));
addpath(fullfile(project_root, 'utilities'));
addpath(fullfile(project_root, fullfile('utilities',['configs_',matlab_version])));

%% Save configs to mat file
if nargin == 0
    libfranka_path = fullfile(project_root,'libfranka');
end

code_gen_target = 'franka_emika';
% code_gen_target = 'ert';
% code_gen_target = 'grt';

if ~exist('franka_matlab_configs.mat','file')
    save(fullfile(project_root, 'franka_matlab_configs'), 'libfranka_path',...
                                                      'code_gen_target', 'matlab_version');
else
    save(fullfile(project_root, 'franka_matlab_configs'), 'libfranka_path',...
                                                          'code_gen_target', 'matlab_version', '-append');
end
%% Set Local Environment
set_local_environment();

%% Refresh customizations
sl_refresh_customizations();

%% Quick evaluation of the situation of libfranka path provided
if ~exist(fullfile(libfranka_path,'build','libfranka.so'),'file') ||...
     ~exist(fullfile(libfranka_path,'build','examples','libexamples_common.a'),'file')
     prompt = [newline, 'libfranka installation seems invalid, either install manually (see https://frankaemika.github.io/docs/)',newline,...
               'and hit init_franka_matlab(libfranka path) again',newline,...
               'or try installing automatically(Y):',newline,newline,...
               '!! Important !! ==================================================================== !! Important !!',newline,...
               '!! Important !! Make sure you managed dependencies in a terminal BEFORE installation !! Important !!',newline,...
               '!! Important !! ==================================================================== !! Important !!',newline,...
               ' --> sudo apt remove "*libfranka*"',newline,...
               ' --> sudo apt install build-essential cmake git libpoco-dev libeigen3-dev',newline,...
               '!! Important !! ==================================================================== !! Important !!',newline,newline,...
               'install libfranka now(Y)||skip installation(n):',newline,newline];
 
    str = input(prompt,'s');
    
    if (strcmp(str,'Y') || strcmp(str,'y'))
        
        install_libfranka();
        
    else
        
        error('libfranka not properly installed, please manage installation (see https://frankaemika.github.io/docs/) and run init_franka_matlab_again(libfranka_local_installation_path) again');
        
    end
    
end

%% Init Toolchain
init_franka_simulink_64_linux_tc();

end