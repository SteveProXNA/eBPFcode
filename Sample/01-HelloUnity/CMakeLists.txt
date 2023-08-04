cmake_minimum_required(VERSION 3.19)
project(HelloUnity C)
set(CMAKE_C_STANDARD 11)

include_directories(src/ /usr/local/include/unity/ src/include/libbpf/src)
link_directories(/usr/local/lib/ src/include/libbpf/src/amd64)

file(GLOB CODE_FILES src/*.c)
file(GLOB TEST_FILES test/*.c)
add_executable(HelloUnity ${CODE_FILES} ${TEST_FILES} )
target_link_libraries(HelloUnity unity bpf elf z)