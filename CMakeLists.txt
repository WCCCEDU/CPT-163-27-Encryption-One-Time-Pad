cmake_minimum_required(VERSION 3.3)
project(one_time_pad_cypher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES main.cpp one_time_pad.cpp one_time_pad.h)
add_executable(one_time_pad_cypher ${SOURCE_FILES})
