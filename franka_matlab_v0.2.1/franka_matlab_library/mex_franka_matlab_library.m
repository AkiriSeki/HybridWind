%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function mex_franka_matlab_library()

franka_matlab_library_components = {'automatic_error_recovery.cpp'};

cellfun(@mex_mxfunction,franka_matlab_library_components);

end