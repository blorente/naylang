#
# Copyright (c) 2016 by Borja Lorente.
# Distributed under the GPLv3 license.
#

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB_RECURSE TEST_SOURCES *_test.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ${TEST_SOURCES})

# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_naylang})

include_directories(include)
include_directories(../interpreter/src)

FILE(GLOB_RECURSE MODEL_SOURCES ../interpreter/src/model/*.cpp)
#FILE(GLOB_RECURSE MODEL_SOURCES ../interpreter/src/parser/*.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ${MODEL_SOURCES})

add_executable(tests ${SOURCE_FILES} ${antlr4cpp_src_files_naylang})
add_dependencies(tests antlr4cpp antlr4cpp_generation_naylang)
target_link_libraries(tests antlr4-runtime)
