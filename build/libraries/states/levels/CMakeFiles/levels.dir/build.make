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
include libraries/states/levels/CMakeFiles/levels.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libraries/states/levels/CMakeFiles/levels.dir/compiler_depend.make

# Include the progress variables for this target.
include libraries/states/levels/CMakeFiles/levels.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/states/levels/CMakeFiles/levels.dir/flags.make

libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.o: libraries/states/levels/CMakeFiles/levels.dir/flags.make
libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.o: /Users/maksim/Study/C++/game2/libraries/states/levels/levels.cpp
libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.o: libraries/states/levels/CMakeFiles/levels.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.o"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/levels && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.o -MF CMakeFiles/levels.dir/levels.cpp.o.d -o CMakeFiles/levels.dir/levels.cpp.o -c /Users/maksim/Study/C++/game2/libraries/states/levels/levels.cpp

libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/levels.dir/levels.cpp.i"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/levels && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksim/Study/C++/game2/libraries/states/levels/levels.cpp > CMakeFiles/levels.dir/levels.cpp.i

libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/levels.dir/levels.cpp.s"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/levels && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksim/Study/C++/game2/libraries/states/levels/levels.cpp -o CMakeFiles/levels.dir/levels.cpp.s

# Object files for target levels
levels_OBJECTS = \
"CMakeFiles/levels.dir/levels.cpp.o"

# External object files for target levels
levels_EXTERNAL_OBJECTS =

libraries/states/levels/liblevels.a: libraries/states/levels/CMakeFiles/levels.dir/levels.cpp.o
libraries/states/levels/liblevels.a: libraries/states/levels/CMakeFiles/levels.dir/build.make
libraries/states/levels/liblevels.a: libraries/states/levels/CMakeFiles/levels.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblevels.a"
	cd /Users/maksim/Study/C++/game2/build/libraries/states/levels && $(CMAKE_COMMAND) -P CMakeFiles/levels.dir/cmake_clean_target.cmake
	cd /Users/maksim/Study/C++/game2/build/libraries/states/levels && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/levels.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/states/levels/CMakeFiles/levels.dir/build: libraries/states/levels/liblevels.a
.PHONY : libraries/states/levels/CMakeFiles/levels.dir/build

libraries/states/levels/CMakeFiles/levels.dir/clean:
	cd /Users/maksim/Study/C++/game2/build/libraries/states/levels && $(CMAKE_COMMAND) -P CMakeFiles/levels.dir/cmake_clean.cmake
.PHONY : libraries/states/levels/CMakeFiles/levels.dir/clean

libraries/states/levels/CMakeFiles/levels.dir/depend:
	cd /Users/maksim/Study/C++/game2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksim/Study/C++/game2 /Users/maksim/Study/C++/game2/libraries/states/levels /Users/maksim/Study/C++/game2/build /Users/maksim/Study/C++/game2/build/libraries/states/levels /Users/maksim/Study/C++/game2/build/libraries/states/levels/CMakeFiles/levels.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libraries/states/levels/CMakeFiles/levels.dir/depend
