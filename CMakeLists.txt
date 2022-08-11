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

# Add program target called sphere
add_executable(test_sphere lib/sphere.cpp test_sphere.cpp)

# Add include directories
target_include_directories(test_sphere PUBLIC include)

# Link random program to catch for testing
target_link_libraries(test_sphere Catch2::Catch2)

# Add program target called sphere_collision
add_executable(sphere_collision app/sphere_collision.cpp)
target_link_libraries(sphere_collision OpenGL::GL)
target_link_libraries(sphere_collision GLEW::GLEW)
target_link_libraries(sphere_collision glfw)

