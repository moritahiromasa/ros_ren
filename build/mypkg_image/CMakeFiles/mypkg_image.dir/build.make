# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ubuntu/ros_ren/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ros_ren/build

# Include any dependencies generated for this target.
include mypkg_image/CMakeFiles/mypkg_image.dir/depend.make

# Include the progress variables for this target.
include mypkg_image/CMakeFiles/mypkg_image.dir/progress.make

# Include the compile flags for this target's objects.
include mypkg_image/CMakeFiles/mypkg_image.dir/flags.make

mypkg_image/CMakeFiles/mypkg_image.dir/src/detectFace.cpp.o: mypkg_image/CMakeFiles/mypkg_image.dir/flags.make
mypkg_image/CMakeFiles/mypkg_image.dir/src/detectFace.cpp.o: /home/ubuntu/ros_ren/src/mypkg_image/src/detectFace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ros_ren/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mypkg_image/CMakeFiles/mypkg_image.dir/src/detectFace.cpp.o"
	cd /home/ubuntu/ros_ren/build/mypkg_image && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mypkg_image.dir/src/detectFace.cpp.o -c /home/ubuntu/ros_ren/src/mypkg_image/src/detectFace.cpp

mypkg_image/CMakeFiles/mypkg_image.dir/src/detectFace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mypkg_image.dir/src/detectFace.cpp.i"
	cd /home/ubuntu/ros_ren/build/mypkg_image && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ros_ren/src/mypkg_image/src/detectFace.cpp > CMakeFiles/mypkg_image.dir/src/detectFace.cpp.i

mypkg_image/CMakeFiles/mypkg_image.dir/src/detectFace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mypkg_image.dir/src/detectFace.cpp.s"
	cd /home/ubuntu/ros_ren/build/mypkg_image && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ros_ren/src/mypkg_image/src/detectFace.cpp -o CMakeFiles/mypkg_image.dir/src/detectFace.cpp.s

# Object files for target mypkg_image
mypkg_image_OBJECTS = \
"CMakeFiles/mypkg_image.dir/src/detectFace.cpp.o"

# External object files for target mypkg_image
mypkg_image_EXTERNAL_OBJECTS =

mypkg_image/mypkg_image: mypkg_image/CMakeFiles/mypkg_image.dir/src/detectFace.cpp.o
mypkg_image/mypkg_image: mypkg_image/CMakeFiles/mypkg_image.dir/build.make
mypkg_image/mypkg_image: mypkg_image/CMakeFiles/mypkg_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ros_ren/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mypkg_image"
	cd /home/ubuntu/ros_ren/build/mypkg_image && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mypkg_image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mypkg_image/CMakeFiles/mypkg_image.dir/build: mypkg_image/mypkg_image

.PHONY : mypkg_image/CMakeFiles/mypkg_image.dir/build

mypkg_image/CMakeFiles/mypkg_image.dir/clean:
	cd /home/ubuntu/ros_ren/build/mypkg_image && $(CMAKE_COMMAND) -P CMakeFiles/mypkg_image.dir/cmake_clean.cmake
.PHONY : mypkg_image/CMakeFiles/mypkg_image.dir/clean

mypkg_image/CMakeFiles/mypkg_image.dir/depend:
	cd /home/ubuntu/ros_ren/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ros_ren/src /home/ubuntu/ros_ren/src/mypkg_image /home/ubuntu/ros_ren/build /home/ubuntu/ros_ren/build/mypkg_image /home/ubuntu/ros_ren/build/mypkg_image/CMakeFiles/mypkg_image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mypkg_image/CMakeFiles/mypkg_image.dir/depend

