% initialization script for running robotic arm in force control
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc; clear; close all

%% Operate from here
expname = 'surgeNoise';
trialname = 'Trial02';
% tuning signal 1=chirp 2= uniform random number
tuning_signal = 4;
% x=1 y=2 z=3 rx=4 ry=5 rz=6
dof = 1;
% delay at start
init_delay = 10;
% amplitude
% x= y= z= rx= ry= rz=
amp = 0.05*100;

%% Demos variables
robot_ip = '172.16.0.2'; %place your robot's ip!

joint_impedance = [3000, 3000, 3000, 2500, 2500, 2000, 2000];
cartesian_impedance = [3000, 3000, 3000, 300, 300, 300];

EE_T_K = [1 0 0 0,...
          0 1 0 0,...
          0 0 1 0,...
          0 0 0 1];  %transformation from end effector frame to stiffness frame
      
load_inertia = [0,...  %mass
                0,0,0,... %center of mass
                0,0,0,...
                0,0,0,...
                0,0,0];   % intertia matrix
            
%% Make assignments to base workspace

assignin('base','joint_impedance',joint_impedance);
assignin('base','cartesian_impedance',cartesian_impedance);
assignin('base','EE_T_K',EE_T_K);
assignin('base','load_inertia',load_inertia);



if ~exist(['/home/HybridWind/model/data/',expname],'dir')
    mkdir(['/home/HybridWind/model/data/',expname])
end
if ~exist(['/home/HybridWind/model/data/',expname,'/',trialname],'dir')
    mkdir(['/home/HybridWind/model/data/',expname,'/',trialname])
    
end
addpath(genpath(['/home/HybridWind/model/data/',expname,'/',trialname]));
set_param('roboticArm/GammaToFile','filename',['/home/HybridWind/model/data/',expname,'/',trialname,'/gamma.mat'])
set_param('roboticArm/DeltaToFile','filename',['/home/HybridWind/model/data/',expname,'/',trialname,'/delta.mat'])
set_param('roboticArm/CommandedToFile','filename',['/home/HybridWind/model/data/',expname,'/',trialname,'/commanded.mat'])
set_param('roboticArm/ArmEstToFile','filename',['/home/HybridWind/model/data/',expname,'/',trialname,'/armest.mat'])





per = .5;

%% EFC feedback coefficients
Kd = diag([0   ; 0  ; 0.003; 0.0001; 0.00; 0.0001]);
Kp = diag([0; 1; 0.2  ; 0.05  ; 0.3 ; 0.2]);
Ki = diag([0  ; 0 ; 10   ; 10    ; 10  ; 2]);

Kd_matr = zeros(6);
Kp_matr = zeros(6);
Ki_matr = zeros(6);

Kd_matr(:,dof) = Kd(:,dof);
Kp_matr(:,dof) = Kp(:,dof);
Ki_matr(:,dof) = Ki(:,dof);


%% openfast input definition
% dfname = '5MWMarin_OC5Semi_OC5_SteadyWind2mps.mat';
% dfname = '5MWMarin_OC5Semi_OC5_SteadyWind4mps.mat';
dfname = '5MWMarin_OC5Semi_OC5_DynamicWind13mps.mat';
% dfname = '5MWMarin_OC5Semi_OC5_Static.mat';


% data = open(['/5MWMarin/',dfname]);
% data.scaled_array = data.scaled_array(11:end,:)-mean(data.scaled_array(11:end,:));
% dt = 0.1/sqrt(50);
% scaled_array = zeros(length(data.scaled_array)+10*round(1/dt),7);
% scaled_array(:,1) = 0:dt:length(scaled_array)*dt-dt;
% scaled_array(:,dof+1) = [zeros(round(5*1/dt)+1,1) ; data.scaled_array(:,dof+1); zeros(round(5*1/dt)+1,1)];

%% square wave input definition
% load('scaled_array_oc5')
% dt = 0.1/sqrt(50);
% scaled_array(:,1) = (0:dt:length(scaled_array)*dt-dt)';
% scaled_array = [scaled_array(:,1) zeros(length(scaled_array),6)];
% scaled_array(:,dof+1) = amp*sign(sin(2*pi/per*scaled_array(:,1)));
% scaled_array(1:round(5*1/dt),dof+1) = zeros(round(5*1/dt),1);
% scaled_array(:,2) = 5*ones(size(scaled_array(:,2)));

%% chirp input definition
TMax = 70;
chirp_duration = 60;
dt = 0.001;
f0 = 0.1;
f1 = 30;
t = (0:dt:chirp_duration-dt)';
y = amp*chirp(t,f0,chirp_duration,f1);
scaled_array = zeros(round((chirp_duration+10)*1./dt-1)+1,7);
scaled_array(:,1) = 0:dt:length(scaled_array)*dt-dt;
scaled_array(:,dof+1) = [zeros(round(5*1/dt),1) ; y; zeros(round(5*1/dt),1)];
