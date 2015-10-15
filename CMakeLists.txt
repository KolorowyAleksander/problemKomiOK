cmake_minimum_required(VERSION 3.3)
project(problemKomiOK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graf.cpp Graf.h)
add_executable(problemKomiOK ${SOURCE_FILES})