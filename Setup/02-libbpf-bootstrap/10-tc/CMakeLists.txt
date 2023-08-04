cmake_minimum_required(VERSION 3.19)
project(11_TC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf/src)

add_executable(11_TC tc.c)
target_link_libraries(11_TC bpf elf z)