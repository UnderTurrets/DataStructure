



SET(LIB_LIST myAlgorithm.h;authority.h;Heap.h;leetcode.h;leetcode.cpp;Tree.h;Graph.h )
ADD_LIBRARY(myAlgorithm_static STATIC ${LIB_LIST} )
SET_TARGET_PROPERTIES(myAlgorithm_static PROPERTIES 
                      OUT_PUT_NAME "myAlgorithm"
                      CLEAN_DIRECT_OUPUT 1)
                      
ADD_LIBRARY(myAlgorithm_shared SHARED ${LIB_LIST} )
SET_TARGET_PROPERTIES(myAlgorithm_shared PROPERTIES 
                      OUT_PUT_NAME "myAlgorithm"
                      CLEAN_DIRECT_OUPUT 1)
                      
INSTALL(FILES myAlgorithm.h DESTINATION include/myAlgorithm/)
INSTALL(FILES authority.h DESTINATION include/myAlgorithm/)
INSTALL(FILES Heap.h DESTINATION include/myAlgorithm/)
INSTALL(FILES leetcode.h DESTINATION include/myAlgorithm/)
INSTALL(FILES Tree.h DESTINATION include/myAlgorithm/)
INSTALL(FILES Graph.h DESTINATION include/myAlgorithm/)
INSTALL(TARGETS myAlgorithm_static myAlgorithm_shared 
        LIBRARY DESTINATION lib/myAlgorithm/
        ARCHIVE DESTINATION lib/myAlgorithm/ )                      
