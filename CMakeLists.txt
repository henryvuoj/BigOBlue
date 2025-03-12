cmake_minimum_required(VERSION 3.30)
project(BigOBlue)

set(CMAKE_CXX_STANDARD 20)

add_executable(class1_test class1_dynamic-array/test/test.cpp
        class1_dynamic-array/test/test.h
        class1_dynamic-array/fashion_in_berland/fashion_in_berland.cpp)

add_executable(class1_fashion_in_berlan class1_dynamic-array/fashion_in_berland/fashion_in_berland.cpp)
add_executable(class1_night_at_museum class1_dynamic-array/night_at_museum/night_at_museum.cpp)
add_executable(class1_bear_and_game class1_dynamic-array/bear_and_game/bear_and_game.cpp)