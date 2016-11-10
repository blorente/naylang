cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/tests.cpp)

FILE(GLOB_RECURSE TEST_SOURCES *_test.cpp)
message(STATUS ${TEST_SOURCES})
set(SOURCE_FILES ${SOURCE_FILES} ${TEST_SOURCES})

include_directories(include)
include_directories(../interpreter/src)

add_executable(tests ${SOURCE_FILES})
