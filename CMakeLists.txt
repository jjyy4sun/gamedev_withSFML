cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)

project(blade_project)

add_subdirectory(3rdparty)
add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/SFML-2.5.1/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/3rdparty/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

add_executable(blade main.cpp)

target_link_libraries(blade PRIVATE gamecore sfml-system sfml-window sfml-graphics sfml-network sfml-audio)