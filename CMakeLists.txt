cmake_minimum_required(VERSION 3.10.0)
project(crc_test VERSION 0.1.0 LANGUAGES C)

add_subdirectory(crc)

add_executable(crc_test main.c)

target_link_libraries(crc_test PRIVATE 
    crc
)