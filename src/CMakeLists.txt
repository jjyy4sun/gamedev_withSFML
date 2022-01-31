cmake_minimum_required(VERSION 3.10)

aux_source_directory(. SRCS)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SFML_DIR "${SFML_ROOT_DIR}/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

add_library(gamecore STATIC ${SRCS})

target_link_libraries(gamecore PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)