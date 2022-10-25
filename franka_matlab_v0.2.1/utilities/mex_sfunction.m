%  Copyright (c) 2020 Franka Emika GmbH - All Rights Reserved
%  This file is subject to the terms and conditions defined in the file
%  'LICENSE' , which is part of this package

function mex_sfunction(src)

src_full_path = which(src);
src_full_home_path = fileparts(src_full_path);

warnStruct = warning('off', 'MATLAB:mex:GccVersion_link');

project_root = fileparts(which('init_franka_matlab'));
franka_matlab_configs = load('franka_matlab_configs');
libfranka_path = franka_matlab_configs.libfranka_path;

[~,eigen3Path] = system(['cd ',project_root, '&& cmake --find-package -DNAME=Eigen3 -DCOMPILER_ID=GNU -DLANGUAGE=C -DMODE=COMPILE']);
eigen3Path = strip(strrep(eigen3Path,'-I',''));

if exist(fullfile(project_root,'CMakeFiles'),'dir')
rmdir(fullfile(project_root,'CMakeFiles'),'s');
end

disp([newline,'<=== Mexing ',src,' ===>',newline]);
mex_string = ['mex  CXXFLAGS=''-fPIC -O3 -fno-loop-optimize -std=c++14 -Wno-format-overflow'' ', ...
                   'LINKLIBS='' -Wl,-rpath,',matlabroot,'/bin/glnxa64 -Wl,-rpath ',libfranka_path,'/build -L"',matlabroot,'/bin/glnxa64" -L"',libfranka_path,'/build" -L"',libfranka_path,'/build/examples" -lfranka -lexamples_common -lPocoNet -lPocoFoundation -lPocoUtil -lmx -lmex -lmat -lm -lstdc++'' ', ...
                   '-I"',libfranka_path,'/build/" ',...
                   '-I"',libfranka_path,'/include/" ',...
                   '-I"',libfranka_path,'/examples/" ',...
                   '-I"',libfranka_path,'/common/include/" ',...
                   '-I"',libfranka_path,'/src/" ',...
                   '-I"',src_full_home_path,'/" ',...
                   '-I"',eigen3Path,'" ',...
                   src_full_home_path,'/',src,' ',...
                   '-outdir ',src_full_home_path,'/'];
               
evalin('base',mex_string);
warning(warnStruct);
end