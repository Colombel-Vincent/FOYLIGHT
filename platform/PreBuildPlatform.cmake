MESSAGE(STATUS "Pre Build Platform Dependancies Configuration")
MESSAGE(STATUS "CMAKE_SYSTEM_NAME :         ${CMAKE_SYSTEM_NAME}")
MESSAGE(STATUS "CMAKE_HOST_SYSTEM_NAME :    ${CMAKE_HOST_SYSTEM_NAME}")

MACRO(download_qbc)

    IF(QBC_FOUND AND NOT QQMHG_DOWNLOAD_QBC)
        MESSAGE( STATUS "Found QBC" )
    ELSE(QBC_FOUND AND NOT QQMHG_DOWNLOAD_QBC)
        SET(QQMHG_DOWNLOAD_QBC ON CACHE BOOL "The Qbc library have been downloaded")
        INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildQBCInstaller.cmake)
        IF(NOT QBC_FOUND)
            MESSAGE( FATAL_ERROR "Fail to configure Qbc Library" )
        ENDIF(NOT QBC_FOUND)
    ENDIF(QBC_FOUND AND NOT QQMHG_DOWNLOAD_QBC)

ENDMACRO(download_qbc)

# ───────── WINDOWS ──────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

    download_qbc()

    IF(QT_WINDOWS_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTWINDOWSCMAKE)
        MESSAGE( STATUS "Found QtWindowsCMake version ${QT_WINDOWS_CMAKE_VERSION}")
    ELSE(QT_WINDOWS_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTWINDOWSCMAKE)
        SET(QQMHG_DOWNLOAD_QTWINDOWSCMAKE ON CACHE BOOL "The QtWindowsCMake library have been downloaded")
        INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildQtWindowsCMake.cmake)
        IF(NOT QT_WINDOWS_CMAKE_FOUND)
            MESSAGE( FATAL_ERROR "Fail to configure QtWindowsCMake Library" )
        ENDIF(NOT QT_WINDOWS_CMAKE_FOUND)
    ENDIF(QT_WINDOWS_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTWINDOWSCMAKE)

ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

# ────────── LINUX ───────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

    download_qbc()

ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

# ────────── MACOS ───────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")

    download_qbc()

ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")

# ───────── ANDROID ──────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "Android") 

    IF(QT_ANDROID_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTANDROIDCMAKE)
        MESSAGE( STATUS "Found QtAndroidCMake version ${QT_ANDROID_CMAKE_VERSION}")
    ELSE(QT_ANDROID_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTANDROIDCMAKE)
        SET(QQMHG_DOWNLOAD_QTANDROIDCMAKE ON CACHE BOOL "The QtAndroidCMake library have been downloaded")
        INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildQtAndroidCMake.cmake)
        IF(NOT QT_ANDROID_CMAKE_FOUND)
            MESSAGE( FATAL_ERROR "Fail to configure QtAndroidCMake Library" )
        ENDIF(NOT QT_ANDROID_CMAKE_FOUND)
    ENDIF(QT_ANDROID_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTANDROIDCMAKE)
        
    SET( QQUICKMATERIALHELPERGALLERY_BUILD_SHARED ON CACHE BOOL "Build as a shared library" FORCE)
    SET( QQUICKMATERIALHELPERGALLERY_BUILD_STATIC OFF CACHE BOOL "Build as a static library" FORCE)
    SET( QQUICKMATERIALHELPERGALLERY_BUILD_EXE OFF CACHE BOOL "Build as an executable" FORCE)

ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Android")

# ─────────── IOS ────────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "iOS")

    IF(QT_IOS_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTIOSCMAKE)
        MESSAGE( STATUS "Found QtIosCMake version ${QT_IOS_CMAKE_VERSION}")
    ELSE(QT_IOS_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTIOSCMAKE)
        SET(QQMHG_DOWNLOAD_QTIOSCMAKE ON CACHE BOOL "The QtIosCMake library have been downloaded")
        INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildQtIosCMake.cmake)
        IF(NOT QT_IOS_CMAKE_FOUND)
            MESSAGE( FATAL_ERROR "Fail to configure QtIosCMake Library" )
        ENDIF(NOT QT_IOS_CMAKE_FOUND)
    ENDIF(QT_IOS_CMAKE_FOUND AND NOT QQMHG_DOWNLOAD_QTIOSCMAKE)

ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "iOS")