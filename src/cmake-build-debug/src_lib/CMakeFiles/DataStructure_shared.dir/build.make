# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/xu736946693/CLion-2022.2.4/clion-2022.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/xu736946693/CLion-2022.2.4/clion-2022.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xu736946693/Desktop/DataStructure/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug

# Include any dependencies generated for this target.
include src_lib/CMakeFiles/DataStructure_shared.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.make

# Include the progress variables for this target.
include src_lib/CMakeFiles/DataStructure_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src_lib/CMakeFiles/DataStructure_shared.dir/flags.make

src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/flags.make
src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.o: ../lib/Heap.cpp
src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.o -MF CMakeFiles/DataStructure_shared.dir/Heap.cpp.o.d -o CMakeFiles/DataStructure_shared.dir/Heap.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/lib/Heap.cpp

src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_shared.dir/Heap.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/lib/Heap.cpp > CMakeFiles/DataStructure_shared.dir/Heap.cpp.i

src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_shared.dir/Heap.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/lib/Heap.cpp -o CMakeFiles/DataStructure_shared.dir/Heap.cpp.s

src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/flags.make
src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o: ../lib/leetcode.cpp
src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o -MF CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o.d -o CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/lib/leetcode.cpp

src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_shared.dir/leetcode.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/lib/leetcode.cpp > CMakeFiles/DataStructure_shared.dir/leetcode.cpp.i

src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_shared.dir/leetcode.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/lib/leetcode.cpp -o CMakeFiles/DataStructure_shared.dir/leetcode.cpp.s

src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/flags.make
src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.o: ../lib/Tree.cpp
src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.o -MF CMakeFiles/DataStructure_shared.dir/Tree.cpp.o.d -o CMakeFiles/DataStructure_shared.dir/Tree.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/lib/Tree.cpp

src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_shared.dir/Tree.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/lib/Tree.cpp > CMakeFiles/DataStructure_shared.dir/Tree.cpp.i

src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_shared.dir/Tree.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/lib/Tree.cpp -o CMakeFiles/DataStructure_shared.dir/Tree.cpp.s

src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/flags.make
src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.o: ../lib/SetType.cpp
src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.o -MF CMakeFiles/DataStructure_shared.dir/SetType.cpp.o.d -o CMakeFiles/DataStructure_shared.dir/SetType.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/lib/SetType.cpp

src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_shared.dir/SetType.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/lib/SetType.cpp > CMakeFiles/DataStructure_shared.dir/SetType.cpp.i

src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_shared.dir/SetType.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/lib/SetType.cpp -o CMakeFiles/DataStructure_shared.dir/SetType.cpp.s

src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/flags.make
src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.o: ../lib/Graph.cpp
src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.o -MF CMakeFiles/DataStructure_shared.dir/Graph.cpp.o.d -o CMakeFiles/DataStructure_shared.dir/Graph.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/lib/Graph.cpp

src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_shared.dir/Graph.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/lib/Graph.cpp > CMakeFiles/DataStructure_shared.dir/Graph.cpp.i

src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_shared.dir/Graph.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/lib/Graph.cpp -o CMakeFiles/DataStructure_shared.dir/Graph.cpp.s

src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/flags.make
src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.o: ../lib/Sort.cpp
src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.o: src_lib/CMakeFiles/DataStructure_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.o"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.o -MF CMakeFiles/DataStructure_shared.dir/Sort.cpp.o.d -o CMakeFiles/DataStructure_shared.dir/Sort.cpp.o -c /home/xu736946693/Desktop/DataStructure/src/lib/Sort.cpp

src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_shared.dir/Sort.cpp.i"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu736946693/Desktop/DataStructure/src/lib/Sort.cpp > CMakeFiles/DataStructure_shared.dir/Sort.cpp.i

src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_shared.dir/Sort.cpp.s"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu736946693/Desktop/DataStructure/src/lib/Sort.cpp -o CMakeFiles/DataStructure_shared.dir/Sort.cpp.s

# Object files for target DataStructure_shared
DataStructure_shared_OBJECTS = \
"CMakeFiles/DataStructure_shared.dir/Heap.cpp.o" \
"CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o" \
"CMakeFiles/DataStructure_shared.dir/Tree.cpp.o" \
"CMakeFiles/DataStructure_shared.dir/SetType.cpp.o" \
"CMakeFiles/DataStructure_shared.dir/Graph.cpp.o" \
"CMakeFiles/DataStructure_shared.dir/Sort.cpp.o"

# External object files for target DataStructure_shared
DataStructure_shared_EXTERNAL_OBJECTS =

src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/Heap.cpp.o
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/leetcode.cpp.o
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/Tree.cpp.o
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/SetType.cpp.o
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/Graph.cpp.o
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/Sort.cpp.o
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/build.make
src_lib/libDataStructure.so: src_lib/CMakeFiles/DataStructure_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library libDataStructure.so"
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructure_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src_lib/CMakeFiles/DataStructure_shared.dir/build: src_lib/libDataStructure.so
.PHONY : src_lib/CMakeFiles/DataStructure_shared.dir/build

src_lib/CMakeFiles/DataStructure_shared.dir/clean:
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib && $(CMAKE_COMMAND) -P CMakeFiles/DataStructure_shared.dir/cmake_clean.cmake
.PHONY : src_lib/CMakeFiles/DataStructure_shared.dir/clean

src_lib/CMakeFiles/DataStructure_shared.dir/depend:
	cd /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xu736946693/Desktop/DataStructure/src /home/xu736946693/Desktop/DataStructure/src/lib /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib /home/xu736946693/Desktop/DataStructure/src/cmake-build-debug/src_lib/CMakeFiles/DataStructure_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src_lib/CMakeFiles/DataStructure_shared.dir/depend

