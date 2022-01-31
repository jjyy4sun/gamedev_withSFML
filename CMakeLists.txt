cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)

project(blade_project)

if (CMAKE_HOST_WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_ROOT_DIR "${CMAKE_SOURCE_DIR}/3rdparty/SFML/windows")
elseif (CMAKE_HOST_APPLE)
    set(SFML_ROOT_DIR "${CMAKE_SOURCE_DIR}/3rdparty/SFML/Apple")
    exec_program(COMMAND install_name_tool -add_rpath ${SFML_ROOT_DIR}/SFML-2.5.1/lib)
elseif (CMAKE_HOST_UNIX)
    set(SFML_ROOT_DIR "${CMAKE_SOURCE_DIR}/3rdparty/SFML/linux")
endif ()

add_subdirectory(3rdparty)
add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${SFML_ROOT_DIR}/SFML-2.5.1/include)


add_executable(blade main.cpp)

target_link_libraries(blade PRIVATE gamecore)