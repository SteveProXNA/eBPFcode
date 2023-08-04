##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/tc.bpf.c
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
Location: /home/stevepro/TC
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
TC BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create tc.bpf.c
update tc.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c tc.bpf.c -o tc.bpf.o
bpftool gen skeleton tc.bpf.o > tc.skel.h
```
Test drive
```
mv main.c tc.c
update tc.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
