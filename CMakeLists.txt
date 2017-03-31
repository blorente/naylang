#
# Copyright (c) 2016 by Borja Lorente.
# Distributed under the GPLv3 license.
#
cmake_minimum_required(VERSION 3.0)
project(naylang)

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr4-4.5.4-SNAPSHOT.jar)
# add external build for antlrcpp
include( ExternalAntlr4Cpp )
# add antrl4cpp artifacts to project environment
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(naylang naylang
  ${PROJECT_SOURCE_DIR}/grammars/TLexer.g4
  ${PROJECT_SOURCE_DIR}/grammars/TParser.g4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(interpreter)
add_subdirectory(tests)
