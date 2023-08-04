##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/uprobe.bpf.c
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
Location: /home/stevepro/UProbe
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
UProbe BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
touch uprobe.bpf.c
update uprobe.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86 -I libbpf/src -c uprobe.bpf.c -o uprobe.bpf.o
bpftool gen skeleton uprobe.bpf.o > uprobe.skel.h
```
Test drive
```
mv main.c uprobe.c
update uprobe.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
