######################################################################################
### 1) Main project config
######################################################################################

# set the project name
PROJECT(JobShopEA)

# set a language for the entire project.
ENABLE_LANGUAGE(CXX)

#####################################################################################


######################################################################################
### 2) We need to know where EO is installed
######################################################################################

IF(NOT EO_SOURCE_DIR)
     	SET(	EO_SOURCE_DIR
		/home/emilie/workspace/MOCAD/PJ/EO/eo/tutorial/Templates/../.. CACHE STRING
		"EO source directory"
		FORCE)
ENDIF(NOT EO_SOURCE_DIR)

IF(NOT EO_BINARY_DIR)
    	 SET(	EO_BINARY_DIR
		/home/emilie/workspace/MOCAD/PJ/EO/eo/tutorial/Templates/../../build CACHE STRING
		"EO binary directory"
		FORCE)
ENDIF(NOT EO_BINARY_DIR)
######################################################################################


######################################################################################
### 3) Where must cmake go now ?
######################################################################################

SUBDIRS(src)

######################################################################################
