cmake_minimum_required(VERSION 3.22.2)
project(endless-driver)

find_package(SDL2 REQUIRED)
add_compile_options(-Wall -pedantic -Werror -Wshadow -O4)

add_executable(${PROJECT_NAME} main.c func.c game_elements.c)
add_library(func func.c)
add_library(game_elements game_elements.c)

target_link_libraries(${PROJECT_NAME} game_elements func SDL2::SDL2 SDL2_mixer SDL2_ttf SDL2_image)

# crosscompile command
add_custom_target(cross
  COMMAND x86_64-w64-mingw32-gcc ${CMAKE_C_FLAGS} ~/code/remake-Endless-Driver/src/main.c ~/code/remake-Endless-Driver/src/func.c ~/code/remake-Endless-Driver/src/game_elements.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o windows/endless-driver
  )
