##### README.md
###### 31-Aug-2023

Reference: https://github.com/joaniedavis/cmock_example
<hr />
Ceedling installation

```
sudo apt install ruby
sudo apt install ruby-bundler
sudo gem install ceedling
```
New Project
```
Launch Terminal
cd /home/stevepro
ceedling new HelloCeedling
Launch VS Code | Open Folder /home/stevepro/HelloCeedling
```
Hello Ceedling
```
Copy joaniedavis/cmock_example/inc files into HelloCeedling
Copy joaniedavis/cmock_example/src files into HelloCeedling
Copy joaniedavis/cmock_example/test files into HelloCeedling
Update project.yml to include "inc" folder
```
Test drive
```
ceedling
Add .vscode folder
Add launch.json file
Set breakpoint in test_shape_container.c
F5
```