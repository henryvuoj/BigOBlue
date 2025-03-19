cmake_minimum_required(VERSION 3.30)
project(BigOBlue)

set(CMAKE_CXX_STANDARD 20)

add_executable(class1_test class1_dynamic-array/test/test.cpp
        class1_dynamic-array/test/test.h
        class1_dynamic-array/fashion_in_berland/fashion_in_berland.cpp)

add_executable(class1_fashion_in_berlan class1_dynamic-array/fashion_in_berland/fashion_in_berland.cpp)
add_executable(class1_night_at_museum class1_dynamic-array/night_at_museum/night_at_museum.cpp)
add_executable(class1_bear_and_game class1_dynamic-array/bear_and_game/bear_and_game.cpp)
add_executable(class1_vitaly_string class1_dynamic-array/vitaly_string/vitaly_string.cpp)
add_executable(class1_array class1_dynamic-array/array/array.cpp)
add_executable(class1_segment class1_dynamic-array/segment/segment.cpp)
add_executable(class1_password class1_dynamic-array/password/password.cpp)
add_executable(class1_suffix_structure suffix_structure/suffix_structure.cpp)
add_executable(class2_array class2_big-o/array.cpp)
add_executable(class3_devu class3_sorting/devu.cpp)