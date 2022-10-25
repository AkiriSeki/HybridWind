%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function set_code_gen_target_path(model_name, code_gen_target_path )

cacheFolder = fullfile(code_gen_target_path,[model_name,'_code_gen']);
if ~exist(cacheFolder, 'dir')
    mkdir(cacheFolder);
end
addpath(genpath(code_gen_target_path));
Simulink.fileGenControl('set', 'CacheFolder', cacheFolder, ...
    'CodeGenFolder', cacheFolder);

project_root = fileparts(which('init_franka_matlab'));
save(fullfile(project_root, 'franka_matlab_configs'), 'code_gen_target_path','-append');


end