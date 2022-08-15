# Specify minimum version required
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

# Specify project and C++
project(cpp_project LANGUAGES CXX)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)

# Get the catch2 package for unit testing
find_package(Catch2 REQUIRED)

# Get OpenGL and GLUT package
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Add program target called test_sphere
add_executable(test_sphere lib/sphere.cpp app/test_sphere.cpp)

# Add include directories
target_include_directories(test_sphere PUBLIC include)
target_link_libraries(test_sphere OpenGL::GL)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(test_sphere ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

# Include sanitizers file
# To enable sanitizers, add the command line option
# -DENABLE_ASAN=true or -DENABLE_UBSAN=true
include(Sanitizers.cmake)

# Link random program to catch for testing
target_link_libraries(test_sphere Catch2::Catch2)

# Add program target called sphere_collision
add_executable(sphere_collision app/sphere_collision.cpp lib/sphere.cpp)

# Add include directories
target_include_directories(sphere_collision PUBLIC include)
target_link_libraries(sphere_collision OpenGL::GL)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(sphere_collision ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

