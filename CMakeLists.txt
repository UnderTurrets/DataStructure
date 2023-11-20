cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
# 设置库的名称
set(LIB_NAME DataStructure)
set(STATIC_LIB ${LIB_NAME}_static)
# 设置可执行文件的名字
PROJECT(${LIB_NAME}_exe)
#设置版本
set(version 1.0)
# 拼接名字
set(LIB_NAME_VERSION ${LIB_NAME}-${version})
#设置安装位置，将头文件和库都安装到这个文章
set(CMAKE_INSTALL_PREFIX /usr/local)

# 依赖的外部库
#find_package(OpenCV REQUIRED)

# 自己的库依赖的头文件
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        lib
        lib/Graph
        lib/Heap
        lib/leetcode
        lib/SetType
        lib/Sort
        lib/Tree
        # 以下为外部依赖
#        ${OpenCV_INCLUDE_DIRS}
)

file(GLOB_RECURSE source
        lib/*.h
        lib/*.hpp
        lib/*.cpp
        lib/Graph/*
        lib/Heap/*
        lib/leetcode/*
        lib/SetType/*
        lib/Sort/*
        lib/Tree/*.
        )

# ----------------- 可执行文件 -----------------
# 可执行文件生成
add_executable(${PROJECT_NAME}  main.cpp )
# 设置可执行文件的依赖
#target_link_libraries(${PROJECT_NAME}
#        # 以下为外部依赖
#        ${OpenCV_LIBS}
#        )
# ----------------- 结束可执行文件的生成 -----------------


# ----------------- 安装（不需要修改） -----------------
# 安装源码文件
install(FILES ${source}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${LIB_NAME_VERSION}
        )

# 安装可执行文件
install(TARGETS ${PROJECT_NAME}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME_VERSION}
        EXPORT ${LIB_NAME_VERSION}-targets
        )
install(EXPORT ${LIB_NAME_VERSION}-targets
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME_VERSION}
        )
# ----------------- 结束安装 -----------------

# ----------------- 生成 CMake 配置文件（不需要修改） -----------------
# 生成 CMake 配置文件
include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${LIB_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME_VERSION}
)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${LIB_NAME}ConfigVersion.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}ConfigVersion.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME_VERSION}
)

# 安装 CMake 配置文件
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}ConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME_VERSION}
        )
# ----------------- 结束生成 CMake 配置文件 -----------------