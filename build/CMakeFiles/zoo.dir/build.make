# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/keanu/code/remake-Endless-Driver/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keanu/code/remake-Endless-Driver/build

# Utility rule file for zoo.

# Include any custom commands dependencies for this target.
include CMakeFiles/zoo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zoo.dir/progress.make

CMakeFiles/zoo:
	echo "This is ALL target 'zoo', and it depends on "

zoo: CMakeFiles/zoo
zoo: CMakeFiles/zoo.dir/build.make
.PHONY : zoo

# Rule to build all files generated by this target.
CMakeFiles/zoo.dir/build: zoo
.PHONY : CMakeFiles/zoo.dir/build

CMakeFiles/zoo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zoo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zoo.dir/clean

CMakeFiles/zoo.dir/depend:
	cd /home/keanu/code/remake-Endless-Driver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keanu/code/remake-Endless-Driver/src /home/keanu/code/remake-Endless-Driver/src /home/keanu/code/remake-Endless-Driver/build /home/keanu/code/remake-Endless-Driver/build /home/keanu/code/remake-Endless-Driver/build/CMakeFiles/zoo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zoo.dir/depend
