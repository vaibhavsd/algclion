cmake_minimum_required(VERSION 3.8)
project(algclion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp week1.cpp week21.cpp week22.cpp week23.cpp week24.cpp week25.cpp week26.cpp week27.cpp week3concepts.cpp)


add_executable(algclion ${SOURCE_FILES})
add_executable(week1 week1.cpp)
add_executable(week21 week21.cpp)
add_executable(week22 week22.cpp)
add_executable(week23 week23.cpp)
add_executable(week24 week24.cpp)
add_executable(week25 week25.cpp)

add_executable(week26 week26.cpp)
add_executable(week27 week27.cpp)
add_executable(week3concepts week3concepts.cpp)