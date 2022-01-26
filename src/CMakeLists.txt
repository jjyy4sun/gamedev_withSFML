cmake_minimum_required(VERSION 3.10)

aux_source_directory(. SRCS)

add_library(gamecore STATIC ${SRCS})