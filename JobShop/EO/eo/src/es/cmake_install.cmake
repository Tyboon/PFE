# Install script for directory: /home/emilie/workspace/MOCAD/PJ/EO/eo/src/es

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/emilie/workspace/MOCAD/PJ/EO/eo/lib/libes.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/emilie/workspace/MOCAD/PJ/EO/eo/lib/libcma.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo/es" TYPE FILE FILES
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoCMAInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/make_real.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsStdev.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoRealAtomXover.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/make_op_es.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoNormalMutation.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoCMABreed.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoSBXcross.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsMutate.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/matrices.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsStandardXover.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoRealInitBounded.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsChromInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/make_op.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoRealOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsGlobalXover.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/CMAParams.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/make_genotype_real.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/make_es.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/CMAState.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsFull.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsMutationInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoEsSimple.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eig.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/make_op_real.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/eoReal.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")

