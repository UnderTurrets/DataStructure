cmake_minimum_required(VERSION 3.16)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


SET(LIB_LIST DataStructure.h
             authority.h
             Heap.h   
             Heap.cpp
             leetcode.h
             leetcode.cpp
             Tree.h
             Tree.cpp
             SetType.h
             SetType.cpp 
             Graph.h
             Graph.cpp     
             Sort.h
             Sort.cpp    )
             
ADD_LIBRARY(DataStructure_static STATIC ${LIB_LIST} )
SET_TARGET_PROPERTIES(DataStructure_static PROPERTIES 
                      OUTPUT_NAME "DataStructure"
                      CLEAN_DIRECT_OUTPUT 1)
                      
ADD_LIBRARY(DataStructure_shared SHARED ${LIB_LIST} )
SET_TARGET_PROPERTIES(DataStructure_shared PROPERTIES 
                      OUTPUT_NAME "DataStructure"
                      CLEAN_DIRECT_OUTPUT 1)
                      
INSTALL(FILES DataStructure.h DESTINATION include/DataStructure/)
INSTALL(FILES authority.h DESTINATION include/DataStructure/)
INSTALL(FILES Heap.h DESTINATION include/DataStructure/)
INSTALL(FILES Heap.cpp DESTINATION include/DataStructure/)
INSTALL(FILES leetcode.h DESTINATION include/DataStructure/)
INSTALL(FILES leetcode.cpp DESTINATION include/DataStructure/)
INSTALL(FILES Tree.h DESTINATION include/DataStructure/)
INSTALL(FILES Tree.cpp DESTINATION include/DataStructure/)
INSTALL(FILES SetType.h DESTINATION include/DataStructure/)
INSTALL(FILES SetType.cpp DESTINATION include/DataStructure/)
INSTALL(FILES Graph.h DESTINATION include/DataStructure/)
INSTALL(FILES Graph.cpp DESTINATION include/DataStructure/)
INSTALL(FILES Sort.h DESTINATION include/DataStructure/)
INSTALL(FILES Sort.cpp DESTINATION include/DataStructure/)
INSTALL(TARGETS DataStructure_static DataStructure_shared
        LIBRARY DESTINATION lib/DataStructure/
        ARCHIVE DESTINATION lib/DataStructure/ )                      
