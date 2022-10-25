%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

% mexing libs
mex_franka_matlab_library();
mex_franka_simulink_library();

% building all demos with all possible supported targets, with and without
% ext mode.
demos = {'cartesian_impedance_control',...
         'echo_robot_state',...
         'force_control',...
         'generate_cartesian_pose_motion',...
         'generate_cartesian_velocity_motion',...
         'generate_elbow_motion',...
         'generate_joint_position_motion',...
         'generate_joint_velocity_motion',...
         'grasp_object',...
         'motion_with_control'};

targets = {'ert','grt','franka_emika','franka_emika_shrlib'};

for j=1:length(targets)

    set_code_gen_target(targets{j});
    
    for i=1:length(demos)
        set_up_franka_simulink_model(demos{i});
        build_standalone(demos{i});
        bdclose all;
    end

    for i=1:length(demos)
        set_up_franka_simulink_model(demos{i},'external_mode_on');
        if strcmp(targets{j},'franka_emika') || strcmp(targets{j},'franka_emika_shrlib')
            build_standalone(demos{i});
        else
            build_standalone(demos{i},'-DON_TARGET_WAIT_FOR_START=1');
        end
        bdclose all;
    end
    
end