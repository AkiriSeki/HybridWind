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
include examples/CMakeFiles/grasp_object.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/grasp_object.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/grasp_object.dir/flags.make

examples/CMakeFiles/grasp_object.dir/grasp_object.cpp.o: examples/CMakeFiles/grasp_object.dir/flags.make
examples/CMakeFiles/grasp_object.dir/grasp_object.cpp.o: ../examples/grasp_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Bosma/franka_matlab_v0.2.1/libfranka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/grasp_object.dir/grasp_object.cpp.o"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grasp_object.dir/grasp_object.cpp.o -c /home/Bosma/franka_matlab_v0.2.1/libfranka/examples/grasp_object.cpp

examples/CMakeFiles/grasp_object.dir/grasp_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grasp_object.dir/grasp_object.cpp.i"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Bosma/franka_matlab_v0.2.1/libfranka/examples/grasp_object.cpp > CMakeFiles/grasp_object.dir/grasp_object.cpp.i

examples/CMakeFiles/grasp_object.dir/grasp_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grasp_object.dir/grasp_object.cpp.s"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Bosma/franka_matlab_v0.2.1/libfranka/examples/grasp_object.cpp -o CMakeFiles/grasp_object.dir/grasp_object.cpp.s

# Object files for target grasp_object
grasp_object_OBJECTS = \
"CMakeFiles/grasp_object.dir/grasp_object.cpp.o"

# External object files for target grasp_object
grasp_object_EXTERNAL_OBJECTS =

examples/grasp_object: examples/CMakeFiles/grasp_object.dir/grasp_object.cpp.o
examples/grasp_object: examples/CMakeFiles/grasp_object.dir/build.make
examples/grasp_object: examples/libexamples_common.a
examples/grasp_object: libfranka.so.0.9.0
examples/grasp_object: examples/CMakeFiles/grasp_object.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Bosma/franka_matlab_v0.2.1/libfranka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable grasp_object"
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grasp_object.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/grasp_object.dir/build: examples/grasp_object

.PHONY : examples/CMakeFiles/grasp_object.dir/build

examples/CMakeFiles/grasp_object.dir/clean:
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/grasp_object.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/grasp_object.dir/clean

examples/CMakeFiles/grasp_object.dir/depend:
	cd /home/Bosma/franka_matlab_v0.2.1/libfranka/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Bosma/franka_matlab_v0.2.1/libfranka /home/Bosma/franka_matlab_v0.2.1/libfranka/examples /home/Bosma/franka_matlab_v0.2.1/libfranka/build /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples /home/Bosma/franka_matlab_v0.2.1/libfranka/build/examples/CMakeFiles/grasp_object.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/grasp_object.dir/depend
