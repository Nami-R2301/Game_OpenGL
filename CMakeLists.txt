cmake_minimum_required(VERSION 3.21)
project(Game_openGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game_openGL test.cpp)
add_executable(My_game src/main.cpp)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(Game_openGL PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_include_directories(My_game PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(Game_openGL PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})

target_link_libraries(My_game PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})
