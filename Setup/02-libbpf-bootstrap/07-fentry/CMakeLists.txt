cmake_minimum_required(VERSION 3.19)
project(05_FEntry C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf/src)

add_executable(05_FEntry fentry.c)
target_link_libraries(05_FEntry bpf elf z)
