# HybridWind

## Installation

### Clone the Repository (and submodules)

`git clone git@github.com:PMEC-OSU/HybridWind.git --recursive`

### Updating Submodules

If you need to pull changes from the submodules, you can use the following:

`git submodule update --recursive`

OR

`git pull --recurse-submodules`

### Build OpenFAST

```bash
cd openfast
. ../build_scripts/build_openfast.sh
```

### Build Qualisys-Matlab

Return to root directory, then:

```bash
cd qualisys-matlab
. ../build_scripts/build_matlab_qualisys.sh
```

### Ensure that MATLAB can find the dynamic library files

Open the following file:

`sudo vim /etc/ld.so.conf.d/randomLibs.conf`

Add the absolute paths to the directories containing your library files for OpenFAST and Qualisys-Matlab (replace the "path/to/repo" with your absolute path to HybridWind):

```
/path/to/repo/HybridWind/openfast/install/lib
/path/to/repo/HybridWind/qualisys-matlab/qualisys_cpp_sdk/build
```

Save the file, and run:

`sudo ldconfig`

### Compile OpenFAST SFunc

TODO

### Compile MATLAB SFunc

TODO
