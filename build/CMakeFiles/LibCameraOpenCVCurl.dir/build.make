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
include CMakeFiles/LibCameraOpenCVCurl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LibCameraOpenCVCurl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LibCameraOpenCVCurl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LibCameraOpenCVCurl.dir/flags.make

CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/flags.make
CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o: /home/myPi/Desktop/rubikRobot/src/main.cpp
CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o -MF CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o.d -o CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o -c /home/myPi/Desktop/rubikRobot/src/main.cpp

CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/main.cpp > CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.i

CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/main.cpp -o CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.s

CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/flags.make
CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o: /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp
CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o -MF CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o.d -o CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o -c /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp

CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp > CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.i

CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/imageProcess.cpp -o CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.s

CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/flags.make
CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o: /home/myPi/Desktop/rubikRobot/src/servo.cpp
CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o -MF CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o.d -o CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o -c /home/myPi/Desktop/rubikRobot/src/servo.cpp

CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/servo.cpp > CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.i

CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/servo.cpp -o CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.s

CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/flags.make
CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o: /home/myPi/Desktop/rubikRobot/src/takePicture.cpp
CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o: CMakeFiles/LibCameraOpenCVCurl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o -MF CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o.d -o CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o -c /home/myPi/Desktop/rubikRobot/src/takePicture.cpp

CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myPi/Desktop/rubikRobot/src/takePicture.cpp > CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.i

CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myPi/Desktop/rubikRobot/src/takePicture.cpp -o CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.s

# Object files for target LibCameraOpenCVCurl
LibCameraOpenCVCurl_OBJECTS = \
"CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o" \
"CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o" \
"CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o" \
"CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o"

# External object files for target LibCameraOpenCVCurl
LibCameraOpenCVCurl_EXTERNAL_OBJECTS =

LibCameraOpenCVCurl: CMakeFiles/LibCameraOpenCVCurl.dir/src/main.cpp.o
LibCameraOpenCVCurl: CMakeFiles/LibCameraOpenCVCurl.dir/src/imageProcess.cpp.o
LibCameraOpenCVCurl: CMakeFiles/LibCameraOpenCVCurl.dir/src/servo.cpp.o
LibCameraOpenCVCurl: CMakeFiles/LibCameraOpenCVCurl.dir/src/takePicture.cpp.o
LibCameraOpenCVCurl: CMakeFiles/LibCameraOpenCVCurl.dir/build.make
LibCameraOpenCVCurl: /usr/local/lib/libopencv_gapi.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_highgui.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_ml.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_objdetect.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_photo.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_stitching.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_video.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_videoio.so.4.10.0
LibCameraOpenCVCurl: /usr/lib/aarch64-linux-gnu/libcurl.so
LibCameraOpenCVCurl: /usr/local/lib/aarch64-linux-gnu/libcamera.so
LibCameraOpenCVCurl: /usr/local/lib/aarch64-linux-gnu/libcamera-base.so
LibCameraOpenCVCurl: /usr/local/lib/libopencv_imgcodecs.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_dnn.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_calib3d.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_features2d.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_flann.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_imgproc.so.4.10.0
LibCameraOpenCVCurl: /usr/local/lib/libopencv_core.so.4.10.0
LibCameraOpenCVCurl: CMakeFiles/LibCameraOpenCVCurl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/myPi/Desktop/rubikRobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable LibCameraOpenCVCurl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibCameraOpenCVCurl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LibCameraOpenCVCurl.dir/build: LibCameraOpenCVCurl
.PHONY : CMakeFiles/LibCameraOpenCVCurl.dir/build

CMakeFiles/LibCameraOpenCVCurl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LibCameraOpenCVCurl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LibCameraOpenCVCurl.dir/clean

CMakeFiles/LibCameraOpenCVCurl.dir/depend:
	cd /home/myPi/Desktop/rubikRobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/myPi/Desktop/rubikRobot /home/myPi/Desktop/rubikRobot /home/myPi/Desktop/rubikRobot/build /home/myPi/Desktop/rubikRobot/build /home/myPi/Desktop/rubikRobot/build/CMakeFiles/LibCameraOpenCVCurl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LibCameraOpenCVCurl.dir/depend

