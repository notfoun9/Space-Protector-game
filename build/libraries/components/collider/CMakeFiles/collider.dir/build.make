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
include libraries/components/collider/CMakeFiles/collider.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libraries/components/collider/CMakeFiles/collider.dir/compiler_depend.make

# Include the progress variables for this target.
include libraries/components/collider/CMakeFiles/collider.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/components/collider/CMakeFiles/collider.dir/flags.make

libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.o: libraries/components/collider/CMakeFiles/collider.dir/flags.make
libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.o: /Users/maksim/Study/C++/game2/libraries/components/collider/collider.cpp
libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.o: libraries/components/collider/CMakeFiles/collider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.o"
	cd /Users/maksim/Study/C++/game2/build/libraries/components/collider && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.o -MF CMakeFiles/collider.dir/collider.cpp.o.d -o CMakeFiles/collider.dir/collider.cpp.o -c /Users/maksim/Study/C++/game2/libraries/components/collider/collider.cpp

libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/collider.dir/collider.cpp.i"
	cd /Users/maksim/Study/C++/game2/build/libraries/components/collider && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksim/Study/C++/game2/libraries/components/collider/collider.cpp > CMakeFiles/collider.dir/collider.cpp.i

libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/collider.dir/collider.cpp.s"
	cd /Users/maksim/Study/C++/game2/build/libraries/components/collider && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksim/Study/C++/game2/libraries/components/collider/collider.cpp -o CMakeFiles/collider.dir/collider.cpp.s

# Object files for target collider
collider_OBJECTS = \
"CMakeFiles/collider.dir/collider.cpp.o"

# External object files for target collider
collider_EXTERNAL_OBJECTS =

libraries/components/collider/libcollider.a: libraries/components/collider/CMakeFiles/collider.dir/collider.cpp.o
libraries/components/collider/libcollider.a: libraries/components/collider/CMakeFiles/collider.dir/build.make
libraries/components/collider/libcollider.a: libraries/components/collider/CMakeFiles/collider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcollider.a"
	cd /Users/maksim/Study/C++/game2/build/libraries/components/collider && $(CMAKE_COMMAND) -P CMakeFiles/collider.dir/cmake_clean_target.cmake
	cd /Users/maksim/Study/C++/game2/build/libraries/components/collider && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/collider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/components/collider/CMakeFiles/collider.dir/build: libraries/components/collider/libcollider.a
.PHONY : libraries/components/collider/CMakeFiles/collider.dir/build

libraries/components/collider/CMakeFiles/collider.dir/clean:
	cd /Users/maksim/Study/C++/game2/build/libraries/components/collider && $(CMAKE_COMMAND) -P CMakeFiles/collider.dir/cmake_clean.cmake
.PHONY : libraries/components/collider/CMakeFiles/collider.dir/clean

libraries/components/collider/CMakeFiles/collider.dir/depend:
	cd /Users/maksim/Study/C++/game2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksim/Study/C++/game2 /Users/maksim/Study/C++/game2/libraries/components/collider /Users/maksim/Study/C++/game2/build /Users/maksim/Study/C++/game2/build/libraries/components/collider /Users/maksim/Study/C++/game2/build/libraries/components/collider/CMakeFiles/collider.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libraries/components/collider/CMakeFiles/collider.dir/depend

