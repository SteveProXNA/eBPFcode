##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/fentry.bpf.c
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
Location: /home/stevepro/FEntry
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
FEntry BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
touch fentry.bpf.c
update fentry.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c fentry.bpf.c -o fentry.bpf.o
bpftool gen skeleton fentry.bpf.o > fentry.skel.h
```
Test drive
```
mv main.c fentry.c
update fentry.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
