# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/elibillinger/Algorithms/Project3/Trebuchet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/recursive.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recursive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recursive.dir/flags.make

CMakeFiles/recursive.dir/main.cpp.o: CMakeFiles/recursive.dir/flags.make
CMakeFiles/recursive.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recursive.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recursive.dir/main.cpp.o -c /Users/elibillinger/Algorithms/Project3/Trebuchet/main.cpp

CMakeFiles/recursive.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recursive.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elibillinger/Algorithms/Project3/Trebuchet/main.cpp > CMakeFiles/recursive.dir/main.cpp.i

CMakeFiles/recursive.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recursive.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elibillinger/Algorithms/Project3/Trebuchet/main.cpp -o CMakeFiles/recursive.dir/main.cpp.s

# Object files for target recursive
recursive_OBJECTS = \
"CMakeFiles/recursive.dir/main.cpp.o"

# External object files for target recursive
recursive_EXTERNAL_OBJECTS =

recursive: CMakeFiles/recursive.dir/main.cpp.o
recursive: CMakeFiles/recursive.dir/build.make
recursive: CMakeFiles/recursive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable recursive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recursive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recursive.dir/build: recursive

.PHONY : CMakeFiles/recursive.dir/build

CMakeFiles/recursive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recursive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recursive.dir/clean

CMakeFiles/recursive.dir/depend:
	cd /Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/elibillinger/Algorithms/Project3/Trebuchet /Users/elibillinger/Algorithms/Project3/Trebuchet /Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug /Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug /Users/elibillinger/Algorithms/Project3/Trebuchet/cmake-build-debug/CMakeFiles/recursive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recursive.dir/depend

