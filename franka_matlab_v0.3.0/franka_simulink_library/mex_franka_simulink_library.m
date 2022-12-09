%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function mex_franka_simulink_library()

franka_simulink_library_components = {'apply_control.cpp',...
                                      'get_initial_robot_state.cpp',...
                                      'get_duration_period.cpp',...
                                      'get_model.cpp',...
                                      'get_robot_state.cpp',...
                                      'get_gripper_state.cpp'};

cellfun(@mex_sfunction,franka_simulink_library_components);

end