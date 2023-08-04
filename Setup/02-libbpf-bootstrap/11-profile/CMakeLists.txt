cmake_minimum_required(VERSION 3.19)
project(09_Profile C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
link_directories(libbpf/src)

add_executable(09_Profile profile.c)
target_link_libraries(09_Profile bpf elf z)