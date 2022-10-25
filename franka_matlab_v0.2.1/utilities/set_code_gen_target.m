%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function set_code_gen_target(code_gen_target)

project_root = fileparts(which('init_franka_matlab'));
save(fullfile(project_root, 'franka_matlab_configs'), 'code_gen_target','-append');

end