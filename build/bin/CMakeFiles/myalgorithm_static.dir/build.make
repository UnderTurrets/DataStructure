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
CMAKE_SOURCE_DIR = /home/xu/Desktop/myAlgorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xu/Desktop/myAlgorithm/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/myalgorithm_static.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/myalgorithm_static.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/myalgorithm_static.dir/flags.make

bin/CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.o: bin/CMakeFiles/myalgorithm_static.dir/flags.make
bin/CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.o: ../lib/myalgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu/Desktop/myAlgorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.o"
	cd /home/xu/Desktop/myAlgorithm/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.o -c /home/xu/Desktop/myAlgorithm/lib/myalgorithm.cpp

bin/CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.i"
	cd /home/xu/Desktop/myAlgorithm/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu/Desktop/myAlgorithm/lib/myalgorithm.cpp > CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.i

bin/CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.s"
	cd /home/xu/Desktop/myAlgorithm/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu/Desktop/myAlgorithm/lib/myalgorithm.cpp -o CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.s

bin/CMakeFiles/myalgorithm_static.dir/leetcode.cpp.o: bin/CMakeFiles/myalgorithm_static.dir/flags.make
bin/CMakeFiles/myalgorithm_static.dir/leetcode.cpp.o: ../lib/leetcode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu/Desktop/myAlgorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/CMakeFiles/myalgorithm_static.dir/leetcode.cpp.o"
	cd /home/xu/Desktop/myAlgorithm/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myalgorithm_static.dir/leetcode.cpp.o -c /home/xu/Desktop/myAlgorithm/lib/leetcode.cpp

bin/CMakeFiles/myalgorithm_static.dir/leetcode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myalgorithm_static.dir/leetcode.cpp.i"
	cd /home/xu/Desktop/myAlgorithm/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu/Desktop/myAlgorithm/lib/leetcode.cpp > CMakeFiles/myalgorithm_static.dir/leetcode.cpp.i

bin/CMakeFiles/myalgorithm_static.dir/leetcode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myalgorithm_static.dir/leetcode.cpp.s"
	cd /home/xu/Desktop/myAlgorithm/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu/Desktop/myAlgorithm/lib/leetcode.cpp -o CMakeFiles/myalgorithm_static.dir/leetcode.cpp.s

# Object files for target myalgorithm_static
myalgorithm_static_OBJECTS = \
"CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.o" \
"CMakeFiles/myalgorithm_static.dir/leetcode.cpp.o"

# External object files for target myalgorithm_static
myalgorithm_static_EXTERNAL_OBJECTS =

bin/libmyalgorithm_static.a: bin/CMakeFiles/myalgorithm_static.dir/myalgorithm.cpp.o
bin/libmyalgorithm_static.a: bin/CMakeFiles/myalgorithm_static.dir/leetcode.cpp.o
bin/libmyalgorithm_static.a: bin/CMakeFiles/myalgorithm_static.dir/build.make
bin/libmyalgorithm_static.a: bin/CMakeFiles/myalgorithm_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xu/Desktop/myAlgorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmyalgorithm_static.a"
	cd /home/xu/Desktop/myAlgorithm/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/myalgorithm_static.dir/cmake_clean_target.cmake
	cd /home/xu/Desktop/myAlgorithm/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myalgorithm_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/myalgorithm_static.dir/build: bin/libmyalgorithm_static.a

.PHONY : bin/CMakeFiles/myalgorithm_static.dir/build

bin/CMakeFiles/myalgorithm_static.dir/clean:
	cd /home/xu/Desktop/myAlgorithm/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/myalgorithm_static.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/myalgorithm_static.dir/clean

bin/CMakeFiles/myalgorithm_static.dir/depend:
	cd /home/xu/Desktop/myAlgorithm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xu/Desktop/myAlgorithm /home/xu/Desktop/myAlgorithm/lib /home/xu/Desktop/myAlgorithm/build /home/xu/Desktop/myAlgorithm/build/bin /home/xu/Desktop/myAlgorithm/build/bin/CMakeFiles/myalgorithm_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/myalgorithm_static.dir/depend

