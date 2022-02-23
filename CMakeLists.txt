cmake_minimum_required(VERSION 3.21)
project(Game_openGL)


set(CMAKE_CXX_STANDARD 14)

add_subdirectory(glfw3 build)

add_executable(Game_openGL src/main.cpp include/program.h)
find_package(OpenGL REQUIRED)

target_link_libraries(Game_openGL PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})

target_link_libraries(Game_openGL PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})
