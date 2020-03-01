cmake_minimum_required(VERSION 3.10)
project(DameDis)
option(STATIC_BUILD "Build as a static library" OFF)

if(STATIC_BUILD)
	set(SRC
		${CMAKE_SOURCE_DIR}/DisasmFrame.cpp
		${CMAKE_SOURCE_DIR}/DisasmFrame.h
		${CMAKE_SOURCE_DIR}/DisasmListCtrl.cpp
		${CMAKE_SOURCE_DIR}/DisasmListCtrl.h
		${CMAKE_SOURCE_DIR}/Disassembler.cpp
		${CMAKE_SOURCE_DIR}/Disassembler.h
		${CMAKE_SOURCE_DIR}/InstructionSet.h
		${CMAKE_SOURCE_DIR}/Cartridge.cpp
		${CMAKE_SOURCE_DIR}/Cartridge.h
		)

	add_definitions(-D_BUILD_STATIC_)
	add_library(DameDis STATIC ${SRC})
else()
	set(SRC
		${CMAKE_SOURCE_DIR}/MainApp.cpp
		${CMAKE_SOURCE_DIR}/MainApp.h
		${CMAKE_SOURCE_DIR}/DisasmFrame.cpp
		${CMAKE_SOURCE_DIR}/DisasmFrame.h
		${CMAKE_SOURCE_DIR}/DisasmListCtrl.cpp
		${CMAKE_SOURCE_DIR}/DisasmListCtrl.h
		${CMAKE_SOURCE_DIR}/Disassembler.cpp
		${CMAKE_SOURCE_DIR}/Disassembler.h
		${CMAKE_SOURCE_DIR}/InstructionSet.h
		${CMAKE_SOURCE_DIR}/Cartridge.cpp
		${CMAKE_SOURCE_DIR}/Cartridge.h
		)
	
	add_executable(DameDis ${SRC})
endif()

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if(WIN32)
	set_target_properties(DameDis PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
	add_definitions(
		-DWIN32
		-D_WXMSW_
		-D_WINDOWS
	)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	message("DEBUG BUILD")
	add_definitions(
		-D_DEBUG
		-D__WXDEBUG__
		)
endif()

find_package(wxWidgets REQUIRED COMPONENTS core base)
 if(wxWidgets_FOUND)
    message(STATUS "Found wxWidgets ${wxWidgets_VERSION_STRING} in ${wxWidgets_USE_FILE}")
    set(wxWidgets_USE_STATIC ON)
    include(${wxWidgets_USE_FILE})
    include_directories(${wxWidgets_INCLUDE_DIRS})
    target_link_libraries(DameDis ${wxWidgets_LIBRARIES})
endif()