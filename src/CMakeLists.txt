cmake_minimum_required(VERSION 3.16)
project(main)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)

include_directories(/home/xu736946693/Desktop/DataStructure/lib)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(main /home/xu736946693/Desktop/DataStructure/build/bin/libDataStructure_shared.so )