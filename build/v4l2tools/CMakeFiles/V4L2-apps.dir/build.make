# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/workspace/V4L2-apps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/workspace/V4L2-apps/build

# Include any dependencies generated for this target.
include v4l2tools/CMakeFiles/V4L2-apps.dir/depend.make

# Include the progress variables for this target.
include v4l2tools/CMakeFiles/V4L2-apps.dir/progress.make

# Include the compile flags for this target's objects.
include v4l2tools/CMakeFiles/V4L2-apps.dir/flags.make

v4l2tools/CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.o: v4l2tools/CMakeFiles/V4L2-apps.dir/flags.make
v4l2tools/CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.o: ../v4l2tools/src/v4l2compress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/workspace/V4L2-apps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object v4l2tools/CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.o"
	cd /home/pi/workspace/V4L2-apps/build/v4l2tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.o -c /home/pi/workspace/V4L2-apps/v4l2tools/src/v4l2compress.cpp

v4l2tools/CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.i"
	cd /home/pi/workspace/V4L2-apps/build/v4l2tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/workspace/V4L2-apps/v4l2tools/src/v4l2compress.cpp > CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.i

v4l2tools/CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.s"
	cd /home/pi/workspace/V4L2-apps/build/v4l2tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/workspace/V4L2-apps/v4l2tools/src/v4l2compress.cpp -o CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.s

# Object files for target V4L2-apps
V4L2__apps_OBJECTS = \
"CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.o"

# External object files for target V4L2-apps
V4L2__apps_EXTERNAL_OBJECTS =

v4l2tools/V4L2-apps: v4l2tools/CMakeFiles/V4L2-apps.dir/src/v4l2compress.cpp.o
v4l2tools/V4L2-apps: v4l2tools/CMakeFiles/V4L2-apps.dir/build.make
v4l2tools/V4L2-apps: v4l2tools/v4l2wrapper/libv4l2wrapper.a
v4l2tools/V4L2-apps: /usr/lib/aarch64-linux-gnu/libjpeg.so
v4l2tools/V4L2-apps: v4l2tools/libyuv/libyuv.a
v4l2tools/V4L2-apps: v4l2tools/CMakeFiles/V4L2-apps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/workspace/V4L2-apps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable V4L2-apps"
	cd /home/pi/workspace/V4L2-apps/build/v4l2tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/V4L2-apps.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
v4l2tools/CMakeFiles/V4L2-apps.dir/build: v4l2tools/V4L2-apps

.PHONY : v4l2tools/CMakeFiles/V4L2-apps.dir/build

v4l2tools/CMakeFiles/V4L2-apps.dir/clean:
	cd /home/pi/workspace/V4L2-apps/build/v4l2tools && $(CMAKE_COMMAND) -P CMakeFiles/V4L2-apps.dir/cmake_clean.cmake
.PHONY : v4l2tools/CMakeFiles/V4L2-apps.dir/clean

v4l2tools/CMakeFiles/V4L2-apps.dir/depend:
	cd /home/pi/workspace/V4L2-apps/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/workspace/V4L2-apps /home/pi/workspace/V4L2-apps/v4l2tools /home/pi/workspace/V4L2-apps/build /home/pi/workspace/V4L2-apps/build/v4l2tools /home/pi/workspace/V4L2-apps/build/v4l2tools/CMakeFiles/V4L2-apps.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : v4l2tools/CMakeFiles/V4L2-apps.dir/depend

