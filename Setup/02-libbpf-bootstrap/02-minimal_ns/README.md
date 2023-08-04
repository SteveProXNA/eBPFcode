##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/minimal_ns.bpf.c
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
Location: /home/stevepro/MinimalNs
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
MinimalNs BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create minimal_ns.bpf.c
update minimal_ns.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86 -I libbpf/src -c minimal_ns.bpf.c -o minimal_ns.bpf.o
bpftool gen skeleton minimal_ns.bpf.o > minimal_ns.skel.h
```
Test drive
```
mv main.c minimal_ns.c
update minimal_ns.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
ERROR
```
bpftool gen skeleton minimal_ns.bpf.o > minimal_ns.skel.h
libbpf: sec '.reltp/syscalls/sys_enter_write': corrupted symbol #34 pointing to invalid section #65522 for relo #0
Error: failed to open BPF object file: BPF object format invalid
```