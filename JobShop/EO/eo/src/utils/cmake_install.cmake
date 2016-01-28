# Install script for directory: /home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/emilie/workspace/MOCAD/PJ/EO/eo/lib/libeoutils.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo/utils" TYPE FILE FILES
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoParam.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoScalarFitnessStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoGnuplot.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoUniformInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoDistance.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/pipecom.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoRealBounds.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoGnuplot1DMonitor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoAssembledFitnessStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoTimeCounter.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoMOFitnessStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/selectors.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoFileSnapshot.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoRndGenerators.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoRealVectorBounds.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoCheckPoint.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoOStreamMonitor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoData.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoTimedMonitor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoLogger.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoUpdater.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoStdoutMonitor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoGnuplot1DSnapshot.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoGenCounter.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoRNG.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoPopStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoMonitor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoUpdatable.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoSignal.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoParser.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/compatibility.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoFDCStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoTimer.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoIntBounds.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoHowMany.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoState.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoFileMonitor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/rnd_generators.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoFeasibleRatioStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoParallel.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/eoFuncPtrStat.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/checkpointing"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")

