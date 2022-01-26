cmake_minimum_required(VERSION 3.21)
project(cmdUtil C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cmdUtil
        cli_parser.c
        network.c
        network.h
        sick.c
        str_util.c
        str_util.h cli_parser.h)
