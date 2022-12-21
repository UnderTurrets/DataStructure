SET(LIB_LIST myAlgorithm.h;authority.h;Heap.h;leetcode.h;leetcode.cpp;Tree.h )
ADD_LIBRARY(myalgorithm_static STATIC ${LIB_LIST} )
SET_TARGET_PROPERTIES(myalgorithm_static PROPERTIES 
                      OUT_PUT_NAME "myalgorithm"
                      CLEAN_DIRECT_OUPUT 1)
                      
ADD_LIBRARY(myalgorithm_shared SHARED ${LIB_LIST} )
SET_TARGET_PROPERTIES(myalgorithm_shared PROPERTIES 
                      OUT_PUT_NAME "myalgorithm"
                      CLEAN_DIRECT_OUPUT 1)
                      
INSTALL(FILES myalgorithm.h DESTINATION include/myalgorithm)
INSTALL(FILES authority.h DESTINATION include/myalgorithm)
INSTALL(FILES Heap.h DESTINATION include/myalgorithm)
INSTALL(FILES leetcode.h DESTINATION include/myalgorithm)
INSTALL(FILES Tree.h DESTINATION include/myalgorithm)
INSTALL(TARGETS myalgorithm_static myalgorithm_shared 
        LIBRARY DESTINATION lib/myalgorithm
        ARCHIVE DESTINATION lib/myalgorithm )                      
