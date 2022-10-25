%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function kill_standalone( model_name )

system(['pkill -f ',model_name],'-echo');

end

