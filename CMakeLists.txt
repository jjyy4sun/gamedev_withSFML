cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)

project(blade_project)

add_subdirectory(3rdparty)
add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/SFML-2.5.1/include)


add_executable(blade main.cpp)

target_link_libraries(blade PRIVATE gamecore)