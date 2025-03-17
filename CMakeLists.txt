cmake_minimum_required(VERSION 3.20)

project(pb-renderer)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC $ENV{OPENGL_SDK}/inc)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/inc)

target_link_directories(${PROJECT_NAME} PUBLIC $ENV{OPENGL_SDK}/lib)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw3 glad imgui)