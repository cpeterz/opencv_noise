cmake_minimum_required(VERSION 2.8)

project(test)

find_package(OpenCV REQUIRED)

add_executable(jiaoyan jiaoyan.cpp)

target_link_libraries(jiaoyan ${OpenCV_LIBS})