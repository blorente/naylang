#
# Copyright (c) 2016 by Borja Lorente.
# Distributed under the GPLv3 license.
#
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp)

include_directories(include)

# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_antlrcpptest})

execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/generate.sh)

add_executable(interpreter ${SOURCE_FILES} ${antlr4cpp_src_files_naylang})
add_dependencies(interpreter antlr4cpp antlr4cpp_generation_naylang)
target_link_libraries(interpreter antlr4-runtime)
