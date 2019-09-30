#
# Foy-Lumiere  CMake script by Colombel Vincent
#

# ┌──────────────────────────────────────────────────────────────────┐
# │                       CMAKE PROPERTIES                           │
# └──────────────────────────────────────────────────────────────────┘

CMAKE_MINIMUM_REQUIRED( VERSION 3.1.0 )

# ┌──────────────────────────────────────────────────────────────────┐
# │                       PROJECT SETTINGS                           │
# └──────────────────────────────────────────────────────────────────┘

SET( FOYLIGHT_TARGET "Foy-light" CACHE STRING "Target Name" )
SET( FOYLIGHT_PROJECT "Foy-light" CACHE STRING "Project Name")
SET( FOYLIGHT_BUILD_SHARED OFF CACHE BOOL "Build as a shared library" )
SET( FOYLIGHT_BUILD_STATIC OFF CACHE BOOL "Build as a static library" )
IF(FOYLIGHT_BUILD_SHARED)
SET( FOYLIGHT_BUILD_EXE OFF CACHE BOOL "Build as an executable" )
ELSE(FOYLIGHT_BUILD_SHARED)
SET( FOYLIGHT_BUILD_EXE ON CACHE BOOL "Build as an executable" )
ENDIF(FOYLIGHT_BUILD_SHARED)
SET( FOYLIGHT_USE_NAMESPACE ON CACHE BOOL "Should the library be compiled with a namespace. Default: ON" )
SET( FOYLIGHT_NAMESPACE "Qqhg" CACHE STRING "Namespace of the library is FOYLIGHT_USE_NAMESPACE is ON. Default : Qqhg" )

SET( QTANDROIDCMAKE_REPOSITORY "https://github.com/OlivierLDff/QtAndroidCMake.git" CACHE STRING "Repository of QtAndroidCMake" )
SET( QTANDROIDCMAKE_TAG "master" CACHE STRING "Git Tag of QtAndroidCMake" )

SET( QTWINDOWSCMAKE_REPOSITORY "https://github.com/OlivierLDff/QtWindowsCMake" CACHE STRING "Repository of QtAndroidCMake" )
SET( QTWINDOWSCMAKE_TAG "master" CACHE STRING "Git Tag of QtAndroidCMake" )



PROJECT( ${FOYLIGHT_PROJECT} )
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# ────────── PRE BUILD PLATFORM DEPENDANCIES ─────────────

INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/platform/PreBuildPlatform.cmake)

# ┌──────────────────────────────────────────────────────────────────┐
# │                         QT5 CMAKE                                │
# └──────────────────────────────────────────────────────────────────┘

# Find includes in corresponding build directories
SET( CMAKE_INCLUDE_CURRENT_DIR ON )
# Instruct CMake to run moc automatically when needed
SET( CMAKE_AUTOMOC ON )
 # https://cmake.org/cmake/help/v3.0/prop_tgt/AUTORCC.html#prop_tgt:AUTORCC
SET( CMAKE_AUTORCC ON )
#required by Qt5
set (CMAKE_CXX_STANDARD 11)

# SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

FIND_PACKAGE(Qt5Core CONFIG REQUIRED ONLY )
FIND_PACKAGE(Qt5Quick CONFIG REQUIRED ONLY )
FIND_PACKAGE(Qt5QuickControls2 CONFIG REQUIRED ONLY )
FIND_PACKAGE(Qt5QuickCompiler CONFIG REQUIRED ONLY )

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# ┌──────────────────────────────────────────────────────────────────┐
# │                       VERSION                                    │
# └──────────────────────────────────────────────────────────────────┘

# Project version must be set here
SET(FOYLIGHT_PROJECT_VERSION_MAJOR 1)
SET(FOYLIGHT_VERSION_MINOR 1)
SET(FOYLIGHT_VERSION_PATCH 0)

