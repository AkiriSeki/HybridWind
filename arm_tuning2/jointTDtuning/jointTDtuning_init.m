%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package
clear; clc; close all

%% Operate from here
modelname = 'jointTDtuning';
expname = 'jointTDtuning';
trialname = 'Trial01';

dof = 1;
amp = 0;
stoptime = inf;
init_delay = 10;

if ~exist(['/home/HybridWind/arm_tuning/data/',expname],'dir')
    mkdir(['/home/HybridWind/arm_tuning/data/',expname])
end
if ~exist(['/home/HybridWind/arm_tuning/data/',expname,'/',trialname],'dir')
    mkdir(['/home/HybridWind/arm_tuning/data/',expname,'/',trialname])
    
end
addpath(genpath(['/home/HybridWind/arm_tuning/data/',expname,'/',trialname]));
% set_param('blockdiagram_3/Cartesian Impedance Controller/Force Control/tau_J_d_to_file','filename',['/home/HybridWind/arm_tuning/data/',expname,'/',trialname,'/tau_J_d.mat'])
% set_param('blockdiagram_3/Cartesian Impedance Controller/Force Control/tau_J_d_prime_to_file','filename',['/home/HybridWind/arm_tuning/data/',expname,'/',trialname,'/tau_J_d_prime.mat'])
% set_param('blockdiagram_3/Cartesian Impedance Controller/Force Control/tau_ext_to_file','filename',['/home/HybridWind/arm_tuning/data/',expname,'/',trialname,'/tau_ext.mat'])
% 
% set_param('blockdiagram_3/delta_to_file','filename',['/home/HybridWind/arm_tuning/data/',expname,'/',trialname,'/delta.mat'])
% set_param('blockdiagram_3/gamma_to_file','filename',['/home/HybridWind/arm_tuning/data/',expname,'/',trialname,'/gamma.mat'])
% set_param('blockdiagram_3/tau_J_to_file','filename',['/home/HybridWind/arm_tuning/data/',expname,'/',trialname,'/tau_J.mat'])
set_param(modelname, 'StopTime', num2str(stoptime))
%% Demos variables
robot_ip = '172.16.0.2'; %place your robot's ip!

%% demos_common_configs.m values
% q_init = [0, -pi/4, 0, -3 * pi/4, 0, pi/2, pi/4];

%% HWRL basin init condition

q_init = [65*pi/128, 59*pi/512, 0, -315 * pi/512, 0, 48*pi/64, 14*pi/64];

O_T_EE_init = [0.707 -0.707 -0.0  0.3071;...
              -0.707 -0.707 -0.0 -0.0;...
              -0.0    0.0    -1    0.59;...
               0      0      0    1]';

collision_behavior = ... 
            [20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0,... % lower_torque_thresholds_acceleration
             20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0,... % upper_torque_thresholds_acceleration
             20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0,... % lower_torque_thresholds_nominal
             20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0,... % upper_torque_thresholds_nominal
             20.0, 20.0, 20.0, 25.0, 25.0, 25.0,...       % lower_force_thresholds_acceleration	
             20.0, 20.0, 20.0, 25.0, 25.0, 25.0,...       % upper_force_thresholds_acceleration
             20.0, 20.0, 20.0, 25.0, 25.0, 25.0,...       % lower_force_thresholds_nominal
             20.0, 20.0, 20.0, 25.0, 25.0, 25.0];         % upper_force_thresholds_nominal

joint_impedance = [3000, 3000, 3000, 2500, 2500, 2000, 2000];
cartesian_impedance = [3000, 3000, 3000, 300, 300, 300];

EE_T_K = [1 0 0 0,...
          0 1 0 0,...
          0 0 1 0,...
          0 0 0 1];  %transformation from end effector frame to stiffness frame
      
F_T_EE =  [1 0 0 0,...
           0 1 0 0,...
           0 0 1 0,...
           0 0 0 1];  %transformation from flange to end effector frame

load_inertia = [0,...  %mass
                0,0,0,... %center of mass
                0.01,0,0,...
                0,0.01,0,...
                0,0,0.01];   % intertia matrix
            
%% Make assignments to base workspace
assignin('base','q_init',q_init);
assignin('base','O_T_EE_init',O_T_EE_init);
assignin('base','collision_behavior',collision_behavior);
assignin('base','joint_impedance',joint_impedance);
assignin('base','cartesian_impedance',cartesian_impedance);
assignin('base','EE_T_K',EE_T_K);
assignin('base','F_T_EE',F_T_EE);
assignin('base','load_inertia',load_inertia);