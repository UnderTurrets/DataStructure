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
CMAKE_SOURCE_DIR = /home/xu736946693/Desktop/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xu736946693/Desktop/DataStructure/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/main.dir/flags.make

bin/CMakeFiles/main.dir/main.cpp.o: bin/CMakeFiles/main.dir/flags.make
bin/CMakeFiles/main.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/main.dir/main.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/main.cpp

bin/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

bin/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/main: bin/CMakeFiles/main.dir/main.cpp.o
bin/main: bin/CMakeFiles/main.dir/build.make
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_img_hash.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: /usr/local/lib/libopencv_world.so.4.6.0
bin/main: bin/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xu736946693/Desktop/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	cd /home/xu736946693/Desktop/DataStructure/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/main.dir/build: bin/main

.PHONY : bin/CMakeFiles/main.dir/build

bin/CMakeFiles/main.dir/clean:
	cd /home/xu736946693/Desktop/DataStructure/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/main.dir/clean

bin/CMakeFiles/main.dir/depend:
	cd /home/xu736946693/Desktop/DataStructure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xu736946693/Desktop/DataStructure /home/xu736946693/Desktop/DataStructure/src /home/xu736946693/Desktop/DataStructure/build /home/xu736946693/Desktop/DataStructure/build/bin /home/xu736946693/Desktop/DataStructure/build/bin/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/main.dir/depend
