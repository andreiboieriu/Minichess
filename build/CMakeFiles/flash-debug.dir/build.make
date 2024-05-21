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
CMAKE_SOURCE_DIR = /home/unclegoga/Development/PM/proiect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/unclegoga/Development/PM/proiect/build

# Utility rule file for flash-debug.

# Include any custom commands dependencies for this target.
include CMakeFiles/flash-debug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/flash-debug.dir/progress.make

CMakeFiles/flash-debug: template_project.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "flashes the elf file onto the MCU"
	avrdude -c arduino -B 16000000 -p atmega328p -b 115200 -U flash:w:template_project.elf:e

flash-debug: CMakeFiles/flash-debug
flash-debug: CMakeFiles/flash-debug.dir/build.make
.PHONY : flash-debug

# Rule to build all files generated by this target.
CMakeFiles/flash-debug.dir/build: flash-debug
.PHONY : CMakeFiles/flash-debug.dir/build

CMakeFiles/flash-debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flash-debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flash-debug.dir/clean

CMakeFiles/flash-debug.dir/depend:
	cd /home/unclegoga/Development/PM/proiect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/unclegoga/Development/PM/proiect /home/unclegoga/Development/PM/proiect /home/unclegoga/Development/PM/proiect/build /home/unclegoga/Development/PM/proiect/build /home/unclegoga/Development/PM/proiect/build/CMakeFiles/flash-debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flash-debug.dir/depend

