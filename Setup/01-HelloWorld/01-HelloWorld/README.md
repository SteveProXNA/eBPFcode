##### README.md
###### 04-Jul-2023
Reference: https://github.com/sartura/ebpf-hello-world/blob/main/src/hello.bpf.c
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
Location: /home/stevepro/HelloWorld
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
Hello BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
touch hello.bpf.c
update hello.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c hello.bpf.c -o hello.bpf.o
bpftool gen skeleton hello.bpf.o > hello.skel.h
```
Test drive
```
mv main.c hello.c
update hello.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
