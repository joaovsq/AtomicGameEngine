project(Atomic)

cmake_minimum_required(VERSION 3.3)

set(ATOMIC_SOURCE_DIR ${Atomic_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${ATOMIC_SOURCE_DIR}/Build/CMake/Modules)
set(ATOMIC_DESKTOP TRUE)

include(AtomicGit)
include(AtomicUtils)
include(AtomicCommon)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    set (ATOMIC_RELEASE_OFF OFF)
    set (ATOMIC_RELEASE_ON ON)
else ()
    set (ATOMIC_RELEASE_OFF ON)
    set (ATOMIC_RELEASE_ON OFF)
endif ()

add_definitions(-DATOMIC_ROOT_SOURCE_DIR="${ATOMIC_SOURCE_DIR}" -DATOMIC_ROOT_BUILD_DIR="${CMAKE_BINARY_DIR}")

if (NOT DEFINED ATOMIC_DEV_BUILD)
    set(ATOMIC_DEV_BUILD 1)
ENDIF ()

if (ATOMIC_DEV_BUILD)
    add_definitions("-DATOMIC_DEV_BUILD=1")
endif ()

include(AtomicPlatform)

find_program(CLDOC cldoc)
if (CLDOC)
    add_custom_target(docs DEPENDS AtomicEngineDocs)
endif ()

add_subdirectory(Source)

if (ATOMIC_DESKTOP AND ATOMIC_DEV_BUILD)
	
	# This subdirectory is specific to the cpp games, using the engine as a library
	add_subdirectory(Submodules/CppGames)

    if (NOT DEFINED ATOMIC_CPLUSPLUS_EXAMPLES)
        set(ATOMIC_CPLUSPLUS_EXAMPLES 1)
    endif ()
    if (ATOMIC_CPLUSPLUS_EXAMPLES)
        initialize_submodule(${ATOMIC_SOURCE_DIR}/Submodules/AtomicExamples ATOMIC_CPLUSPLUS_EXAMPLES)
        if (ATOMIC_CPLUSPLUS_EXAMPLES)
            add_subdirectory(Submodules/AtomicExamples/FeatureExamples/CPlusPlus)
        endif ()
    endif ()
endif ()