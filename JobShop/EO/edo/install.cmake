# Variables to set

#  directory we need to build project
SET(EO_DIR "~/workspace/MOCAD/PJ/EO/eo" CACHE PATH "EO directory" FORCE)

# automagically set parameters, do not edit

SET(EO_INCLUDE_DIRS "${EO_DIR}/src" CACHE PATH "EO include directory" FORCE)
SET(EO_LIBRARY_DIRS "${EO_DIR}/lib" CACHE PATH "EO library directory" FORCE)
SET(EO_LIBRARIES eoutils eo es ga cma gcov) # do not use quotes around this list or it will fail
