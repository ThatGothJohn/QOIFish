cmake_minimum_required(VERSION 3.21)
project(qoi_fish)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Werror")

add_executable(qoi_fish main.cpp qoi.cpp qoi.h)
