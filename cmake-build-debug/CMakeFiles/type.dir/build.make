# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /home/crtrader/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4073.41/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/crtrader/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4073.41/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crtrader/CLionProjects/CPPFun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crtrader/CLionProjects/CPPFun/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/type.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/type.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/type.dir/flags.make

CMakeFiles/type.dir/TypeTrait/type.cpp.o: CMakeFiles/type.dir/flags.make
CMakeFiles/type.dir/TypeTrait/type.cpp.o: ../TypeTrait/type.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crtrader/CLionProjects/CPPFun/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/type.dir/TypeTrait/type.cpp.o"
	/opt/cresearch/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/type.dir/TypeTrait/type.cpp.o -c /home/crtrader/CLionProjects/CPPFun/TypeTrait/type.cpp

CMakeFiles/type.dir/TypeTrait/type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/type.dir/TypeTrait/type.cpp.i"
	/opt/cresearch/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crtrader/CLionProjects/CPPFun/TypeTrait/type.cpp > CMakeFiles/type.dir/TypeTrait/type.cpp.i

CMakeFiles/type.dir/TypeTrait/type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/type.dir/TypeTrait/type.cpp.s"
	/opt/cresearch/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crtrader/CLionProjects/CPPFun/TypeTrait/type.cpp -o CMakeFiles/type.dir/TypeTrait/type.cpp.s

CMakeFiles/type.dir/TypeTrait/type.cpp.o.requires:

.PHONY : CMakeFiles/type.dir/TypeTrait/type.cpp.o.requires

CMakeFiles/type.dir/TypeTrait/type.cpp.o.provides: CMakeFiles/type.dir/TypeTrait/type.cpp.o.requires
	$(MAKE) -f CMakeFiles/type.dir/build.make CMakeFiles/type.dir/TypeTrait/type.cpp.o.provides.build
.PHONY : CMakeFiles/type.dir/TypeTrait/type.cpp.o.provides

CMakeFiles/type.dir/TypeTrait/type.cpp.o.provides.build: CMakeFiles/type.dir/TypeTrait/type.cpp.o


# Object files for target type
type_OBJECTS = \
"CMakeFiles/type.dir/TypeTrait/type.cpp.o"

# External object files for target type
type_EXTERNAL_OBJECTS =

type: CMakeFiles/type.dir/TypeTrait/type.cpp.o
type: CMakeFiles/type.dir/build.make
type: CMakeFiles/type.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crtrader/CLionProjects/CPPFun/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable type"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/type.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/type.dir/build: type

.PHONY : CMakeFiles/type.dir/build

CMakeFiles/type.dir/requires: CMakeFiles/type.dir/TypeTrait/type.cpp.o.requires

.PHONY : CMakeFiles/type.dir/requires

CMakeFiles/type.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/type.dir/cmake_clean.cmake
.PHONY : CMakeFiles/type.dir/clean

CMakeFiles/type.dir/depend:
	cd /home/crtrader/CLionProjects/CPPFun/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crtrader/CLionProjects/CPPFun /home/crtrader/CLionProjects/CPPFun /home/crtrader/CLionProjects/CPPFun/cmake-build-debug /home/crtrader/CLionProjects/CPPFun/cmake-build-debug /home/crtrader/CLionProjects/CPPFun/cmake-build-debug/CMakeFiles/type.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/type.dir/depend

