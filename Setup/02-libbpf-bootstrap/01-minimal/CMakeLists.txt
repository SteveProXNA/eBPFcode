cmake_minimum_required(VERSION 3.19)
project(01_Minimal C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf/src)

add_executable(01_Minimal minimal.c)
target_link_libraries(01_Minimal bpf elf z)