# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/myPi/Desktop/rubikRobot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/myPi/Desktop/rubikRobot/build

# Include any dependencies generated for this target.
include CMakeFiles/rubikSolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rubikSolver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rubikSolver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rubikSolver.dir/flags.make

CMakeFiles/rubikSolver.dir/src/main.cpp.o: CMakeFiles/rubikSolver.dir/flags.make
CMakeFiles/rubikSolver.dir/src/main.cpp.o: /home/myPi/Desktop/rubikRobot/src/main.cpp
CMakeFiles/rubikSolver.dir/src/main.cpp.o: CMakeFiles/rubikSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rubikSolver.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rubikSolver.dir/src/main.cpp.o -MF CMakeFiles/rubikSolver.dir/src/main.cpp.o.d -o CMakeFiles/rubikSolver.dir/src/main.cpp.o -c /home/myPi/Desktop/rubikRobot/src/main.cpp

CMakeFiles/rubikSolver.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rubikSolver.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/main.cpp > CMakeFiles/rubikSolver.dir/src/main.cpp.i

CMakeFiles/rubikSolver.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rubikSolver.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/main.cpp -o CMakeFiles/rubikSolver.dir/src/main.cpp.s

CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o: CMakeFiles/rubikSolver.dir/flags.make
CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o: /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp
CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o: CMakeFiles/rubikSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o -MF CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o.d -o CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o -c /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp

CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp > CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.i

CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp -o CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.s

CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o: CMakeFiles/rubikSolver.dir/flags.make
CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o: /home/myPi/Desktop/rubikRobot/src/pca9685.cpp
CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o: CMakeFiles/rubikSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o -MF CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o.d -o CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o -c /home/myPi/Desktop/rubikRobot/src/pca9685.cpp

CMakeFiles/rubikSolver.dir/src/pca9685.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rubikSolver.dir/src/pca9685.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/pca9685.cpp > CMakeFiles/rubikSolver.dir/src/pca9685.cpp.i

CMakeFiles/rubikSolver.dir/src/pca9685.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rubikSolver.dir/src/pca9685.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/pca9685.cpp -o CMakeFiles/rubikSolver.dir/src/pca9685.cpp.s

# Object files for target rubikSolver
rubikSolver_OBJECTS = \
"CMakeFiles/rubikSolver.dir/src/main.cpp.o" \
"CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o" \
"CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o"

# External object files for target rubikSolver
rubikSolver_EXTERNAL_OBJECTS =

rubikSolver: CMakeFiles/rubikSolver.dir/src/main.cpp.o
rubikSolver: CMakeFiles/rubikSolver.dir/src/imageProcess.cpp.o
rubikSolver: CMakeFiles/rubikSolver.dir/src/pca9685.cpp.o
rubikSolver: CMakeFiles/rubikSolver.dir/build.make
rubikSolver: /usr/local/lib/libopencv_gapi.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_highgui.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_ml.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_objdetect.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_photo.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_stitching.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_video.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_videoio.so.4.10.0
rubikSolver: /usr/lib/aarch64-linux-gnu/libcurl.so
rubikSolver: /usr/local/lib/aarch64-linux-gnu/libcamera.so
rubikSolver: /usr/local/lib/aarch64-linux-gnu/libcamera-base.so
rubikSolver: /usr/local/lib/libwiringPi.so
rubikSolver: /usr/local/lib/libopencv_imgcodecs.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_dnn.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_calib3d.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_features2d.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_flann.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_imgproc.so.4.10.0
rubikSolver: /usr/local/lib/libopencv_core.so.4.10.0
rubikSolver: CMakeFiles/rubikSolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable rubikSolver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rubikSolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rubikSolver.dir/build: rubikSolver
.PHONY : CMakeFiles/rubikSolver.dir/build

CMakeFiles/rubikSolver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rubikSolver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rubikSolver.dir/clean

CMakeFiles/rubikSolver.dir/depend:
	cd /home/myPi/Desktop/rubikRobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/myPi/Desktop/rubikRobot /home/myPi/Desktop/rubikRobot /home/myPi/Desktop/rubikRobot/build /home/myPi/Desktop/rubikRobot/build /home/myPi/Desktop/rubikRobot/build/CMakeFiles/rubikSolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rubikSolver.dir/depend
