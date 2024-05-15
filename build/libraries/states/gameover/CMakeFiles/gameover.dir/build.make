# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maksim/Study/C++/game2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maksim/Study/C++/game2/build

# Include any dependencies generated for this target.
include libraries/states/gameover/CMakeFiles/gameover.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libraries/states/gameover/CMakeFiles/gameover.dir/compiler_depend.make

# Include the progress variables for this target.
include libraries/states/gameover/CMakeFiles/gameover.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/states/gameover/CMakeFiles/gameover.dir/flags.make

libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.o: libraries/states/gameover/CMakeFiles/gameover.dir/flags.make
libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.o: /Users/maksim/Study/C++/game2/libraries/states/gameover/gameover.cpp
libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.o: libraries/states/gameover/CMakeFiles/gameover.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.o"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/gameover && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.o -MF CMakeFiles/gameover.dir/gameover.cpp.o.d -o CMakeFiles/gameover.dir/gameover.cpp.o -c /Users/maksim/Study/C++/game2/libraries/states/gameover/gameover.cpp

libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gameover.dir/gameover.cpp.i"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/gameover && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksim/Study/C++/game2/libraries/states/gameover/gameover.cpp > CMakeFiles/gameover.dir/gameover.cpp.i

libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gameover.dir/gameover.cpp.s"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/gameover && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksim/Study/C++/game2/libraries/states/gameover/gameover.cpp -o CMakeFiles/gameover.dir/gameover.cpp.s

# Object files for target gameover
gameover_OBJECTS = \
"CMakeFiles/gameover.dir/gameover.cpp.o"

# External object files for target gameover
gameover_EXTERNAL_OBJECTS =

libraries/states/gameover/libgameover.a: libraries/states/gameover/CMakeFiles/gameover.dir/gameover.cpp.o
libraries/states/gameover/libgameover.a: libraries/states/gameover/CMakeFiles/gameover.dir/build.make
libraries/states/gameover/libgameover.a: libraries/states/gameover/CMakeFiles/gameover.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgameover.a"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/gameover && $(CMAKE_COMMAND) -P CMakeFiles/gameover.dir/cmake_clean_target.cmake
	cd /Users/maksim/Study/C++/game2/build/libraries/states/gameover && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameover.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/states/gameover/CMakeFiles/gameover.dir/build: libraries/states/gameover/libgameover.a
.PHONY : libraries/states/gameover/CMakeFiles/gameover.dir/build

libraries/states/gameover/CMakeFiles/gameover.dir/clean:
	cd /Users/maksim/Study/C++/game2/build/libraries/states/gameover && $(CMAKE_COMMAND) -P CMakeFiles/gameover.dir/cmake_clean.cmake
.PHONY : libraries/states/gameover/CMakeFiles/gameover.dir/clean

libraries/states/gameover/CMakeFiles/gameover.dir/depend:
	cd /Users/maksim/Study/C++/game2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksim/Study/C++/game2 /Users/maksim/Study/C++/game2/libraries/states/gameover /Users/maksim/Study/C++/game2/build /Users/maksim/Study/C++/game2/build/libraries/states/gameover /Users/maksim/Study/C++/game2/build/libraries/states/gameover/CMakeFiles/gameover.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libraries/states/gameover/CMakeFiles/gameover.dir/depend
