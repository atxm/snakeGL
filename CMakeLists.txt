cmake_minimum_required(VERSION 3.10)

project(snakeGL)

# Set the include and library directories
set(INCL_DIR ${PROJECT_BINARY_DIR}/include)
set(LIB_DIR ${PROJECT_BINARY_DIR}/lib)

# Add the GLFW include directory (adjust the path if necessary)
include_directories(${CMAKE_SOURCE_DIR}/GLFW)

# Specify the executable
add_executable(snakeGL main.cpp)

# Link against the GLFW library (adjust the library name if necessary)
target_link_libraries(snakeGL glfw)

find_package(glfw3 REQUIRED)