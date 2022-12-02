cmake_minimum_required(VERSION 3.23)
project(get_next_line C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -D BUFFER_SIZE=42")

set(SOURCES get_next_line.c get_next_line_utils.c get_next_line.h)

add_library(get_next_line ${SOURCES})
