# Install script for directory: /home/emilie/workspace/MOCAD/PJ/EO/eo/src/do

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo/do" TYPE FILE FILES
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_checkpoint_FDC.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_pop.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_algo_scalar.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_general_replacement.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_run.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_checkpoint.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_continue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_checkpoint_assembled.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/make_algo_easea.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")

