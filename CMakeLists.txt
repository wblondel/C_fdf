cmake_minimum_required(VERSION 3.9)
project(02a_C_FdF C)

set(CMAKE_C_STANDARD 99)

add_custom_target(FranceM COMMAND make re
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )

include_directories(inc)
include_directories(libft/inc)
include_directories(libmlx)

add_executable(mlx2
        src/calculate.c
        src/cam.c
        src/clicks.c
        src/debug.c
        src/draw_map.c
        src/draw_ui.c
        src/hooks_init.c
        src/hooks_keyboard.c
        src/hooks_mouse.c
        src/hooks_others.c
        src/image.c
        src/import.c
        src/init.c
        src/keys.c
        src/main.c
        )