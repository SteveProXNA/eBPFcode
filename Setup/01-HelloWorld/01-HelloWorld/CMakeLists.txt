cmake_minimum_required(VERSION 3.19)
project(HelloWorld C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf libbpf/src)

add_executable(HelloWorld hello.c)
target_link_libraries(HelloWorld bpf elf z)