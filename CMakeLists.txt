cmake_minimum_required(VERSION 3.0)
project(coo)
set( CMAKE_BUILD_TYPE Debug)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

set( LIBRARY_TYPE SHARED)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra")
endif()

set( CAMERA_INCLUDE_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/camera )
set( IMAGE_INCLUDE_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/image )
set( MATH_INCLUDE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/math )
set( MESH_INCLUDE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/mesh )
set( RENDERER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/renderer )

link_directories( ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} )

set(CMAKE_C_STANDARD_LIBRARIES "-lm")

add_subdirectory(src/camera)
add_subdirectory(src/image)
add_subdirectory(src/math)
add_subdirectory(src/mesh)
add_subdirectory(src/renderer)

include_directories(
    ${CAMERA_INCLUDE_DIR}
    ${IMAGE_INCLUDE_DIR}
    ${MATH_INCLUDE_DIR}
    ${MESH_INCLUDE_DIR}
    ${RENDERER_INCLUDE_DIR}
)

add_executable(
    coo
    src/main.c
)

add_dependencies(
    coo
    renderer
    image
    math
    camera
    mesh
)

target_link_libraries(
    coo
    coo_renderer
    coo_image
    coo_math
    coo_camera
    coo_mesh
)

