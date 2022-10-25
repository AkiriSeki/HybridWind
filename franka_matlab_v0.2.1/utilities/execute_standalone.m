%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function [ exit_status, exit_status_str ] = execute_standalone( model_name, code_gen_target_path, log )

franka_matlab_configs = load('franka_matlab_configs');

if nargin < 2
    code_gen_target_path = fileparts(Simulink.fileGenControl('get', 'CodeGenFolder'));
    log = false;
end

if nargin < 3
    log = false;
end

set_code_gen_target_path( model_name, code_gen_target_path );

if log
    cmd_ = [code_gen_target_path, '/', model_name, '_code_gen/', model_name , '>> ', model_name, '_fsi_log.txt &'];
else
    cmd_ = [code_gen_target_path, '/', model_name, '_code_gen/', model_name, ' &'];
end

[ exit_status, exit_status_str ] = system(['export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:',franka_matlab_configs.libfranka_path,'/build && ',cmd_]);

disp(exit_status_str);

end
