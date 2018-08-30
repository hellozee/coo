cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_STANDARD_LIBRARIES "-lm")

project(coo)

add_executable(
    coo
    src/main.c
    src/math/vector.c
    src/image/image.c
    src/math/ray.c
    src/camera/camera.c
)
