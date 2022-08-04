# Specify minimum version required
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

# Specify project and C++
project(cpp_project LANGUAGES CXX)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)

# Get OpenGL, GLEW, and GLFW package
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Add program target called sphere_collision
add_executable(sphere_collision app/sphere_collision.cpp)
target_link_libraries(sphere_collision OpenGL::GL)
target_link_libraries(sphere_collision GLEW::GLEW)
target_link_libraries(sphere_collision glfw)

