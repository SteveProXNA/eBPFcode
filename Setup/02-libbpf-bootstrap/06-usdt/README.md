##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/usdt.bpf.c
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
Location: /home/stevepro/USDT
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
USDT BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create usdt.bpf.c
update usdt.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86 -I libbpf/src -c usdt.bpf.c -o usdt.bpf.o
bpftool gen skeleton usdt.bpf.o > usdt.skel.h
```
Test drive
```
mv main.c usdt.c
update usdt.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
ERROR
```
bpftool gen skeleton usdt.bpf.o > usdt.skel.h
libbpf: Error finalizing .BTF: -2.
Error: failed to open BPF object file: No such file or directory
```