# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eld/algolab/week3/firsthit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eld/algolab/week3/firsthit

# Include any dependencies generated for this target.
include CMakeFiles/firsthit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/firsthit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firsthit.dir/flags.make

CMakeFiles/firsthit.dir/firsthit.cpp.o: CMakeFiles/firsthit.dir/flags.make
CMakeFiles/firsthit.dir/firsthit.cpp.o: firsthit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eld/algolab/week3/firsthit/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/firsthit.dir/firsthit.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firsthit.dir/firsthit.cpp.o -c /home/eld/algolab/week3/firsthit/firsthit.cpp

CMakeFiles/firsthit.dir/firsthit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firsthit.dir/firsthit.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eld/algolab/week3/firsthit/firsthit.cpp > CMakeFiles/firsthit.dir/firsthit.cpp.i

CMakeFiles/firsthit.dir/firsthit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firsthit.dir/firsthit.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eld/algolab/week3/firsthit/firsthit.cpp -o CMakeFiles/firsthit.dir/firsthit.cpp.s

# Object files for target firsthit
firsthit_OBJECTS = \
"CMakeFiles/firsthit.dir/firsthit.cpp.o"

# External object files for target firsthit
firsthit_EXTERNAL_OBJECTS =

firsthit: CMakeFiles/firsthit.dir/firsthit.cpp.o
firsthit: CMakeFiles/firsthit.dir/build.make
firsthit: /usr/lib/libmpfr.so
firsthit: /usr/lib/libgmp.so
firsthit: /usr/lib/libCGAL_Core.so.13.0.2
firsthit: /usr/lib/libboost_thread.so
firsthit: /usr/lib/libboost_system.so
firsthit: /usr/lib/libboost_chrono.so
firsthit: /usr/lib/libboost_date_time.so
firsthit: /usr/lib/libboost_atomic.so
firsthit: /usr/lib/libCGAL.so.13.0.2
firsthit: /usr/lib/libboost_thread.so
firsthit: /usr/lib/libboost_system.so
firsthit: /usr/lib/libboost_chrono.so
firsthit: /usr/lib/libboost_date_time.so
firsthit: /usr/lib/libboost_atomic.so
firsthit: /usr/lib/libmpfr.so
firsthit: /usr/lib/libgmp.so
firsthit: /usr/lib/libboost_thread.so
firsthit: /usr/lib/libboost_chrono.so
firsthit: /usr/lib/libboost_system.so
firsthit: /usr/lib/libboost_date_time.so
firsthit: /usr/lib/libboost_atomic.so
firsthit: CMakeFiles/firsthit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eld/algolab/week3/firsthit/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable firsthit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/firsthit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firsthit.dir/build: firsthit

.PHONY : CMakeFiles/firsthit.dir/build

CMakeFiles/firsthit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firsthit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firsthit.dir/clean

CMakeFiles/firsthit.dir/depend:
	cd /home/eld/algolab/week3/firsthit && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eld/algolab/week3/firsthit /home/eld/algolab/week3/firsthit /home/eld/algolab/week3/firsthit /home/eld/algolab/week3/firsthit /home/eld/algolab/week3/firsthit/CMakeFiles/firsthit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firsthit.dir/depend
