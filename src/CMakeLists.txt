cmake_minimum_required(VERSION 3.22.2)
project(endless-driver)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} main.c)
add_library(func func.c)
add_library(game_elements game_elements.c)

target_link_libraries(${PROJECT_NAME} func game_elements SDL2::SDL2 SDL2_mixer SDL2_ttf SDL2_image)
