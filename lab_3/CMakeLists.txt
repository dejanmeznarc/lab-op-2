cmake_minimum_required(VERSION 3.24)
project(lab_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_3 main.c libs/bitmap/bitmap.c)

target_link_libraries(${PROJECT_NAME} m)
