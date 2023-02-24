%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function build_run_connect(model_name)

%%
set_up_franka_simulink_model( model_name, 'external_mode_on' );
build_standalone(model_name,'-DON_TARGET_WAIT_FOR_START=1');

%%
kill_standalone( model_name );
pause(1);
execute_standalone( model_name );
pause(1);

%%
ext_mode_connect_standalone( model_name );

end