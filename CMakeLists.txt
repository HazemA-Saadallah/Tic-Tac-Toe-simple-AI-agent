set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe_AI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_executable(main main.cxx)
target_link_libraries(main PRIVATE tic_tac_toe)

