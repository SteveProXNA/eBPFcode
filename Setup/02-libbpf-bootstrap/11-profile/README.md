##### README.md
###### 04-Jul-2023
Reference: https://github.com/libbpf/libbpf-bootstrap/blob/master/examples/c/profile.bpf.c
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
Location: /home/stevepro/Profile
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
Profile BPF
```
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h
create profile.h
update profile.h
create profile.bpf.c
update profile.bpf.c
clang -g -O2 -target bpf -D__TARGET_ARCH_x86_64 -I libbpf/src -c profile.bpf.c -o profile.bpf.o
bpftool gen skeleton profile.bpf.o > profile.skel.h
```
Test drive
```
mv main.c profile.c
update profile.c
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```
ERROR
```
profile.c:15:10: fatal error: blazesym.h: No such file or directory
   15 | #include "blazesym.h"
```