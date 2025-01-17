%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package
clear; clc; close all

%% Operate from here
modelname = 'lynchpark_forcecontrol_v1b';
expname = 'lynchpark_forcecontrol_v1b';
trialname = 'Trial01';

dof = 1;
amp = 0;
stoptime = inf;
init_delay = 10;
% 
% if ~exist(['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname],'dir')
%     mkdir(['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname])
% end
% if ~exist(['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname],'dir')
%     mkdir(['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname])
%     
% end
% addpath(genpath(['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname]));
% set_param('blockdiagram_3/Cartesian Impedance Controller/Force Control/tau_J_d_to_file','filename',['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname,'/tau_J_d.mat'])
% set_param('blockdiagram_3/Cartesian Impedance Controller/Force Control/tau_J_d_prime_to_file','filename',['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname,'/tau_J_d_prime.mat'])
% set_param('blockdiagram_3/Cartesian Impedance Controller/Force Control/tau_ext_to_file','filename',['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname,'/tau_ext.mat'])
% 
% set_param('blockdiagram_3/delta_to_file','filename',['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname,'/delta.mat'])
% set_param('blockdiagram_3/gamma_to_file','filename',['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname,'/gamma.mat'])
% set_param('blockdiagram_3/tau_J_to_file','filename',['/home/HybridWind/lynchpark_forcecontrol_v1/data/',expname,'/',trialname,'/tau_J.mat'])
set_param(modelname, 'StopTime', num2str(stoptime))
%% Demos variables
robot_ip = '172.16.0.2'; %place your robot's ip!

%% demos_common_configs.m values
% q_init = [0, -pi/4, 0, -3 * pi/4, 0, pi/2, pi/4];

%% HWRL basin init condition

q_init = [65*pi/128, 59*pi/512, 0, -315 * pi/512, 0, 48*pi/64, 14*pi/64];

%robotState = franka_robot_state(robot_ip);
%O_T_EE_init = robotState.O_T_EE;

% O_T_EE_init = [0.707 -0.707 -0.0  0.3071;...
%               -0.707 -0.707 -0.0 -0.0;...
%               -0.0    0.0    -1    0.59;...
%                0      0      0    1]';

% Orientation of EE frame in O frame
% This should be the upper 3x3 of O_T_EE frame at startup
R_O_EE_init = [
    0.707 -0.707 -0.0
    -0.707 -0.707 -0.0
    -0.0    0.0    -1];

% Position of EE origin in O frame
P = [
    0.3071
    -0.0
    0.59];

O_T_EE_init = [R_O_EE_init P ; 0 0 0 1];

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

load_inertia = [1.78*0.75,...  %mass
                0,0,0.02,... %center of mass
                1/3*1.78*0.065^2,0,0,...
                0,1/3*1.78*0.065^2,0,...
                0,0,0.5*1.78*0.09^2];   % intertia matrix

V_damp = diag([10 10 10 10 10 10]);

R_O_LC = [
    0.707   -0.707  0
    -0.707  -0.707  0
    0       0       -1
    ];

% From Jonah
% total dry mass (neglecting moorings) = 111.15kg
% Center of gravity distance from coordinate system 2 = 1.99980044 m 
% Moments of inertia about coordinate system 2: 
% Ixx = 489.0261 kg-m^2
% Iyy = 489.0285 kg-m^2
% Izz = 38.6910 kg-m^2
            
      
% R_O_LC
% R_O_EE
% R_LC_EE = R_LC_O*R_O_EE

% R_O_EE = [
%     0.982 0.1882 0.01857
%     0.1883 -0.9821 -0.00693
%     0.01693 0.0103 -0.9998
%     ];

R_O_EE = [
    1 0 0
    0 -1 0
    0 0 -1
    ];

R_LC_EE = R_O_LC'*R_O_EE

FR_EE_LC = [R_LC_EE' zeros(3) ; zeros(3) R_LC_EE'];



%% Make assignments to base workspace
assignin('base','q_init',q_init);
assignin('base','O_T_EE_init',O_T_EE_init);
assignin('base','collision_behavior',collision_behavior);
assignin('base','joint_impedance',joint_impedance);
assignin('base','cartesian_impedance',cartesian_impedance);
assignin('base','EE_T_K',EE_T_K);
assignin('base','F_T_EE',F_T_EE);
assignin('base','load_inertia',load_inertia);