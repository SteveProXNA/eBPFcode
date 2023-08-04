##### README.md
###### 31-Aug-2023

Reference: https://github.com/ThrowTheSwitch/Unity/tree/master/examples
<hr />
Unity installation

```
git clone git@github.com:ThrowTheSwitch/Unity.git
cd Unity
cmake .
make
sudo make install
sudo cp libunity.a /usr/local/lib
sudo cp src/unity*.h /usr/local/include/unity
```
New Project
```
Launch CLion | New Project
C Executable
Location: /home/stevepro/HelloUnity
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
Hello Unity
```
mkdir src
mkdir src/include
mkdir test
mv main.c test/all_tests.c
mv libbpf src/include
touch bpf_object.*
touch test_bpf_object.*
```
Test drive
```
update bpf_object.*
update test_bpf_object.*
update CMakeLists.txt
Edit configurations
Run with root privileges
F5
```