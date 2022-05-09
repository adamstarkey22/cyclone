cmake_minimum_required(VERSION 3.22)
project(cyclone VERSION 0.1.0)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(extlib/cglm)
add_subdirectory(extlib/glfw)
add_subdirectory(extlib/lua-5.4.4)

set(CYCLONE_SOURCE_FILES
    src/gl.c
    src/init.c
    src/instance.c
    src/main.c
    src/memory.c
    src/mesh_array.c
    src/mesh.c
    src/program_array.c
    src/program.c
)

add_executable(cyclone ${CYCLONE_SOURCE_FILES})
target_include_directories(cyclone PUBLIC include)

target_link_libraries(cyclone cglm)
target_link_libraries(cyclone glfw)
target_link_libraries(cyclone lua)
target_link_libraries(cyclone OpenGL::GL)
target_include_directories(cyclone PRIVATE extlib/glad/include)
target_include_directories(cyclone PRIVATE extlib/lua/src)