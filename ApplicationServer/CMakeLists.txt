cmake_minimum_required(VERSION 3.7)
project(ApplicationServer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/controllers/HelloWorldController.cpp src/controllers/HelloWorldController.h)
add_executable(ApplicationServer ${SOURCE_FILES})