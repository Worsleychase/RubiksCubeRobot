cmake_minimum_required(VERSION 3.10)

# Set the project name
project(rubikSolver)

set(CURL_INCLUDE_DIR "/usr/include/aarch64-linux-gnu/curl")
set(CURL_LIBRARY "/usr/lib/aarch64-linux-gnu/libcurl.so")

set(LIBCAMERA_INCLUDE_DIR "/usr/local/include/libcamera")
set(LIBCAMERA_LIBRARY "/usr/local/lib/aarch64-linux-gnu/libcamera.so")

# You may also need the base library
set(LIBCAMERA_BASE_LIBRARY "/usr/local/lib/aarch64-linux-gnu/libcamera-base.so")

# Find required libraries
find_package(OpenCV REQUIRED)
find_package(CURL REQUIRED)

# Check if libcamera is available
find_library(LIBCAMERA_LIBRARY NAMES libcamera)
find_path(LIBCAMERA_INCLUDE_DIR NAMES camera.h)

# Find the wiringPi library
find_library(WIRINGPI_LIBRARY NAMES wiringPi)

# Print error if libcamera or wiringPi is not found
if(NOT LIBCAMERA_LIBRARY OR NOT LIBCAMERA_INCLUDE_DIR)
    message(FATAL_ERROR "libcamera not found. Please install libcamera-dev.")
endif()

if(NOT WIRINGPI_LIBRARY)
    message(FATAL_ERROR "wiringPi library not found. Please install wiringPi.")
endif()

# Include directories
# Include your project's header files directory
include_directories(
    ${PROJECT_SOURCE_DIR}/include    # Custom headers like piece.hpp, cube.hpp, etc.
    ${OpenCV_INCLUDE_DIRS}           # OpenCV headers
    ${LIBCAMERA_INCLUDE_DIR}         # libcamera headers
    ${CURL_INCLUDE_DIRS}             # cURL headers
)

# Define the source files
set(SOURCES
    src/main.cpp        # Main entry point
    src/imageProcess.cpp
    src/pca9685.cpp
)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${CURL_LIBRARIES}
    ${LIBCAMERA_LIBRARY}
    ${LIBCAMERA_BASE_LIBRARY}
    ${WIRINGPI_LIBRARY}  # Link wiringPi library
)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
