%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function build_standalone(model_name,defines_opts, code_gen_target_path)

open_system(model_name,'loadonly');

project_root = fileparts(which('init_franka_matlab'));

if nargin < 3
    code_gen_target_path = fullfile(project_root, 'work');
end

set_code_gen_target_path(model_name, code_gen_target_path);

franka_matlab_configs = load('franka_matlab_configs');

if (nargin == 1)
    defines_opts = '';
else
    if strcmp(franka_matlab_configs.code_gen_target,'grt') || strcmp(franka_matlab_configs.code_gen_target,'franka_emika')
        defines_opts = ['"DEFINES_OPTS=',defines_opts,'"'];
    elseif strcmp(franka_matlab_configs.code_gen_target,'ert')
        defines_opts = ['"DEFINES_OPTS=',defines_opts,' -DRT -DUSE_RTMODEL -DERT"'];
    end
end

generated_code_path = fullfile(Simulink.fileGenControl('get', 'CacheFolder'),[model_name,'_',franka_matlab_configs.code_gen_target,'_rtw']);

cs = getActiveConfigSet(model_name);

% Code Generation General pane
cs.set_param('TargetLang', 'C++');   % Language
%     cs.set_param('BuildConfiguration', 'Faster Runs');    
%     cs.set_param('CheckMdlBeforeBuild', 'Off');   % Check model before generating code 
cs.set_param('GenCodeOnly', 'on');   % Generate code only 

save_system(model_name);

rtwbuild(model_name);

if system([fullfile(matlabroot,'bin','glnxa64','gmake '),defines_opts,' -j8 -C ',generated_code_path,' -f ',model_name,'.mk'])
    error(['Failed to build system ',model_name]);
end

end