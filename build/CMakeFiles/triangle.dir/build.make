# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/seanyan/Documents/practice/OpenGL_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seanyan/Documents/practice/OpenGL_c/build

# Include any dependencies generated for this target.
include CMakeFiles/triangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/triangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/triangle.dir/flags.make

CMakeFiles/triangle.dir/triangle.cpp.o: CMakeFiles/triangle.dir/flags.make
CMakeFiles/triangle.dir/triangle.cpp.o: ../triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seanyan/Documents/practice/OpenGL_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/triangle.dir/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/triangle.dir/triangle.cpp.o -c /home/seanyan/Documents/practice/OpenGL_c/triangle.cpp

CMakeFiles/triangle.dir/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/triangle.dir/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seanyan/Documents/practice/OpenGL_c/triangle.cpp > CMakeFiles/triangle.dir/triangle.cpp.i

CMakeFiles/triangle.dir/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/triangle.dir/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seanyan/Documents/practice/OpenGL_c/triangle.cpp -o CMakeFiles/triangle.dir/triangle.cpp.s

CMakeFiles/triangle.dir/triangle.cpp.o.requires:

.PHONY : CMakeFiles/triangle.dir/triangle.cpp.o.requires

CMakeFiles/triangle.dir/triangle.cpp.o.provides: CMakeFiles/triangle.dir/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/triangle.dir/build.make CMakeFiles/triangle.dir/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/triangle.dir/triangle.cpp.o.provides

CMakeFiles/triangle.dir/triangle.cpp.o.provides.build: CMakeFiles/triangle.dir/triangle.cpp.o


# Object files for target triangle
triangle_OBJECTS = \
"CMakeFiles/triangle.dir/triangle.cpp.o"

# External object files for target triangle
triangle_EXTERNAL_OBJECTS =

triangle: CMakeFiles/triangle.dir/triangle.cpp.o
triangle: CMakeFiles/triangle.dir/build.make
triangle: /usr/lib/x86_64-linux-gnu/libGLU.so
triangle: /usr/lib/x86_64-linux-gnu/libGL.so
triangle: /usr/lib/x86_64-linux-gnu/libglut.so
triangle: /usr/lib/x86_64-linux-gnu/libXmu.so
triangle: /usr/lib/x86_64-linux-gnu/libXi.so
triangle: CMakeFiles/triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seanyan/Documents/practice/OpenGL_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable triangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/triangle.dir/build: triangle

.PHONY : CMakeFiles/triangle.dir/build

CMakeFiles/triangle.dir/requires: CMakeFiles/triangle.dir/triangle.cpp.o.requires

.PHONY : CMakeFiles/triangle.dir/requires

CMakeFiles/triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/triangle.dir/clean

CMakeFiles/triangle.dir/depend:
	cd /home/seanyan/Documents/practice/OpenGL_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seanyan/Documents/practice/OpenGL_c /home/seanyan/Documents/practice/OpenGL_c /home/seanyan/Documents/practice/OpenGL_c/build /home/seanyan/Documents/practice/OpenGL_c/build /home/seanyan/Documents/practice/OpenGL_c/build/CMakeFiles/triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/triangle.dir/depend

