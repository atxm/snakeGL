cmake_minimum_required(VERSION 3.10)

project(snakeGL)

set(INCL_DIR ${PROJECT_BINARY_DIR}/include)
set(LIB_DIR ${PROJECT_BINARY_DIR}/lib)

find_package(glfw3 REQUIRED)

include_directories(${INCL_DIR})

file(GLOB SOURCES "src/*.cpp" "src/*.c")

add_executable(snakeGL ${SOURCES})

link_directories(${PROJECT_BINARY_DIR}/lib)

target_link_libraries(snakeGL PRIVATE glfw)