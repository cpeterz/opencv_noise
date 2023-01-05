cmake_minimum_required(VERSION 2.8)

project(test)

find_package(OpenCV REQUIRED)

add_executable(kernel1 kernel.cpp)

target_link_libraries(kernel1 ${OpenCV_LIBS})