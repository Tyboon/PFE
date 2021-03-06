# Install script for directory: /home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/emilie/workspace/MOCAD/PJ/EO/eo/lib/libga.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo/ga" TYPE FILE FILES
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoBit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoPBILDistrib.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoBoolFlip.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/make_op.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/make_PBILdistrib.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/make_PBILupdate.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoPBILAdditive.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/make_ga.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoBitOpFactory.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoPBILOrg.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/make_genotype_ga.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/eoBitOp.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")

