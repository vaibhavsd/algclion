cmake_minimum_required(VERSION 3.8)
project(algclion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp week1.cpp week21.cpp week22.cpp week23.cpp week24.cpp week25.cpp week26.cpp week27.cpp week31_change.cpp fuel.cpp week32_fractional_knapsack.cpp week33_dot_product.cpp week36_largest_number.cpp week35_different_summands.cpp week34.cpp .idea/week41.cpp)


add_executable(algclion ${SOURCE_FILES})
add_executable(week1 week1.cpp)
add_executable(week21 week21.cpp)
add_executable(week22 week22.cpp)
add_executable(week23 week23.cpp)
add_executable(week24 week24.cpp)
add_executable(week25 week25.cpp)

add_executable(week26 week26.cpp)
add_executable(week27 week27.cpp)

add_executable(week31_change week31_change.cpp)
add_executable(fuel fuel.cpp)
add_executable(week32_fractional_knapsack week32_fractional_knapsack.cpp)
add_executable(week33_dot_product week33_dot_product.cpp)
add_executable(week36_largest_number week36_largest_number.cpp)
add_executable(week35_different_summands week35_different_summands.cpp)
add_executable(week34 week34.cpp)

add_executable(week41 .idea/week41.cpp)