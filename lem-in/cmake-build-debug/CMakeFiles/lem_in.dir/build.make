# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vchechai/work/lem-in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vchechai/work/lem-in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem_in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem_in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem_in.dir/flags.make

CMakeFiles/lem_in.dir/library.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/library.c.o: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vchechai/work/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem_in.dir/library.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/library.c.o   -c /Users/vchechai/work/lem-in/library.c

CMakeFiles/lem_in.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/library.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vchechai/work/lem-in/library.c > CMakeFiles/lem_in.dir/library.c.i

CMakeFiles/lem_in.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/library.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vchechai/work/lem-in/library.c -o CMakeFiles/lem_in.dir/library.c.s

CMakeFiles/lem_in.dir/library.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/library.c.o.requires

CMakeFiles/lem_in.dir/library.c.o.provides: CMakeFiles/lem_in.dir/library.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/library.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/library.c.o.provides

CMakeFiles/lem_in.dir/library.c.o.provides.build: CMakeFiles/lem_in.dir/library.c.o


# Object files for target lem_in
lem_in_OBJECTS = \
"CMakeFiles/lem_in.dir/library.c.o"

# External object files for target lem_in
lem_in_EXTERNAL_OBJECTS =

liblem_in.a: CMakeFiles/lem_in.dir/library.c.o
liblem_in.a: CMakeFiles/lem_in.dir/build.make
liblem_in.a: CMakeFiles/lem_in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vchechai/work/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library liblem_in.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lem_in.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem_in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem_in.dir/build: liblem_in.a

.PHONY : CMakeFiles/lem_in.dir/build

CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/library.c.o.requires

.PHONY : CMakeFiles/lem_in.dir/requires

CMakeFiles/lem_in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem_in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem_in.dir/clean

CMakeFiles/lem_in.dir/depend:
	cd /Users/vchechai/work/lem-in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vchechai/work/lem-in /Users/vchechai/work/lem-in /Users/vchechai/work/lem-in/cmake-build-debug /Users/vchechai/work/lem-in/cmake-build-debug /Users/vchechai/work/lem-in/cmake-build-debug/CMakeFiles/lem_in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem_in.dir/depend

