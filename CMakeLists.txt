cmake_minimum_required(VERSION 3.5)
project(CoRe VERSION 0.1 LANGUAGES CXX)

set(INCLUDE_INSTALL_PATH "include" CACHE PATH "Include install path")

## Set CMake flags for different build types
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11 -pg")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -std=c++11 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -DEIGEN_NO_DEBUG")

## RelWithDebInfo is the default build type
if (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE RelWithDebInfo) 
endif()

## Check for correct usage of CMAKE_BUILD_TYPE
string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
if (NOT CMAKE_BUILD_TYPE MATCHES RELWITHDEBINFO AND NOT CMAKE_BUILD_TYPE MATCHES DEBUG AND NOT CMAKE_BUILD_TYPE MATCHES RELEASE)
   message(FATAL_ERROR "${CMAKE_BUILD_TYPE} is not a valid build type. Supported types are Debug, Release and RelWithDebInfo (default)")
endif()

## Add -pg flag for debug build types
if (CMAKE_BUILD_TYPE MATCHES RELWITHDEBINFO OR CMAKE_BUILD_TYPE MATCHES DEBUG)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
endif()

## Set the root path to the current directory
set(ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

## Set the cmake path to ./cmake
set (CoRe_CMAKE_DIR ${ROOT_PATH}/cmake)

include(GNUInstallDirs)
include (${ROOT_PATH}/components/CMakeLists.txt)

## Create a CoReConfig.cmake so we can use find_package(CoRe)
include(CMakePackageConfigHelpers)
configure_package_config_file("${CoRe_CMAKE_DIR}/CoReConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/CoReConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/cmake"
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)

install(EXPORT CoReTargets
  FILE "CoReTargets.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/cmake"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/CoReConfig.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/cmake"
)
