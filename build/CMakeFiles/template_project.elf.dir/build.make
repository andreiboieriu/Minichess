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

# Include any dependencies generated for this target.
include CMakeFiles/template_project.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/template_project.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/template_project.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template_project.elf.dir/flags.make

CMakeFiles/template_project.elf.dir/src/adc.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/adc.cpp.obj: ../src/adc.cpp
CMakeFiles/template_project.elf.dir/src/adc.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template_project.elf.dir/src/adc.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/adc.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/adc.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/adc.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/adc.cpp

CMakeFiles/template_project.elf.dir/src/adc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/adc.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/adc.cpp > CMakeFiles/template_project.elf.dir/src/adc.cpp.i

CMakeFiles/template_project.elf.dir/src/adc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/adc.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/adc.cpp -o CMakeFiles/template_project.elf.dir/src/adc.cpp.s

CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj: ../src/button_manager.cpp
CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/button_manager.cpp

CMakeFiles/template_project.elf.dir/src/button_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/button_manager.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/button_manager.cpp > CMakeFiles/template_project.elf.dir/src/button_manager.cpp.i

CMakeFiles/template_project.elf.dir/src/button_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/button_manager.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/button_manager.cpp -o CMakeFiles/template_project.elf.dir/src/button_manager.cpp.s

CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj: ../src/chess_board.cpp
CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/chess_board.cpp

CMakeFiles/template_project.elf.dir/src/chess_board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/chess_board.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/chess_board.cpp > CMakeFiles/template_project.elf.dir/src/chess_board.cpp.i

CMakeFiles/template_project.elf.dir/src/chess_board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/chess_board.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/chess_board.cpp -o CMakeFiles/template_project.elf.dir/src/chess_board.cpp.s

CMakeFiles/template_project.elf.dir/src/display.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/display.cpp.obj: ../src/display.cpp
CMakeFiles/template_project.elf.dir/src/display.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/template_project.elf.dir/src/display.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/display.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/display.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/display.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/display.cpp

CMakeFiles/template_project.elf.dir/src/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/display.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/display.cpp > CMakeFiles/template_project.elf.dir/src/display.cpp.i

CMakeFiles/template_project.elf.dir/src/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/display.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/display.cpp -o CMakeFiles/template_project.elf.dir/src/display.cpp.s

CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj: ../src/i2c.cpp
CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/i2c.cpp

CMakeFiles/template_project.elf.dir/src/i2c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/i2c.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/i2c.cpp > CMakeFiles/template_project.elf.dir/src/i2c.cpp.i

CMakeFiles/template_project.elf.dir/src/i2c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/i2c.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/i2c.cpp -o CMakeFiles/template_project.elf.dir/src/i2c.cpp.s

CMakeFiles/template_project.elf.dir/src/main.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/template_project.elf.dir/src/main.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/template_project.elf.dir/src/main.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/main.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/main.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/main.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/main.cpp

CMakeFiles/template_project.elf.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/main.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/main.cpp > CMakeFiles/template_project.elf.dir/src/main.cpp.i

CMakeFiles/template_project.elf.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/main.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/main.cpp -o CMakeFiles/template_project.elf.dir/src/main.cpp.s

CMakeFiles/template_project.elf.dir/src/millis.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/millis.cpp.obj: ../src/millis.cpp
CMakeFiles/template_project.elf.dir/src/millis.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/template_project.elf.dir/src/millis.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/millis.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/millis.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/millis.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/millis.cpp

CMakeFiles/template_project.elf.dir/src/millis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/millis.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/millis.cpp > CMakeFiles/template_project.elf.dir/src/millis.cpp.i

CMakeFiles/template_project.elf.dir/src/millis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/millis.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/millis.cpp -o CMakeFiles/template_project.elf.dir/src/millis.cpp.s

CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj: ../src/minichess.cpp
CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/minichess.cpp

CMakeFiles/template_project.elf.dir/src/minichess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/minichess.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/minichess.cpp > CMakeFiles/template_project.elf.dir/src/minichess.cpp.i

CMakeFiles/template_project.elf.dir/src/minichess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/minichess.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/minichess.cpp -o CMakeFiles/template_project.elf.dir/src/minichess.cpp.s

CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj: ../src/text_renderer.cpp
CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/text_renderer.cpp

CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/text_renderer.cpp > CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.i

CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/text_renderer.cpp -o CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.s

CMakeFiles/template_project.elf.dir/src/uart.cpp.obj: CMakeFiles/template_project.elf.dir/flags.make
CMakeFiles/template_project.elf.dir/src/uart.cpp.obj: ../src/uart.cpp
CMakeFiles/template_project.elf.dir/src/uart.cpp.obj: CMakeFiles/template_project.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/template_project.elf.dir/src/uart.cpp.obj"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template_project.elf.dir/src/uart.cpp.obj -MF CMakeFiles/template_project.elf.dir/src/uart.cpp.obj.d -o CMakeFiles/template_project.elf.dir/src/uart.cpp.obj -c /home/unclegoga/Development/PM/proiect/src/uart.cpp

CMakeFiles/template_project.elf.dir/src/uart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.elf.dir/src/uart.cpp.i"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unclegoga/Development/PM/proiect/src/uart.cpp > CMakeFiles/template_project.elf.dir/src/uart.cpp.i

CMakeFiles/template_project.elf.dir/src/uart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.elf.dir/src/uart.cpp.s"
	avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unclegoga/Development/PM/proiect/src/uart.cpp -o CMakeFiles/template_project.elf.dir/src/uart.cpp.s

# Object files for target template_project.elf
template_project_elf_OBJECTS = \
"CMakeFiles/template_project.elf.dir/src/adc.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/display.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/main.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/millis.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj" \
"CMakeFiles/template_project.elf.dir/src/uart.cpp.obj"

# External object files for target template_project.elf
template_project_elf_EXTERNAL_OBJECTS =

template_project.elf: CMakeFiles/template_project.elf.dir/src/adc.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/button_manager.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/chess_board.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/display.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/i2c.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/main.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/millis.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/minichess.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/text_renderer.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/src/uart.cpp.obj
template_project.elf: CMakeFiles/template_project.elf.dir/build.make
template_project.elf: CMakeFiles/template_project.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/unclegoga/Development/PM/proiect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable template_project.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template_project.elf.dir/link.txt --verbose=$(VERBOSE)
	avr-objcopy -j .text -j .data -O ihex template_project.elf template_project.hex
	avr-objcopy -j .text -j .data -O binary template_project.elf template_project.bin

# Rule to build all files generated by this target.
CMakeFiles/template_project.elf.dir/build: template_project.elf
.PHONY : CMakeFiles/template_project.elf.dir/build

CMakeFiles/template_project.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/template_project.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/template_project.elf.dir/clean

CMakeFiles/template_project.elf.dir/depend:
	cd /home/unclegoga/Development/PM/proiect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/unclegoga/Development/PM/proiect /home/unclegoga/Development/PM/proiect /home/unclegoga/Development/PM/proiect/build /home/unclegoga/Development/PM/proiect/build /home/unclegoga/Development/PM/proiect/build/CMakeFiles/template_project.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template_project.elf.dir/depend

