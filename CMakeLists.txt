#
#   FOYLIGHT CMake script by Olivier Le Doeuff
#

# ┌──────────────────────────────────────────────────────────────────┐
# │                       CMAKE PROPERTIES                           │
# └──────────────────────────────────────────────────────────────────┘

CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       PROJECT SETTINGS                           │
# └──────────────────────────────────────────────────────────────────┘

set(FOYLIGHT_TARGET "FOYLIGHT" CACHE STRING "Target Name")
set(FOYLIGHT_PROJECT "FOYLIGHT" CACHE STRING "Project Name")
set(FOYLIGHT_BUILD_SHARED OFF CACHE BOOL "Build as a shared library")
set(FOYLIGHT_BUILD_STATIC OFF CACHE BOOL "Build as a static library")
if(FOYLIGHT_BUILD_SHARED)
set(FOYLIGHT_BUILD_EXE OFF CACHE BOOL "Build as an executable")
else(FOYLIGHT_BUILD_SHARED)
set(FOYLIGHT_BUILD_EXE ON CACHE BOOL "Build as an executable")
endif(FOYLIGHT_BUILD_SHARED)
set(FOYLIGHT_USE_NAMESPACE ON CACHE BOOL "Should the library be compiled with a namespace. Default: ON")
set(FOYLIGHT_NAMESPACE "FL" CACHE BOOL "Namespace of the library is FOYLIGHT_USE_NAMESPACE is ON. Default : ErMt")

set(LIBENDIAN_REPOSITORY "https://github.com/OlivierLDff/LibEndian.git" CACHE STRING "Repository of LibEndian")
set(LIBENDIAN_TAG "master" CACHE STRING "Git Tag of LibEndian")

set(QQMLMODEL_REPOSITORY "https://github.com/OlivierLDff/QQmlModel.git" CACHE STRING "Repository of QQmlModel")
set(QQMLMODEL_TAG "master" CACHE STRING "Git Tag of QQmlModel")

set(QSUPERMACROS_REPOSITORY "https://github.com/OlivierLDff/QSuperMacros.git" CACHE STRING "Repository of QSuperMacros")
set(QSUPERMACROS_TAG "master" CACHE STRING "Git Tag of QSuperMacros")

set(QBC_REPOSITORY "https://github.com/OlivierLDff/QbcInstaller.git" CACHE STRING "Repository of Qbc")
set(QBC_TAG "master" CACHE STRING "Git Tag of Qbc")

set(QTANDROIDCMAKE_REPOSITORY "https://github.com/OlivierLDff/QtAndroidCMake.git" CACHE STRING "Repository of QtAndroidCMake")
set(QTANDROIDCMAKE_TAG "master" CACHE STRING "Git Tag of QtAndroidCMake")

set(QTWINDOWSCMAKE_REPOSITORY "https://github.com/OlivierLDff/QtWindowsCMake" CACHE STRING "Repository of QtAndroidCMake")
set(QTWINDOWSCMAKE_TAG "master" CACHE STRING "Git Tag of QtAndroidCMake")

set(QQUICKMATERIALHELPER_REPOSITORY "https://github.com/OlivierLDff/QQuickMaterialHelper.git" CACHE STRING "Repository of QQuickMaterialHelper")
set(QQUICKMATERIALHELPER_TAG "master" CACHE STRING "Git Tag of QQuickMaterialHelper")

project(${FOYLIGHT_PROJECT})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ────────── PRE BUILD PLATFORM DEPENDANCIES ─────────────

include(${CMAKE_CURRENT_SOURCE_DIR}/platform/PreBuildPlatform.cmake)

# ┌──────────────────────────────────────────────────────────────────┐
# │                         QT5 CMAKE                                │
# └──────────────────────────────────────────────────────────────────┘

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
 # https://cmake.org/cmake/help/v3.0/prop_tgt/AUTORCC.html#prop_tgt:AUTORCC
set(CMAKE_AUTORCC ON)
#required by Qt5
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

find_package(Qt5Core CONFIG REQUIRED CMAKE_FIND_ROOT_PATH_BOTH)
find_package(Qt5Quick CONFIG REQUIRED CMAKE_FIND_ROOT_PATH_BOTH)
find_package(Qt5QuickControls2 CONFIG REQUIRED CMAKE_FIND_ROOT_PATH_BOTH)
find_package(Qt5QuickCompiler CONFIG REQUIRED CMAKE_FIND_ROOT_PATH_BOTH)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# ┌──────────────────────────────────────────────────────────────────┐
# │                       VERSION                                    │
# └──────────────────────────────────────────────────────────────────┘

