cmake_minimum_required(VERSION 3.22)
project(cyclone VERSION 0.1.0)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(extlib/glfw)

set(CYCLONE_SOURCE_FILES
    src/instance.c
    src/main.c
)

add_executable(cyclone ${CYCLONE_SOURCE_FILES})

target_link_libraries(cyclone glfw)
target_link_libraries(cyclone OpenGL::GL)
target_include_directories(cyclone PRIVATE extlib\glad\include)