SET(LIB_LIST myalgorithm.cpp ../cmake-build-debug/main.cpp)
ADD_LIBRARY(myalgorithm_static STATIC ${LIB_LIST} ../cmake-build-debug/main.cpp)
SET_TARGET_PROPERTIES(myalgorithm_static PROPERTIES 
                      OUT_PUT_NAME "myalgorithm"
                      CLEAN_DIRECT_OUPUT 1)
                      
ADD_LIBRARY(myalgorithm_shared SHARED ${LIB_LIST} ../cmake-build-debug/main.cpp)
SET_TARGET_PROPERTIES(myalgorithm_shared PROPERTIES 
                      OUT_PUT_NAME "myalgorithm"
                      CLEAN_DIRECT_OUPUT 1)
                      
INSTALL(FILES myalgorithm.h DESTINATION include/myalgorithm)
INSTALL(TARGETS myalgorithm_static myalgorithm_shared 
        LIBRARY DESTINATION lib/myalgorithm
        ARCHIVE DESTINATION lib/myalgorithm )                      
