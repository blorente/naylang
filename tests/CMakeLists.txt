#
# Copyright (c) 2016 by Borja Lorente.
# Distributed under the GPLv3 license.
#

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB_RECURSE TEST_SOURCES *_test.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ${TEST_SOURCES})

FILE(GLOB_RECURSE MODEL_SOURCES ../interpreter/src/model/*.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ${MODEL_SOURCES})

include_directories(include)
include_directories(../interpreter/src)

add_executable(tests ${SOURCE_FILES})
