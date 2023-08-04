cmake_minimum_required(VERSION 3.19)
project(13_ksyscall C)

set(CMAKE_C_STANDARD 11)

include_directories(. libbpf/src)
link_directories(libbpf/src)

add_executable(13_ksyscall ksyscall.c)
target_link_libraries(13_ksyscall bpf elf z)