##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/sockfilter.bpf.c
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
Location: /home/stevepro/SockFilter
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
SockFilter BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create sockfilter.h
update sockfilter.h
create sockfilter.bpf.c
update sockfilter.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c sockfilter.bpf.c -o sockfilter.bpf.o
bpftool gen skeleton sockfilter.bpf.o > sockfilter.skel.h
```
Test drive
```
mv main.c sockfilter.c
update sockfilter.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
ERROR
```
sockfilter.bpf.c:16:18: error: use of undeclared identifier 'BPF_MAP_TYPE_RINGBUF'
    __uint(type, BPF_MAP_TYPE_RINGBUF);
                 ^
1 error generated.
```