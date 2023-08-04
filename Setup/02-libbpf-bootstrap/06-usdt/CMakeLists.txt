cmake_minimum_required(VERSION 3.19)
project(12_usdt C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf/src)

add_executable(12_usdt usdt.c)
target_link_libraries(12_usdt bpf elf z)