# Project version must be set here
set(FOYLIGHT_VERSION_MAJOR 2)
set(FOYLIGHT_VERSION_MINOR 2)
set(FOYLIGHT_VERSION_PATCH 0)

if( EXISTS "${CMAKE_SOURCE_DIR}/.git")
    EXECUTE_PROCESS(
        COMMAND git rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE FOYLIGHT_VERSION_TAG
        OUTPUT_STRIP_TRAILING_WHITESPACE
   )
else()
    set(FOYLIGHT_VERSION_TAG 00000000)
endif()
set(FOYLIGHT_VERSION_TAG_HEX 0x${FOYLIGHT_VERSION_TAG})
set(FOYLIGHT_VERSION ${FOYLIGHT_VERSION_MAJOR}.${FOYLIGHT_VERSION_MINOR}.${FOYLIGHT_VERSION_PATCH})


# ┌──────────────────────────────────────────────────────────────────┐
# │                       STATUS                                     │
# └──────────────────────────────────────────────────────────────────┘

# ─── GLOBAL ────────
message("------ ${FOYLIGHT_TARGET} Configuration ------")
message(STATUS "FOYLIGHT_BUILD_SHARED           : ${FOYLIGHT_BUILD_SHARED}")
message(STATUS "FOYLIGHT_BUILD_STATIC           : ${FOYLIGHT_BUILD_STATIC}")
message(STATUS "FOYLIGHT_BUILD_EXE              : ${FOYLIGHT_BUILD_EXE}")
message(STATUS "FOYLIGHT_VERSION                : ${FOYLIGHT_VERSION}")
message(STATUS "FOYLIGHT_VERSION_TAG_HEX        : ${FOYLIGHT_VERSION_TAG_HEX}")
# ─── NAMESPACE ────────
message(STATUS "FOYLIGHT_USE_NAMESPACE          : ${FOYLIGHT_USE_NAMESPACE}")
if(FOYLIGHT_USE_NAMESPACE)
message(STATUS "FOYLIGHT_NAMESPACE              : ${FOYLIGHT_NAMESPACE}")
endif(FOYLIGHT_USE_NAMESPACE)
message(STATUS "FOYLIGHT_CUSTOMER_RES           : ${FOYLIGHT_CUSTOMER_RES}")
message(STATUS "PATH_TO_QML_CUSTOMER_PAGE       : ${PATH_TO_QML_CUSTOMER_PAGE}")

message("------ ${FOYLIGHT_TARGET} End Configuration ------")

# ────────── CHECK CONFLICT ──────────────────────────────────────────

if(FOYLIGHT_BUILD_SHARED)
    if(FOYLIGHT_BUILD_STATIC)
        message(FATAL_ERROR "FOYLIGHT can't compile shared and static library at the same time")
    endif(FOYLIGHT_BUILD_STATIC)
    if(FOYLIGHT_BUILD_EXE)
        message(FATAL_ERROR "FOYLIGHT can't compile shared library and executable at the same time")
    endif(FOYLIGHT_BUILD_EXE)
endif(FOYLIGHT_BUILD_SHARED)

if(FOYLIGHT_BUILD_STATIC)
    if(FOYLIGHT_BUILD_SHARED)
        message(FATAL_ERROR "FOYLIGHT can't compile shared and static library at the same time")
    endif(FOYLIGHT_BUILD_SHARED)
    if(FOYLIGHT_BUILD_EXE)
        message(FATAL_ERROR "FOYLIGHT can't compile static library and executable at the same time")
    endif(FOYLIGHT_BUILD_EXE)
endif(FOYLIGHT_BUILD_STATIC)

if(FOYLIGHT_BUILD_EXE)
    if(FOYLIGHT_BUILD_SHARED)
        message(FATAL_ERROR "FOYLIGHT can't compile shared library and executable at the same time")
    endif(FOYLIGHT_BUILD_SHARED)
    if(FOYLIGHT_BUILD_STATIC)
        message(FATAL_ERROR "FOYLIGHT can't compile static library and executable at the same time")
    endif(FOYLIGHT_BUILD_STATIC)
endif(FOYLIGHT_BUILD_EXE)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       DEPENDENCIES                               │
# └──────────────────────────────────────────────────────────────────┘

include(FetchContent)

