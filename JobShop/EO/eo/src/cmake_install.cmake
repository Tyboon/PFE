# Install script for directory: /home/emilie/workspace/MOCAD/PJ/EO/eo/src

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/emilie/workspace/MOCAD/PJ/EO/eo/lib/libeo.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo" TYPE FILE FILES
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoBitParticle.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFitnessScalingSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoOrderXover.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalFuncCounter.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSTLFunctor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSyncEasyPSO.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFlOrMonOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalFuncCounterBounder.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSGA.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFitContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPopEvalFunc.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPSO.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoG3Replacement.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoGenContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalUserTimeThrowException.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/EO.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoDetTournamentSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoCounter.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPop.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPeriodicContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVariableLengthCrossover.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPopulator.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoStochasticUniversalSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalFuncPtr.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTruncSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoInvalidateOps.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEasyEA.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoParticleFullInitializer.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoAlgo.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoOpSelMason.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFunctorStore.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoConstrictedVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoOneToOneBreeder.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoScalarFitness.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoCombinedInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoCombinedContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoBreed.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoGeneralBreeder.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoCellularEasyEA.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRanking.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoDualFitness.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoReplacement.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoLinearTopology.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVariableLengthMutation.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalFunc.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoMerge.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoShiftMutation.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRandomRealWeightUp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoCtrlCContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoGaussRealWeightUp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoMergeReduce.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFlight.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoStochTournamentSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTruncatedSelectOne.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRankMuSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSocialNeighborhood.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoBinaryFlight.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSharing.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoReduce.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalCounterThrowException.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPersistent.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEasyPSO.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoWeightUpdater.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFactory.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTruncatedSelectMany.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelectOne.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoDetSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSimpleEDA.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSharingSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVector.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoStandardFlight.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSwapMutation.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalTimeThrowException.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRandomSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFixedInertiaWeightedVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoObject.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelectPerc.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRingTopology.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoReduceMergeReduce.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoExtendedVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelectFactory.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSequentialSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSGAGenOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoExceptions.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTimeContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoStarTopology.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoReduceSplit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSigBinaryFlight.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVelocityInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEvalContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFlOrQuadOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTransform.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoMGGReplacement.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoProportionalCombinedOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoScalarFitnessAssembled.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoDistribUpdater.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelectMany.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFunctor.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoLinearFitScaling.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoOpContainer.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoStandardVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoDistribution.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPropGAGenOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPrintable.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTwoOptMutation.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVectorParticle.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoIntegerVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoInt.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoParticleBestInit.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRealBoundModifier.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoVariableInertiaWeightedVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSIGContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoGenOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRealParticle.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoTopology.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoProportionalSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoRankingSelect.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoReduceMerge.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoFlOrBinOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoNDSorting.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSGATransform.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoInitializer.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoCloneOps.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoPerf2Worth.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSteadyFitContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelectFromWorth.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSelectNumber.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoLinearDecreasingWeightUp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoNeighborhood.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoOp.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoEDA.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSurviveAndDie.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoConstrictedVariableWeightVelocity.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eoSecondsElapsedContinue.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/apply.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/PO.h"
    "/home/emilie/workspace/MOCAD/PJ/EO/eo/src/eo"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/do/cmake_install.cmake")
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/es/cmake_install.cmake")
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/ga/cmake_install.cmake")
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/gp/cmake_install.cmake")
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/other/cmake_install.cmake")
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/utils/cmake_install.cmake")
  INCLUDE("/home/emilie/workspace/MOCAD/PJ/EO/eo/src/serial/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

