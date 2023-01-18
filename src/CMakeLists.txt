cmake_minimum_required(VERSION 3.16)
project(main)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)

include_directories(lib/)
include_directories(${OpenCV_INCLUDE_DIRS})
ADD_SUBDIRECTORY(lib)
add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS})

