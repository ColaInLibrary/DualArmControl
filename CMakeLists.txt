cmake_minimum_required(VERSION 3.6)

if(POLICY CMP0072)
	cmake_policy(SET CMP0072 NEW)
endif()

if(POLICY CMP0075)
	cmake_policy(SET CMP0075 NEW)
endif()

project(rl VERSION 1.0)

if(NOT PROJECT_VERSION_TWEAK)
	set(PROJECT_VERSION_TWEAK 0)
endif()

set(Boost_ADDITIONAL_VERSIONS "1.73.0" "1.73" "1.72.0" "1.72" "1.71.0" "1.71" "1.70.0" "1.70" "1.69.0" "1.69" "1.68.0" "1.68" "1.67.0" "1.67" "1.66.0" "1.66" "1.65.1" "1.65.0" "1.65" "1.64.0" "1.64" "1.63.0" "1.63" "1.62.0" "1.62" "1.61.0" "1.61" "1.60.0" "1.60" "1.59.0" "1.59" "1.58.0" "1.58" "1.57.0" "1.57")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_SYSTEM_RUNTIME_COMPONENT system)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

include(CheckCXXCompilerFlag)
include(CMakeDependentOption)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)
include(GNUInstallDirs)
include(InstallRequiredSystemLibraries)


option(RL_BUILD_DEMOS "Build demos" ON)
option(RL_BUILD_EXTRAS "Build extras" ON)
option(RL_BUILD_MATH "Build mathematics component" ON)
option(RL_BUILD_TESTS "Build tests" ON)
option(RL_BUILD_UTIL "Build utility component" ON)
option(RL_BUILD_XML "Build XML abstraction layer component" ON)

cmake_dependent_option(RL_BUILD_HAL "Build hardware abstraction layer component" ON "RL_BUILD_MATH;RL_BUILD_UTIL" OFF)
cmake_dependent_option(RL_BUILD_KIN "Build Denavit-Hartenberg kinematics component" ON "RL_BUILD_MATH;RL_BUILD_XML" OFF)
cmake_dependent_option(RL_BUILD_MDL "Build rigid body kinematics and dynamics component" ON "RL_BUILD_MATH;RL_BUILD_XML" OFF)
cmake_dependent_option(RL_BUILD_SG "Build scene graph abstraction component" ON "RL_BUILD_MATH;RL_BUILD_UTIL;RL_BUILD_XML" OFF)
cmake_dependent_option(RL_BUILD_UTIL_RTAI "Build RTAI support" OFF "RL_BUILD_UTIL" OFF)
cmake_dependent_option(RL_BUILD_UTIL_XENOMAI "Build Xenomai support" OFF "RL_BUILD_UTIL" OFF)

cmake_dependent_option(RL_BUILD_PLAN "Build path planning component" ON "RL_BUILD_KIN;RL_BUILD_MATH;RL_BUILD_MDL;RL_BUILD_SG;RL_BUILD_UTIL;RL_BUILD_XML" OFF)

configure_file(robotics-library.rc.in robotics-library.rc)

add_subdirectory(src)
add_subdirectory(examples)

if(RL_BUILD_DEMOS)
	add_subdirectory(demos)
endif()

if(RL_BUILD_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()

#add_subdirectory(doc)

foreach(target IN LISTS TARGETS)
	if(NOT target STREQUAL "util_rtai" AND NOT target STREQUAL "util_xenomai")
		list(APPEND RL_LIBRARIES "rl::${target}")
	endif()
	get_target_property(TARGET_INTERFACE_LINK_LIBRARIES ${target} INTERFACE_LINK_LIBRARIES)
	if(TARGET_INTERFACE_LINK_LIBRARIES)
		foreach(library IN LISTS TARGET_INTERFACE_LINK_LIBRARIES)
			if(library MATCHES "([A-Za-z0-9_.+-]*)::([A-Za-z0-9_.+-]*)")
				list(APPEND PACKAGES ${CMAKE_MATCH_1})
			endif()
		endforeach()
	endif()
endforeach()

list(REMOVE_DUPLICATES PACKAGES)
list(SORT PACKAGES)

foreach(package IN LISTS PACKAGES)
	list(APPEND FIND_DEPENDENCIES "find_dependency(${package})")
	list(APPEND MODULES ${package})
	message(STATUS "${package}")
	if(package STREQUAL "fcl")
		message(STATUS "Adding dependencies for fcl: Boost, ccd, Eigen3, octomap")
		list(APPEND MODULES Boost ccd Eigen3 octomap)
	elseif(package STREQUAL "LibXml2")
		message(STATUS "Adding dependencies for LibXml2")
		list(APPEND MODULES Iconv ICU LibLZMA Threads ZLIB)
	elseif(package STREQUAL "LibXslt")
		message(STATUS "Adding dependencies for LibXslt")
		list(APPEND MODULES LibXml2)
	elseif(package STREQUAL "ODE")
		message(STATUS "Adding dependencies for ODE")
		list(APPEND MODULES ccd Threads)
	endif()
endforeach()

## 查找Eigen库
#find_package(Eigen3 REQUIRED)
#
## 检查是否找到Eigen库
#if(EIGEN3_FOUND)
#	message(STATUS "Eigen3 found: ${EIGEN3_INCLUDE_DIRS}")
#else()
#	message(WARNING "Eigen3 not found")
#endif()
#
#include_directories(${EIGEN3_INCLUDE_DIRS})

list(REMOVE_DUPLICATES MODULES)
list(SORT MODULES)

foreach(module IN LISTS MODULES)
	if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Find${module}.cmake)
		file(
			COPY cmake/Find${module}.cmake
			DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/rl
		)
		install(
			FILES cmake/Find${module}.cmake
			DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rl-${PROJECT_VERSION}
			COMPONENT development
		)
	endif()
endforeach()

string(REPLACE ";" "\n" FIND_DEPENDENCIES "${FIND_DEPENDENCIES}")

export(
	TARGETS ${TARGETS}
	NAMESPACE rl::
	FILE ${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/rl/rl-export.cmake
)

configure_package_config_file(
	rl-config.cmake.in lib/cmake/rl/rl-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rl-${PROJECT_VERSION}
)

install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/rl/rl-config.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rl-${PROJECT_VERSION}
	COMPONENT development
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/rl/rl-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY ExactVersion
)

install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/rl/rl-config-version.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rl-${PROJECT_VERSION}
	COMPONENT development
)

if(DEFINED TARGETS)
	install(
		EXPORT rl
		DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rl-${PROJECT_VERSION}
		NAMESPACE rl::
		FILE rl-export.cmake
		COMPONENT development
	)
endif()
message(STATUS "PROJECT_VERSION = ${PROJECT_VERSION}")
if(RL_BUILD_EXTRAS)
	add_subdirectory(extras)
endif()

#include(CPackConfig)
#include(CPack)
