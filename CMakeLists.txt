cmake_minimum_required(VERSION 3.0)
project(rubikRobot)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(rubikRobot main.cpp)

target_link_libraries(rubikRobot ${OpenCV_LIBS})