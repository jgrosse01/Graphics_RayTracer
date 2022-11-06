cmake_minimum_required(VERSION 3.23)
project(GL_Raytracer)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/src/*/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}src/*/*.h)

find_package(OpenGL REQUIRED)

set(SOURCES ${SRC} ${HEADERS})

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENGL_LIBRARIES} -lfreeglut)
