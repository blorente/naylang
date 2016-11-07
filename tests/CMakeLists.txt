cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/tests.cpp src/Literal_test.cpp src/ExpArithmetic_test.cpp src/ArithmeticOperation_test.cpp
        src/ComparisonOperation_test.cpp src/ExpBoolean.cpp src/ExpConditional_test.cpp)

include_directories(include)
include_directories(../interpreter/src)

add_executable(tests ${SOURCE_FILES})