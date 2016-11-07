cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/tests.cpp)

FILE(GLOB TEST_SOURCES src/*_test.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ${TEST_SOURCES})

include_directories(include)
include_directories(../interpreter/src)

add_executable(tests ${SOURCE_FILES})
