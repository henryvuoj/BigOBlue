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
add_executable(class2_george_and_round class2_big-o/george_and_round.cpp)
add_executable(class2_v class2_big-o/book.cpp)
add_executable(class2_vest class2_big-o/vest.cpp)
add_executable(class2_sereja_dima class2_big-o/sereja_dima.cpp)
add_executable(class2_approx_const class2_big-o/approx_const.cpp)
add_executable(class2_wrath class2_big-o/wrath.cpp)
add_executable(class2_alice_bob_chocolate class2_big-o/alice_bob_chocolate.cpp)
add_executable(class3_devu class3_sorting/devu.cpp)
add_executable(class3_chores class3_sorting/chores.cpp)
add_executable(class3_sort_array class3_sorting/sort_array.cpp)
add_executable(class3_gukiz class3_sorting/gukiz.cpp)
add_executable(class3_pasha class3_sorting/pasha.cpp)
add_executable(class5_shortest_reach class5_BFS/shortest_reach.cpp)
add_executable(class6_bishu_gf class6_DFS/bishu_gf.cpp)