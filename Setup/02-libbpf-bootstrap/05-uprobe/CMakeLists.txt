cmake_minimum_required(VERSION 3.19)
project(04_UProbe C)

set(CMAKE_C_STANDARD 11)

include_directories(. libbpf/src)
link_directories(libbpf/src)

add_executable(04_UProbe uprobe.c)
target_link_libraries(04_UProbe bpf elf z)