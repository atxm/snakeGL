cmake_minimum_required(VERSION 3.10)

project(snakeGL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(snakeGL 
    main.cpp
    glad.c
    Program.cpp
    Shader.cpp
    Window.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/../include)

target_link_libraries(snakeGL glfw)

find_package(OpenGL REQUIRED)
if (NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()
find_package(glfw3 REQUIRED)
if (NOT glfw3_FOUND)
    message(FATAL_ERROR "GLFW not found")
endif()
