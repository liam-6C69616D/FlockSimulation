cmake_minimum_required(VERSION 3.29)
project(BacterialSim C)

add_executable(BacterialSim src/draw.c src/bacterial_sim.c)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
target_include_directories(BacterialSim PRIVATE include)
target_link_libraries(BacterialSim m raylib)