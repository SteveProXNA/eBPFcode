cmake_minimum_required(VERSION 3.19)
project(07_MinimalLegacy C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf libbpf/src)

add_executable(07_MinimalLegacy minimal_legacy.c)
target_link_libraries(07_MinimalLegacy bpf elf z)