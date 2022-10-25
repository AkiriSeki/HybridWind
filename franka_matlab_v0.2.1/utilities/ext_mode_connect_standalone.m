%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function ext_mode_connect_standalone( model_name )

set_param(model_name,'SimulationMode','External');
set_param(model_name,'SimulationCommand','connect');
% set_param(model_name,'SimulationCommand', 'start');

end

