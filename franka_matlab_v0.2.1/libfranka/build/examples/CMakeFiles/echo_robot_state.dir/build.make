# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Bosma/franka_matlab_v0.2.1/libfranka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Bosma/franka_matlab_v0.2.1/libfranka/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/echo_robot_state.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/echo_robot_state.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/echo_robot_state.dir/flags.make

examples/CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.o: examples/CMakeFiles/echo_robot_state.dir/flags.make
examples/CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.o: ../examples/echo_robot_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Bosma/franka_matlab_v0.2.1/libfranka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.o"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.o -c /home/Bosma/franka_matlab_v0.2.1/libfranka/examples/echo_robot_state.cpp

examples/CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.i"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Bosma/franka_matlab_v0.2.1/libfranka/examples/echo_robot_state.cpp > CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.i

examples/CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.s"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Bosma/franka_matlab_v0.2.1/libfranka/examples/echo_robot_state.cpp -o CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.s

# Object files for target echo_robot_state
echo_robot_state_OBJECTS = \
"CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.o"

# External object files for target echo_robot_state
echo_robot_state_EXTERNAL_OBJECTS =

examples/echo_robot_state: examples/CMakeFiles/echo_robot_state.dir/echo_robot_state.cpp.o
examples/echo_robot_state: examples/CMakeFiles/echo_robot_state.dir/build.make
examples/echo_robot_state: examples/libexamples_common.a
examples/echo_robot_state: libfranka.so.0.9.0
examples/echo_robot_state: examples/CMakeFiles/echo_robot_state.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Bosma/franka_matlab_v0.2.1/libfranka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable echo_robot_state"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echo_robot_state.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/echo_robot_state.dir/build: examples/echo_robot_state

.PHONY : examples/CMakeFiles/echo_robot_state.dir/build

examples/CMakeFiles/echo_robot_state.dir/clean:
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/echo_robot_state.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/echo_robot_state.dir/clean

examples/CMakeFiles/echo_robot_state.dir/depend:
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Bosma/franka_matlab_v0.2.1/libfranka /home/Bosma/franka_matlab_v0.2.1/libfranka/examples /home/Bosma/franka_matlab_v0.2.1/libfranka/build /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples/CMakeFiles/echo_robot_state.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/echo_robot_state.dir/depend

