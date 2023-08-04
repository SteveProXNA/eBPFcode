cmake_minimum_required(VERSION 3.19)
project(03_KProbe C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf libbpf/src)

add_executable(03_KProbe kprobe.c)
target_link_libraries(03_KProbe bpf elf z)