# libEndian
FetchContent_Declare(
    LibEndian
    GIT_REPOSITORY ${LIBENDIAN_REPOSITORY}
    GIT_TAG        ${LIBENDIAN_TAG}
)

# QSuperMacros
FetchContent_Declare(
    QSuperMacros
    GIT_REPOSITORY ${QSUPERMACROS_REPOSITORY}
    GIT_TAG        ${QSUPERMACROS_TAG}
)

# ObjectListModel
FetchContent_Declare(
    ObjectListModel
    GIT_REPOSITORY ${QQMLMODEL_REPOSITORY}
    GIT_TAG        ${QQMLMODEL_TAG}
)

# MaterialHelper
FetchContent_Declare(
    QQuickMaterialHelper
    GIT_REPOSITORY ${QQUICKMATERIALHELPER_REPOSITORY}
    GIT_TAG        ${QQUICKMATERIALHELPER_TAG}
)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET ON)

# Make all dependencies avaiables
FetchContent_MakeAvailable(QQuickMaterialHelper LibEndian QSuperMacros ObjectListModel)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       SOURCES                                    │
# └──────────────────────────────────────────────────────────────────┘

# Get all the qml files inside the qml dir
file(GLOB_RECURSE FOYLIGHT_QML_SRCS qml/*.qml)

# Then set a folder inside IDE
foreach(_source IN ITEMS ${FOYLIGHT_QML_SRCS})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel ${CMAKE_CURRENT_SOURCE_DIR} "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

set(FOYLIGHT_SHARED_RES ${CMAKE_CURRENT_SOURCE_DIR}/qml/FOYLIGHT.qrc)

set(FOYLIGHT_SRCS
    # FOYLIGHT entry point
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FOYLIGHT.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FOYLIGHT.hpp

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

if(FOYLIGHT_BUILD_SHARED)
    ADD_LIBRARY( ${FOYLIGHT_TARGET} SHARED ${FOYLIGHT_SRCS} ${FOYLIGHT_QML_RES})
    target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_SHARED)
endif(FOYLIGHT_BUILD_SHARED)

# ───── STATIC ──────────────

if(FOYLIGHT_BUILD_STATIC)
    ADD_LIBRARY( ${FOYLIGHT_TARGET} STATIC ${FOYLIGHT_SRCS} ${FOYLIGHT_QML_RES})
    target_compile_definitions(${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_STATIC)
endif(FOYLIGHT_BUILD_STATIC)

# ───── EXE ──────────────

if(FOYLIGHT_BUILD_EXE)
    add_executable(${FOYLIGHT_TARGET} ${FOYLIGHT_SRCS} ${FOYLIGHT_QML_RES})
    target_compile_definitions(${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_STATIC)
endif(FOYLIGHT_BUILD_EXE)

# ───── COMMON ──────────────

target_include_directories(${FOYLIGHT_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Set version
target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_MAJOR=${FOYLIGHT_VERSION_MAJOR})
target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_MINOR=${FOYLIGHT_VERSION_MINOR})
target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_PATCH=${FOYLIGHT_VERSION_PATCH})
target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_TAG=${FOYLIGHT_VERSION_TAG})
target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_VERSION_TAG_HEX=${FOYLIGHT_VERSION_TAG_HEX})

# Page to load in Main.qml
target_compile_definitions(${FOYLIGHT_TARGET} PRIVATE -DFOYLIGHT_QML_CUSTOMER_PAGE="${PATH_TO_QML_CUSTOMER_PAGE}")

# Set namespace
if(FOYLIGHT_USE_NAMESPACE)
    target_compile_definitions(${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_USE_NAMESPACE)
    target_compile_definitions(${FOYLIGHT_TARGET} PUBLIC -DFOYLIGHT_NAMESPACE=${FOYLIGHT_NAMESPACE})
endif() # FOYLIGHT_USE_NAMESPACE

# Link to library we depend on
target_link_libraries(${FOYLIGHT_TARGET} ${QQUICKMATERIALHELPER_TARGET} ${QSUPERMACROS_TARGET} ${QQMLMODEL_TARGET} ${LIBENDIAN_TARGET})
# Link to qt library we depend on
qt5_use_modules(${FOYLIGHT_TARGET} Core Network Gui Svg Xml XmlPatterns Quick QuickControls2)

# ────────── POST BUILD PLATFORM DEPENDANCIES ─────────────

include(${CMAKE_CURRENT_SOURCE_DIR}/platform/PostBuildPlatform.cmake)
