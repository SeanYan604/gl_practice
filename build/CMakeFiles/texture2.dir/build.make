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
include CMakeFiles/texture2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/texture2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/texture2.dir/flags.make

CMakeFiles/texture2.dir/texture2.cpp.o: CMakeFiles/texture2.dir/flags.make
CMakeFiles/texture2.dir/texture2.cpp.o: ../texture2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seanyan/Documents/practice/OpenGL_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/texture2.dir/texture2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/texture2.dir/texture2.cpp.o -c /home/seanyan/Documents/practice/OpenGL_c/texture2.cpp

CMakeFiles/texture2.dir/texture2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture2.dir/texture2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seanyan/Documents/practice/OpenGL_c/texture2.cpp > CMakeFiles/texture2.dir/texture2.cpp.i

CMakeFiles/texture2.dir/texture2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture2.dir/texture2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seanyan/Documents/practice/OpenGL_c/texture2.cpp -o CMakeFiles/texture2.dir/texture2.cpp.s

CMakeFiles/texture2.dir/texture2.cpp.o.requires:

.PHONY : CMakeFiles/texture2.dir/texture2.cpp.o.requires

CMakeFiles/texture2.dir/texture2.cpp.o.provides: CMakeFiles/texture2.dir/texture2.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture2.dir/build.make CMakeFiles/texture2.dir/texture2.cpp.o.provides.build
.PHONY : CMakeFiles/texture2.dir/texture2.cpp.o.provides

CMakeFiles/texture2.dir/texture2.cpp.o.provides.build: CMakeFiles/texture2.dir/texture2.cpp.o


# Object files for target texture2
texture2_OBJECTS = \
"CMakeFiles/texture2.dir/texture2.cpp.o"

# External object files for target texture2
texture2_EXTERNAL_OBJECTS =

texture2: CMakeFiles/texture2.dir/texture2.cpp.o
texture2: CMakeFiles/texture2.dir/build.make
texture2: /usr/lib/x86_64-linux-gnu/libGLU.so
texture2: /usr/lib/x86_64-linux-gnu/libGL.so
texture2: /usr/lib/x86_64-linux-gnu/libglut.so
texture2: /usr/lib/x86_64-linux-gnu/libXmu.so
texture2: /usr/lib/x86_64-linux-gnu/libXi.so
texture2: CMakeFiles/texture2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seanyan/Documents/practice/OpenGL_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable texture2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/texture2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/texture2.dir/build: texture2

.PHONY : CMakeFiles/texture2.dir/build

CMakeFiles/texture2.dir/requires: CMakeFiles/texture2.dir/texture2.cpp.o.requires

.PHONY : CMakeFiles/texture2.dir/requires

CMakeFiles/texture2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/texture2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/texture2.dir/clean

CMakeFiles/texture2.dir/depend:
	cd /home/seanyan/Documents/practice/OpenGL_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seanyan/Documents/practice/OpenGL_c /home/seanyan/Documents/practice/OpenGL_c /home/seanyan/Documents/practice/OpenGL_c/build /home/seanyan/Documents/practice/OpenGL_c/build /home/seanyan/Documents/practice/OpenGL_c/build/CMakeFiles/texture2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/texture2.dir/depend

