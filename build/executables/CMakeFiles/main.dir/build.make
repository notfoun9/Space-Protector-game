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
include executables/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include executables/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include executables/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include executables/CMakeFiles/main.dir/flags.make

executables/CMakeFiles/main.dir/main.cpp.o: executables/CMakeFiles/main.dir/flags.make
executables/CMakeFiles/main.dir/main.cpp.o: /Users/maksim/Study/C++/game2/executables/main.cpp
executables/CMakeFiles/main.dir/main.cpp.o: executables/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object executables/CMakeFiles/main.dir/main.cpp.o"
	cd /Users/maksim/Study/C++/game2/build/executables && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT executables/CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /Users/maksim/Study/C++/game2/executables/main.cpp

executables/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /Users/maksim/Study/C++/game2/build/executables && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksim/Study/C++/game2/executables/main.cpp > CMakeFiles/main.dir/main.cpp.i

executables/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /Users/maksim/Study/C++/game2/build/executables && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksim/Study/C++/game2/executables/main.cpp -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

executables/bin/main: executables/CMakeFiles/main.dir/main.cpp.o
executables/bin/main: executables/CMakeFiles/main.dir/build.make
executables/bin/main: game/libgame.a
executables/bin/main: /Users/maksim/Study/C++/game2/src/lib/SDL2.framework/Versions/A/SDL2
executables/bin/main: libraries/ECS/libECS.a
executables/bin/main: libraries/utilities/short_names/libshort_names.a
executables/bin/main: libraries/utilities/time/libtime.a
executables/bin/main: libraries/components/position/libposition.a
executables/bin/main: libraries/components/animatedTexture/libanimatedTexture.a
executables/bin/main: libraries/states/menu/libmenu.a
executables/bin/main: libraries/components/simpleTexture/libsimpleTexture.a
executables/bin/main: libraries/structs/Vector2D/libVector2D.a
executables/bin/main: libraries/utilities/texture_manager/libtexture_manager.a
executables/bin/main: game/libgame.a
executables/bin/main: libraries/ECS/libECS.a
executables/bin/main: libraries/utilities/short_names/libshort_names.a
executables/bin/main: libraries/utilities/time/libtime.a
executables/bin/main: libraries/components/position/libposition.a
executables/bin/main: libraries/components/animatedTexture/libanimatedTexture.a
executables/bin/main: libraries/states/menu/libmenu.a
executables/bin/main: libraries/components/simpleTexture/libsimpleTexture.a
executables/bin/main: libraries/structs/Vector2D/libVector2D.a
executables/bin/main: libraries/utilities/texture_manager/libtexture_manager.a
executables/bin/main: executables/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksim/Study/C++/game2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/main"
	cd /Users/maksim/Study/C++/game2/build/executables && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
executables/CMakeFiles/main.dir/build: executables/bin/main
.PHONY : executables/CMakeFiles/main.dir/build

executables/CMakeFiles/main.dir/clean:
	cd /Users/maksim/Study/C++/game2/build/executables && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : executables/CMakeFiles/main.dir/clean

executables/CMakeFiles/main.dir/depend:
	cd /Users/maksim/Study/C++/game2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksim/Study/C++/game2 /Users/maksim/Study/C++/game2/executables /Users/maksim/Study/C++/game2/build /Users/maksim/Study/C++/game2/build/executables /Users/maksim/Study/C++/game2/build/executables/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : executables/CMakeFiles/main.dir/depend

