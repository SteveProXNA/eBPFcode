cmake_minimum_required(VERSION 3.19)
project(02_Bootstrap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf libbpf/src)

add_executable(02_Bootstrap bootstrap.c)
target_link_libraries(02_Bootstrap bpf elf z)
