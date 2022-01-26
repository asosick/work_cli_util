cmake_minimum_required(VERSION 3.21)
project(cmdUtil C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cmdUtil
        utils/cli_parser.c
        network/network.c
        network/network.h
        main.c
        utils/str_util.c
        utils/str_util.h utils/cli_parser.h)
