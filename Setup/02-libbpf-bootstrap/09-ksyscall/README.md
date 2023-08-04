##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/ksyscall.bpf.c
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
Location: /home/stevepro/ksyscall
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
ksyscall BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create ksyscall.bpf.c
update ksyscall.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86 -I libbpf/src -c ksyscall.bpf.c -o ksyscall.bpf.o
bpftool gen skeleton ksyscall.bpf.o > ksyscall.skel.h
```
Test drive
```
mv main.c ksyscall.c
update ksyscall.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
