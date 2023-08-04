##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/minimal_legacy.bpf.c
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
Location: /home/stevepro/MinimalLegacy
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
MinimalLegacy BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create minimal_legacy.bpf.c
update minimal_legacy.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c minimal_legacy.bpf.c -o minimal_legacy.bpf.o
bpftool gen skeleton minimal_legacy.bpf.o > minimal_legacy.skel.h
```
Test drive
```
mv main.c minimal_legacy.c
update minimal_legacy.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
