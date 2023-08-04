cmake_minimum_required(VERSION 3.19)
project(HelloMaps C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf libbpf/src)

add_executable(HelloMaps maps.c)
target_link_libraries(HelloMaps bpf elf z)