##### README.md
###### 04-Jul-2023
Reference: https://github.com/sartura/ebpf-hello-world/blob/main/src/maps.bpf.c
<hr />

bpftool installation
```
git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
cd linux
cd tools/bpf/bpftool
make
sudo make install
```
New Project
```
Launch CLion | New Project
C Executable
Location: /home/stevepro/HelloMaps
Language standard: C11
Create
```
libbpf installation
```
git clone https://github.com/libbpf/libbpf
cd libbpf/src
make
sudo make install
cd ../..
```
Maps BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
touch maps.h
update maps.h
touch maps.bpf.c
update maps.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c maps.bpf.c -o maps.bpf.o
bpftool gen skeleton maps.bpf.o > maps.skel.h
```
Test drive
```
mv main.c maps.c
update maps.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
