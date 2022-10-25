%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function install_libfranka(desired_installation_path)

if nargin == 0
    desired_installation_path = fileparts(which('init_franka_matlab'));
end

system(cding(desired_installation_path,'git clone --recursive https://github.com/frankaemika/libfranka'));
system(cding(fullfile(desired_installation_path, 'libfranka'), 'git checkout 0.9.0'));
system(cding(fullfile(desired_installation_path, 'libfranka'),'git submodule update'));
system(cding(fullfile(desired_installation_path, 'libfranka'),'mkdir build'));
system(cding(fullfile(desired_installation_path, 'libfranka','build'),'cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON ..'));
system(cding(fullfile(desired_installation_path, 'libfranka','build'),'cmake --build .'));

libfranka_path = fullfile(desired_installation_path,'libfranka');
project_root = fileparts(which('init_franka_matlab'));
code_gen_target = 'franka_emika';

if ~exist('franka_matlab_configs.mat','file')
    save(fullfile(project_root, 'franka_matlab_configs'), 'libfranka_path',...
                                                      'code_gen_target');
end

save(fullfile(project_root, 'franka_matlab_configs'), 'libfranka_path','-append');

end

function cd_string = cding(path, cmd)

cd_string = ['cd ',path,' && ',cmd];

end