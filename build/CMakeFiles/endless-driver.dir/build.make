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

# Include any dependencies generated for this target.
include CMakeFiles/endless-driver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/endless-driver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/endless-driver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/endless-driver.dir/flags.make

CMakeFiles/endless-driver.dir/main.c.o: CMakeFiles/endless-driver.dir/flags.make
CMakeFiles/endless-driver.dir/main.c.o: /home/keanu/code/remake-Endless-Driver/src/main.c
CMakeFiles/endless-driver.dir/main.c.o: CMakeFiles/endless-driver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keanu/code/remake-Endless-Driver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/endless-driver.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/endless-driver.dir/main.c.o -MF CMakeFiles/endless-driver.dir/main.c.o.d -o CMakeFiles/endless-driver.dir/main.c.o -c /home/keanu/code/remake-Endless-Driver/src/main.c

CMakeFiles/endless-driver.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/endless-driver.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/keanu/code/remake-Endless-Driver/src/main.c > CMakeFiles/endless-driver.dir/main.c.i

CMakeFiles/endless-driver.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/endless-driver.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/keanu/code/remake-Endless-Driver/src/main.c -o CMakeFiles/endless-driver.dir/main.c.s

# Object files for target endless-driver
endless__driver_OBJECTS = \
"CMakeFiles/endless-driver.dir/main.c.o"

# External object files for target endless-driver
endless__driver_EXTERNAL_OBJECTS =

endless-driver: CMakeFiles/endless-driver.dir/main.c.o
endless-driver: CMakeFiles/endless-driver.dir/build.make
endless-driver: libfunc.a
endless-driver: libgame_elements.a
endless-driver: /usr/lib/libSDL2-2.0.so.0.18.2
endless-driver: CMakeFiles/endless-driver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keanu/code/remake-Endless-Driver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable endless-driver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/endless-driver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/endless-driver.dir/build: endless-driver
.PHONY : CMakeFiles/endless-driver.dir/build

CMakeFiles/endless-driver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/endless-driver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/endless-driver.dir/clean

CMakeFiles/endless-driver.dir/depend:
	cd /home/keanu/code/remake-Endless-Driver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keanu/code/remake-Endless-Driver/src /home/keanu/code/remake-Endless-Driver/src /home/keanu/code/remake-Endless-Driver/build /home/keanu/code/remake-Endless-Driver/build /home/keanu/code/remake-Endless-Driver/build/CMakeFiles/endless-driver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/endless-driver.dir/depend
