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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/deanwilson/development/cpp/BlackEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/deanwilson/development/cpp/BlackEngine

# Utility rule file for CopyDllToBlackEngineTest.

# Include any custom commands dependencies for this target.
include BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/compiler_depend.make

# Include the progress variables for this target.
include BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/progress.make

BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest: bin/arm64/BlackEngine/libBlackEngine.dylib

CopyDllToBlackEngineTest: BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest
CopyDllToBlackEngineTest: BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/build.make
.PHONY : CopyDllToBlackEngineTest

# Rule to build all files generated by this target.
BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/build: CopyDllToBlackEngineTest
.PHONY : BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/build

BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/clean:
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngineTest && $(CMAKE_COMMAND) -P CMakeFiles/CopyDllToBlackEngineTest.dir/cmake_clean.cmake
.PHONY : BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/clean

BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/depend:
	cd /Users/deanwilson/development/cpp/BlackEngine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/deanwilson/development/cpp/BlackEngine /Users/deanwilson/development/cpp/BlackEngine/BlackEngineTest /Users/deanwilson/development/cpp/BlackEngine /Users/deanwilson/development/cpp/BlackEngine/BlackEngineTest /Users/deanwilson/development/cpp/BlackEngine/BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : BlackEngineTest/CMakeFiles/CopyDllToBlackEngineTest.dir/depend
