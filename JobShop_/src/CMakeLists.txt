######################################################################################
### 1) Include the sources
######################################################################################

INCLUDE_DIRECTORIES(/home/emilie/workspace/PFE/JobShop_/src)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/eo/)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/eo/do/)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/eo/es/)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/eo/ga/)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/eo/utils/)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/moeo/)
INCLUDE_DIRECTORIES(/usr/include/paradiseo/mo/)
######################################################################################



######################################################################################
### 2) Specify where CMake can find the libraries
######################################################################################

IF(NOT WIN32 OR CYGWIN)
  LINK_DIRECTORIES(${EO_BINARY_DIR}/lib)
ENDIF(NOT WIN32 OR CYGWIN)

# especially for Visual Studio
IF(WIN32 AND NOT CYGWIN)
  	LINK_DIRECTORIES(${EO_BINARY_DIR}\\lib\\${CMAKE_BUILD_TYPE})
ENDIF(WIN32 AND NOT CYGWIN)

######################################################################################



######################################################################################
### 3) Define your targets
######################################################################################

ADD_EXECUTABLE(JobShopEA JobShopEA.cpp)

######################################################################################


######################################################################################
### 4) Link the librairies for the targets
######################################################################################

TARGET_LINK_LIBRARIES(JobShopEA eo moeo eoutils ga es)

######################################################################################
