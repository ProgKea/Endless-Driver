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

# Utility rule file for cross.

# Include any custom commands dependencies for this target.
include CMakeFiles/cross.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cross.dir/progress.make

CMakeFiles/cross:
	x86_64-w64-mingw32-gcc ~/code/remake-Endless-Driver/src/main.c ~/code/remake-Endless-Driver/src/func.c ~/code/remake-Endless-Driver/src/game_elements.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o windows/endless-driver

cross: CMakeFiles/cross
cross: CMakeFiles/cross.dir/build.make
.PHONY : cross

# Rule to build all files generated by this target.
CMakeFiles/cross.dir/build: cross
.PHONY : CMakeFiles/cross.dir/build

CMakeFiles/cross.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cross.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cross.dir/clean

CMakeFiles/cross.dir/depend:
	cd /home/keanu/code/remake-Endless-Driver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keanu/code/remake-Endless-Driver/src /home/keanu/code/remake-Endless-Driver/src /home/keanu/code/remake-Endless-Driver/build /home/keanu/code/remake-Endless-Driver/build /home/keanu/code/remake-Endless-Driver/build/CMakeFiles/cross.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cross.dir/depend

