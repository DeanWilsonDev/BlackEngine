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

# Include any dependencies generated for this target.
include BlackEngine/CMakeFiles/BlackEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include BlackEngine/CMakeFiles/BlackEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include BlackEngine/CMakeFiles/BlackEngine.dir/progress.make

# Include the compile flags for this target's objects.
include BlackEngine/CMakeFiles/BlackEngine.dir/flags.make

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o: BlackEngine/CMakeFiles/BlackEngine.dir/flags.make
BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o: BlackEngine/src/BlackEngine/Application.cpp
BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o: BlackEngine/CMakeFiles/BlackEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/deanwilson/development/cpp/BlackEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o -MF CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o.d -o CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o -c /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Application.cpp

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.i"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Application.cpp > CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.i

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.s"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Application.cpp -o CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.s

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o: BlackEngine/CMakeFiles/BlackEngine.dir/flags.make
BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o: BlackEngine/src/BlackEngine/Logging/Log.cpp
BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o: BlackEngine/CMakeFiles/BlackEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/deanwilson/development/cpp/BlackEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o -MF CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o.d -o CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o -c /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Logging/Log.cpp

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.i"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Logging/Log.cpp > CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.i

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.s"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Logging/Log.cpp -o CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.s

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o: BlackEngine/CMakeFiles/BlackEngine.dir/flags.make
BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o: BlackEngine/src/BlackEngine/Logging/Logger.cpp
BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o: BlackEngine/CMakeFiles/BlackEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/deanwilson/development/cpp/BlackEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o -MF CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o.d -o CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o -c /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Logging/Logger.cpp

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.i"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Logging/Logger.cpp > CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.i

BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.s"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/src/BlackEngine/Logging/Logger.cpp -o CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.s

# Object files for target BlackEngine
BlackEngine_OBJECTS = \
"CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o" \
"CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o" \
"CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o"

# External object files for target BlackEngine
BlackEngine_EXTERNAL_OBJECTS =

bin/arm64/BlackEngine/libBlackEngine.dylib: BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Application.cpp.o
bin/arm64/BlackEngine/libBlackEngine.dylib: BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Log.cpp.o
bin/arm64/BlackEngine/libBlackEngine.dylib: BlackEngine/CMakeFiles/BlackEngine.dir/src/BlackEngine/Logging/Logger.cpp.o
bin/arm64/BlackEngine/libBlackEngine.dylib: BlackEngine/CMakeFiles/BlackEngine.dir/build.make
bin/arm64/BlackEngine/libBlackEngine.dylib: BlackEngine/CMakeFiles/BlackEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/deanwilson/development/cpp/BlackEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../bin/arm64/BlackEngine/libBlackEngine.dylib"
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BlackEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
BlackEngine/CMakeFiles/BlackEngine.dir/build: bin/arm64/BlackEngine/libBlackEngine.dylib
.PHONY : BlackEngine/CMakeFiles/BlackEngine.dir/build

BlackEngine/CMakeFiles/BlackEngine.dir/clean:
	cd /Users/deanwilson/development/cpp/BlackEngine/BlackEngine && $(CMAKE_COMMAND) -P CMakeFiles/BlackEngine.dir/cmake_clean.cmake
.PHONY : BlackEngine/CMakeFiles/BlackEngine.dir/clean

BlackEngine/CMakeFiles/BlackEngine.dir/depend:
	cd /Users/deanwilson/development/cpp/BlackEngine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/deanwilson/development/cpp/BlackEngine /Users/deanwilson/development/cpp/BlackEngine/BlackEngine /Users/deanwilson/development/cpp/BlackEngine /Users/deanwilson/development/cpp/BlackEngine/BlackEngine /Users/deanwilson/development/cpp/BlackEngine/BlackEngine/CMakeFiles/BlackEngine.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : BlackEngine/CMakeFiles/BlackEngine.dir/depend