IF( EXISTS "${CMAKE_SOURCE_DIR}/.git" )
  EXECUTE_PROCESS(
    COMMAND git describe --always
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE FOYLIGHT_VERSION_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
ENDIF()

IF(NOT FOYLIGHT_VERSION_TAG)
    SET( FOYLIGHT_VERSION_TAG 00000000 )
ENDIF(NOT FOYLIGHT_VERSION_TAG)
SET( FOYLIGHT_VERSION_TAG_HEX 0x${FOYLIGHT_VERSION_TAG})
SET( FOYLIGHT_VERSION ${FOYLIGHT_VERSION_MAJOR}.${FOYLIGHT_VERSION_MINOR}.${FOYLIGHT_VERSION_PATCH} )

# ┌──────────────────────────────────────────────────────────────────┐
# │                       STATUS                                     │
# └──────────────────────────────────────────────────────────────────┘

# ─── GLOBAL ────────
MESSAGE( STATUS "------ ${FOYLIGHT_TARGET} Configuration ------" )
MESSAGE( STATUS "FOYLIGHT_BUILD_SHARED           : ${FOYLIGHT_BUILD_SHARED}" )
MESSAGE( STATUS "FOYLIGHT_BUILD_STATIC           : ${FOYLIGHT_BUILD_STATIC}" )
MESSAGE( STATUS "FOYLIGHT_EXE              	   : ${FOYLIGHT_BUILD_EXE}" )
MESSAGE( STATUS "FOYLIGHT_VERSION                : ${FOYLIGHT_VERSION}" )
MESSAGE( STATUS "FOYLIGHT_VERSION_TAG_HEX        : ${FOYLIGHT_VERSION_TAG_HEX}" )
# ─── NAMESPACE ────────
MESSAGE( STATUS "FOYLIGHT_USE_NAMESPACE          : ${FOYLIGHT_USE_NAMESPACE}" )
IF(FOYLIGHT_USE_NAMESPACE)
MESSAGE( STATUS "FOYLIGHT_NAMESPACE              : ${FOYLIGHT_NAMESPACE}" )
ENDIF(FOYLIGHT_USE_NAMESPACE)

MESSAGE( STATUS "------ ${FOYLIGHT_TARGET} End Configuration ------" )

# ────────── CHECK CONFLICT ──────────────────────────────────────────

IF(FOYLIGHT_BUILD_SHARED)
    IF(FOYLIGHT_BUILD_STATIC)
        MESSAGE( FATAL_ERROR "FOYLIGHT can't compile shared and static library at the same time" )
    ENDIF(FOYLIGHT_BUILD_STATIC)
    IF(FOYLIGHT_BUILD_EXE)
        MESSAGE( FATAL_ERROR "FOYLIGHT can't compile shared library and executable at the same time" )
    ENDIF(FOYLIGHT_BUILD_EXE)
ENDIF(FOYLIGHT_BUILD_SHARED)

IF(FOYLIGHT_BUILD_STATIC)
    IF(FOYLIGHT_BUILD_SHARED)
        MESSAGE( FATAL_ERROR "FOYLIGHT can't compile shared and static library at the same time" )
    ENDIF(FOYLIGHT_BUILD_SHARED)
    IF(FOYLIGHT_BUILD_EXE)
        MESSAGE( FATAL_ERROR "FOYLIGHT can't compile static library and executable at the same time" )
    ENDIF(FOYLIGHT_BUILD_EXE)
ENDIF(FOYLIGHT_BUILD_STATIC)

IF(FOYLIGHT_BUILD_EXE)
    IF(FOYLIGHT_BUILD_SHARED)
        MESSAGE( FATAL_ERROR "FOYLIGHT can't compile shared library and executable at the same time" )
    ENDIF(FOYLIGHT_BUILD_SHARED)
    IF(FOYLIGHT_BUILD_STATIC)
        MESSAGE( FATAL_ERROR "FOYLIGHT can't compile static library and executable at the same time" )
    ENDIF(FOYLIGHT_BUILD_STATIC)
ENDIF(FOYLIGHT_BUILD_EXE)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       DEPENDENCIES                               │
# └──────────────────────────────────────────────────────────────────┘

# ────────── QT STATIC CMAKE ──────────────────────────────────────────

IF(STATIC_QT)
    IF(QT_STATIC_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTSTATICCMAKE)
        MESSAGE( STATUS "Found QtStaticCMake version ${QT_STATIC_CMAKE_VERSION}")
    ELSE(QT_STATIC_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTSTATICCMAKE)
        SET(QQMHG_DOWNLOAD_QTSTATICCMAKE ON CACHE BOOL "The QtStaticCMake library have been downloaded")
        INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildQtStaticCMake.cmake)
        IF(NOT QT_STATIC_CMAKE_FOUND)
            MESSAGE( FATAL_ERROR "Fail to configure QtStaticCMake Library" )
        ENDIF(NOT QT_STATIC_CMAKE_FOUND)
    ENDIF(QT_STATIC_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTSTATICCMAKE)
ENDIF(STATIC_QT)

# ────────── QSM HELPER LIB ──────────────────────────────────────────

IF(QQUICKMATERIALHELPER_TARGET AND NOT QQMHG_DOWNLOAD_QQUICKMATERIALHELPER)
    MESSAGE( STATUS "Found ${QQUICKMATERIALHELPER_TARGET} v${QQUICKMATERIALHELPER_VERSION}" )
ELSE(QQUICKMATERIALHELPER_TARGET AND NOT QQMHG_DOWNLOAD_QQUICKMATERIALHELPER)
    SET(QQMHG_DOWNLOAD_QQUICKMATERIALHELPER ON CACHE BOOL "The QQuickMaterialHelper library have been downloaded")
    INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildQQuickMaterialHelper.cmake)
    IF(NOT QQUICKMATERIALHELPER_TARGET)
        MESSAGE( FATAL_ERROR "Fail to configure QQuickMaterialHelper Library" )
    ENDIF(NOT QQUICKMATERIALHELPER_TARGET)
ENDIF(QQUICKMATERIALHELPER_TARGET AND NOT QQMHG_DOWNLOAD_QQUICKMATERIALHELPER)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       SOURCES                                    │
# └──────────────────────────────────────────────────────────────────┘

