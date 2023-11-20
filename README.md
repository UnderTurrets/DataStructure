# Brief
This is a collection of algorithms which I have met during my learning experience!All the algorithms are stated in the lib.You can use the following commands to install them.
```bash
git clone git@gitee.com:UnderTurrets/DataStructure.git
cd DataStructure
rm -rf cmake-build-debug
mkdir cmake-build-debug
cd cmake-build-debug
cmake..
make
sudo make install
```
# Explanation
二叉树：Tree.h
堆：Heap.h
集合：SetType.h
图：Graph.h
排序：Sort.h
力扣的一些算法：leetcode.h

# Start quickly
We create another project to use the library. Then we can use the library in the test project.
```CMakeLists.txt
cmake_minimum_required(VERSION 3.23)
project(test)
find_package(DataStructure REQUIRED)
set(CMAKE_CXX_STANDARD 23)
include_directories(${DataStructure_INCLUDE_DIRS})
add_executable(test main.cpp)
```
Diretory structure:
```
.
├── cmake-build-debug
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── Makefile
│   ├── test
│   ├── test.cbp
│   └── Testing
├── CMakeLists.txt
└── main.cpp
```
main.cpp:
```cpp
#include <iostream>
#include <DataStructure.h>
#include <vector>
int main() {
    vector<int>v1=BubbleSort<int>({5,1,2,25,});
    v1.push_back(9);
    v1= BubbleSort(v1);
    for(auto x:v1){
      cout<<x<<endl;
    }
    return 0;
}
```