%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function set_up_franka_simulink_model( model_name, ext_mode )

franka_matlab_configs = load('franka_matlab_configs');

if nargin == 1
    ext_mode = 'external_mode_off';
end

open_system(model_name,'loadonly');

cs = getActiveConfigSet(model_name);

cs = eval(['config_',franka_matlab_configs.code_gen_target,'_core( cs )']);

cs.set_param('Toolchain', 'Franka Simulink | gmake (64-bit linux)');
cs.set_param('BuildConfiguration', 'Faster Runs');
cs.set_param('ObjectivePriorities', {'Execution efficiency'});   % Prioritized

% Code Generation:Interface pane
cs.set_param('CodeInterfacePackaging', 'Nonreusable function');   % Code interface packaging 
cs.set_param('CodeReplacementLibrary', 'None');   % Code replacement library 
cs.set_param('CombineSignalStateStructs', 'off');   % Combine signal/state structures 

cs.set_param();

if strcmp(ext_mode,'external_mode_on')
    
    cs.set_param('ExtMode', 'on');   % Interface
    
    if strcmp(franka_matlab_configs.code_gen_target, 'ert') || strcmp(franka_matlab_configs.code_gen_target, 'grt')
        cs.set_param('CustomSource', [fullfile(matlabroot,'toolbox','coder','rtiostream','src','rtiostreamtcpip','rtiostream_tcpip.c '), fullfile(matlabroot,'rtw','c','src','ext_mode','common','rtiostream_interface.cpp')]); 
    end

    [~,host_ip] = system('hostname -I');
    host_ip = regexp(host_ip, '\d+\.\d+\.\d+\.\d+','match');

    host_ip = host_ip{1};
    
    cs.set_param('ExtModeMexArgs',   ['''',host_ip,''' 0 17725']);
    cs.set_param('ExtModeTransport', 0);   % Transport layer 
    cs.set_param('ExtModeStaticAlloc', 'off');   % Static memory allocation 
    
    if strcmp(franka_matlab_configs.code_gen_target, 'franka_emika')
        cs.set_param('OnTargetWaitForStartPaneOption', 'on');   % Interface
    end
    
elseif strcmp(ext_mode,'external_mode_off')
    
    cs.set_param('ExtMode', 'off');   % Interface
    
    if strcmp(franka_matlab_configs.code_gen_target, 'franka_emika')
        cs.set_param('OnTargetWaitForStartPaneOption', 'off');   % Interface
    end
    
end

% cs.set_param('TargetLangStandard', 'C89/C90 (ANSI)');   % Standard math library 
% cs.set_param('UtilityFuncGeneration', 'Auto');   % Shared code placement 

save_system(model_name);
% close_system(model_name);

end