file(GLOB_RECURSE FOYLIGHT_QML_SRCS qml/*.qml)

FOREACH(SOURCE IN ITEMS ${FOYLIGHT_QML_SRCS})
    GET_FILENAME_COMPONENT(SOURCE_PATH "${SOURCE}" PATH)
    FILE(RELATIVE_PATH SOURCE_PATH_REL ${CMAKE_CURRENT_SOURCE_DIR} "${SOURCE_PATH}")
    STRING(REPLACE "/" "\\" GROUP_PATH "${SOURCE_PATH_REL}")
    SOURCE_GROUP("${GROUP_PATH}" FILES "${SOURCE}")
ENDFOREACH()

SET( FOYLIGHT_SRCS
    # Main
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FOYLIGHT.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FOYLIGHT.cpp
    ${FOYLIGHT_QML_SRCS}
    )

# ┌──────────────────────────────────────────────────────────────────┐
# │                       TARGET                                     │
# └──────────────────────────────────────────────────────────────────┘

# ────────── QML TO CACHE ───────────

# Add qml to the qtquick compiler
qtquick_compiler_add_resources(FOYLIGHT_QML_RES ${CMAKE_CURRENT_SOURCE_DIR}/qml/FOYLIGHT.qrc)

# Trick to rerun cmake each time qquickHelperGallery.qrc is updated
CONFIGURE_FILE(
  ${CMAKE_CURRENT_SOURCE_DIR}/qml/FOYLIGHT.qrc
  ${CMAKE_CURRENT_BINARY_DIR}/qml.junk
)



# Dont Run Moc on cpp file generated from qml
FOREACH(CacheQml ${FOYLIGHT_QML_RES})
    SET_PROPERTY(SOURCE ${CacheQml} PROPERTY SKIP_AUTOMOC ON)
    SOURCE_GROUP( "QtQuickCompiler Files" FILES ${CacheQml} )
ENDFOREACH(CacheQml)

# ───── SHARED ──────────────

IF(FOYLIGHT_BUILD_SHARED)
    IF( MSVC )
    INCLUDE (GenerateExportHeader)
    ENDIF( MSVC )

    ADD_LIBRARY( ${FOYLIGHT_TARGET} SHARED ${FOYLIGHT_SRCS} ${FOYLIGHT_QML_RES} )

    IF( MSVC )
    GENERATE_EXPORT_HEADER( ${FOYLIGHT_TARGET}
        BASE_NAME ${FOYLIGHT_TARGET}
        EXPORT_MACRO_NAME ${FOYLIGHT_TARGET}_EXPORT
        EXPORT_FILE_NAME ${FOYLIGHT_TARGET}_Export.h
        STATIC_DEFINE ${FOYLIGHT_TARGET}_BUILT_AS_STATIC
    )
    ENDIF( MSVC )

    TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_SHARED )
ENDIF(FOYLIGHT_BUILD_SHARED)

# ───── STATIC ──────────────

IF(FOYLIGHT_BUILD_STATIC)
    ADD_LIBRARY( ${FOYLIGHT_TARGET} STATIC ${FOYLIGHT_SRCS} ${FOYLIGHT_QML_RES} )
    TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_STATIC )
ENDIF(FOYLIGHT_BUILD_STATIC)

# ───── EXE ──────────────

IF(FOYLIGHT_BUILD_EXE)
  ADD_EXECUTABLE( ${FOYLIGHT_TARGET} ${FOYLIGHT_SRCS} ${FOYLIGHT_QML_RES} )
    TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_STATIC )
ENDIF(FOYLIGHT_BUILD_EXE)

# ───── COMMON ──────────────

TARGET_INCLUDE_DIRECTORIES( ${FOYLIGHT_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_MAJOR=${FOYLIGHT_VERSION_MAJOR} )
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_MINOR=${FOYLIGHT_VERSION_MINOR} )
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_PATCH=${FOYLIGHT_VERSION_PATCH} )
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_TAG=${FOYLIGHT_VERSION_TAG} )
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_TAG_HEX=${FOYLIGHT_VERSION_TAG_HEX} )
IF(FOYLIGHT_USE_NAMESPACE)
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_USE_NAMESPACE )
TARGET_COMPILE_DEFINITIONS( ${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_NAMESPACE=${FOYLIGHT_NAMESPACE} )
ENDIF(FOYLIGHT_USE_NAMESPACE)
TARGET_LINK_LIBRARIES( ${FOYLIGHT_TARGET} ${QQUICKMATERIALHELPER_TARGET} )
qt5_use_modules( ${FOYLIGHT_TARGET} Core Gui Svg Xml XmlPatterns Quick QuickControls2 )

IF(STATIC_QT)
    qt_generate_qml_plugin_import(${FOYLIGHT_TARGET} QML_SRC ${CMAKE_CURRENT_SOURCE_DIR}/qml VERBOSE)
    qt_generate_plugin_import(${FOYLIGHT_TARGET} VERBOSE)
ENDIF(STATIC_QT)

# ────────── POST BUILD PLATFORM DEPENDANCIES ─────────────

INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/platform/PostBuildPlatform.cmake)