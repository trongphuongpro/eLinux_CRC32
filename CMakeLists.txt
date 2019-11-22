cmake_minimum_required(VERSION 3.0)

#-----------------------------------------------------------------------------#

set(TARGET crc32)

add_library(${TARGET} STATIC src/crc32.c)
target_include_directories(${TARGET} PUBLIC include)

#-----------------------------------------------------------------------------#
target_compile_options(${TARGET} PUBLIC -std=gnu11
										-O2
										-Wall
										-Werror
)
#-----------------------------------------------------------------------------#