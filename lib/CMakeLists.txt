cmake_minimum_required(VERSION 3.10)
add_library(tic_tac_toe STATIC tic_tac_toe.cxx)
target_include_directories(tic_tac_toe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
