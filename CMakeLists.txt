cmake_minimum_required(VERSION 3.8)
project(algclion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp week1.cpp week21.cpp.cpp)
add_executable(algclion ${SOURCE_FILES})
add_executable(week1 week1.cpp)
add_executable(week21.cpp week21.cpp.cpp)