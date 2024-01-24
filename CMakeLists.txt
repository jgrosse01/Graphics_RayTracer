# Simple CMake Setup
cmake_minimum_required(VERSION 3.28)

project(
    GrosseTracer
    VERSION 0.1
    LANGUAGES CXX
)

# creates compilation DB
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# GLFW build disabled
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


set(CXX_STANDARD 23)

# Add library subdirectories here
add_subdirectory(lib/glfw-3.3.9)


# Source files for this project
# add_subdirectory(src)
add_subdirectory(apps)
