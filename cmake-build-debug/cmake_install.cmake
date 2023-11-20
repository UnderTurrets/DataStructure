# Install script for directory: /home/xu736946693/Desktop/DataStructure

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/DataStructure-1.0/DataStructure.h;/usr/local/include/DataStructure-1.0/Graph.cpp;/usr/local/include/DataStructure-1.0/Graph.h;/usr/local/include/DataStructure-1.0/Heap.cpp;/usr/local/include/DataStructure-1.0/Heap.h;/usr/local/include/DataStructure-1.0/SetType.cpp;/usr/local/include/DataStructure-1.0/SetType.h;/usr/local/include/DataStructure-1.0/Sort.cpp;/usr/local/include/DataStructure-1.0/Sort.h;/usr/local/include/DataStructure-1.0/Tree.cpp;/usr/local/include/DataStructure-1.0/Tree.h;/usr/local/include/DataStructure-1.0/leetcode.cpp;/usr/local/include/DataStructure-1.0/leetcode.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include/DataStructure-1.0" TYPE FILE FILES
    "/home/xu736946693/Desktop/DataStructure/lib/DataStructure.h"
    "/home/xu736946693/Desktop/DataStructure/lib/Graph/Graph.cpp"
    "/home/xu736946693/Desktop/DataStructure/lib/Graph/Graph.h"
    "/home/xu736946693/Desktop/DataStructure/lib/Heap/Heap.cpp"
    "/home/xu736946693/Desktop/DataStructure/lib/Heap/Heap.h"
    "/home/xu736946693/Desktop/DataStructure/lib/SetType/SetType.cpp"
    "/home/xu736946693/Desktop/DataStructure/lib/SetType/SetType.h"
    "/home/xu736946693/Desktop/DataStructure/lib/Sort/Sort.cpp"
    "/home/xu736946693/Desktop/DataStructure/lib/Sort/Sort.h"
    "/home/xu736946693/Desktop/DataStructure/lib/Tree/Tree.cpp"
    "/home/xu736946693/Desktop/DataStructure/lib/Tree/Tree.h"
    "/home/xu736946693/Desktop/DataStructure/lib/leetcode/leetcode.cpp"
    "/home/xu736946693/Desktop/DataStructure/lib/leetcode/leetcode.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure_exe")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure_exe"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/DataStructure-1.0/DataStructure_exe")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/DataStructure-1.0" TYPE EXECUTABLE FILES "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/DataStructure_exe")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure_exe")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure_exe")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake"
         "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/CMakeFiles/Export/_usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}/usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/DataStructure-1.0" TYPE FILE FILES "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/CMakeFiles/Export/_usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/usr/local/lib/DataStructure-1.0" TYPE FILE FILES "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/CMakeFiles/Export/_usr/local/lib/DataStructure-1.0/DataStructure-1.0-targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/DataStructure-1.0/DataStructureConfig.cmake;/usr/local/lib/DataStructure-1.0/DataStructureConfigVersion.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/DataStructure-1.0" TYPE FILE FILES
    "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/DataStructureConfig.cmake"
    "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/DataStructureConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/xu736946693/Desktop/DataStructure/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
