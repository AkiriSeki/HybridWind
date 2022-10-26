###########################################################################
## Makefile generated for component 'roboticArm_loadCell'. 
## 
## Makefile     : roboticArm_loadCell.mk
## Generated on : Wed Oct 26 09:12:46 2022
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/roboticArm_loadCell
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = roboticArm_loadCell
MAKEFILE                  = roboticArm_loadCell.mk
MATLAB_ROOT               = /usr/local/MATLAB/R2021a
MATLAB_BIN                = /usr/local/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /home/HybridWind/franka_matlab_v0.2.1/work/roboticArm_loadCell_code_gen
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Franka Simulink | gmake (64-bit linux)
# Supported Version(s):    4.4.x
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ANSI_OPTS
# CPP_ANSI_OPTS

#-----------
# MACROS
#-----------

MW_BIN_DIR                 = $(MATLAB_ROOT)/bin/glnxa64
CPP_17_OPTS                = -std=c++17
FRANKA_INCLUDE_DIRECTORIES = -I/home/HybridWind/franka_matlab_v0.2.1/libfranka/include -I/home/HybridWind/franka_matlab_v0.2.1/libfranka/examples -I/home/HybridWind/franka_matlab_v0.2.1/libfranka/common/include -I/home/HybridWind/franka_matlab_v0.2.1/libfranka/src -I/home/HybridWind/franka_matlab_v0.2.1/libfranka/build -I/home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src -I/home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/blocks -I/usr/local/MATLAB/R2021a/toolbox/coder/rtiostream/src -I/usr/local/MATLAB/R2021a/toolbox/coder/rtiostream/src/utils -I/usr/include/eigen3

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = /home/HybridWind/franka_matlab_v0.2.1/libfranka/build/examples/libexamples_common.a /home/HybridWind/franka_matlab_v0.2.1/libfranka/build/libfranka.so -lPocoNet -lPocoFoundation -lPocoUtil -lmx -lmex -lmat -lm -lstdc++ -lpthread

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = gcc

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = gcc

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =



#---------------------------
# Model-Specific Options
#---------------------------

CFLAGS = -c -fPIC $(ANSI_OPTS) $(FRANKA_INCLUDE_DIRECTORIES) -O0

LDFLAGS = -Wl,-rpath,"$(MW_BIN_DIR)",-L"$(MW_BIN_DIR)",-lm,--no-as-needed,-ldl

SHAREDLIB_LDFLAGS = -shared -Wl,-rpath,"$(MW_BIN_DIR)",-L"$(MW_BIN_DIR)",-lm,--no-as-needed,-ldl

CPPFLAGS = -c -fPIC $(CPP_17_OPTS) $(FRANKA_INCLUDE_DIRECTORIES) -O0

CPP_LDFLAGS = -Wl,-rpath,"$(MW_BIN_DIR)",-L"$(MW_BIN_DIR)",-lm,--no-as-needed,-ldl

CPP_SHAREDLIB_LDFLAGS = -shared -Wl,-rpath,"$(MW_BIN_DIR)",-L"$(MW_BIN_DIR)",-lm,--no-as-needed,-ldl

ARFLAGS = ruvs

DOWNLOAD_FLAGS = -f $(MAKEFILE) download

EXECUTE_FLAGS = -f $(MAKEFILE) execute

MAKE_FLAGS = -f $(MAKEFILE)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/roboticArm_loadCell
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/include -I$(START_DIR)/roboticArm_loadCell_franka_emika_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=roboticArm_loadCell -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_Network.c $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_rtw.c $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtiostream_interface.c $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtiostream_tcpip.c $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/roboticArm_loadCell.cpp $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/roboticArm_loadCell_data.cpp $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtGetInf.cpp $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtGetNaN.cpp $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rt_nonfinite.cpp $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/sizes_codegen.cpp /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/gripper_api.cpp /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/robot_api.cpp /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/control_modes.cpp

MAIN_SRC = $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/ert_main.cpp

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = DAHostLib_Network.o DAHostLib_rtw.o rtiostream_interface.o rtiostream_tcpip.o roboticArm_loadCell.o roboticArm_loadCell_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o ext_svr.o updown.o ext_work.o rtiostream_utils.o sizes_codegen.o gripper_api.o robot_api.o control_modes.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/blocks/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/blocks/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


DAHostLib_Network.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_Network.c
	$(CC) $(CFLAGS) -o"$@" "$<"


DAHostLib_rtw.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_rtw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtiostream_interface.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtiostream_interface.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtiostream_tcpip.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtiostream_tcpip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ert_main.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/ert_main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


roboticArm_loadCell.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/roboticArm_loadCell.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


roboticArm_loadCell_data.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/roboticArm_loadCell_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/roboticArm_loadCell_franka_emika_rtw/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ext_svr.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c
	$(CC) $(CFLAGS) -o"$@" "$<"


updown.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ext_work.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtiostream_utils.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) $(CFLAGS) -o"$@" "$<"


sizes_codegen.o : /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/sizes_codegen.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gripper_api.o : /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/gripper_api.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


robot_api.o : /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/robot_api.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


control_modes.o : /home/HybridWind/franka_matlab_v0.2.1/franka_simulink_library/src/control_modes.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


