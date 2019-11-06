message(STATUS "Post Build Platform Dependancies Configuration")

# ───────── WINDOWS ──────────

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

    if(FOYLIGHT_BUILD_EXE)

        # QtWindowsCMake
        FetchContent_Declare(
            QtWindowsCMake
            GIT_REPOSITORY ${QTWINDOWSCMAKE_REPOSITORY}
            GIT_TAG        ${QTWINDOWSCMAKE_TAG}
        )
        FetchContent_MakeAvailable(QtWindowsCMake)

        message(STATUS "Add QtWindowsCMake for ${FOYLIGHT_TARGET}")
        add_qt_windows_exe(${FOYLIGHT_TARGET}
            ALL
            NAME "FOYLIGHT ${FOYLIGHT_CUSTOMER}"
            RUN_PROGRAM "FOYLIGHT"
            VERSION ${FOYLIGHT_VERSION}
            PUBLISHER "Ereimul"
            PRODUCT_URL ""
            PACKAGE "org.FOYLIGHT.${FOYLIGHT_CUSTOMER}"
            ICON ${CMAKE_CURRENT_SOURCE_DIR}/platform/windows/icon.ico
            ICON_RC ${CMAKE_CURRENT_SOURCE_DIR}/platform/windows/icon.rc
            QML_DIR ${QT_WINDOWS_QT_ROOT}/qml
            NO_TRANSATION
            VERBOSE_LEVEL_DEPLOY 1
            VERBOSE_INSTALLER
        )

        if(MSVC)
            set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${FOYLIGHT_TARGET})
        endif() # MSVC

    endif() # FOYLIGHT_BUILD_EXE
endif() # ${CMAKE_SYSTEM_NAME} STREQUAL "Windows"

# ────────── LINUX ───────────

# ────────── MACOS ───────────

# ───────── ANDROID ──────────

if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")

    # QtAndroidCMake
    FetchContent_Declare(
        QtAndroidCMake
        GIT_REPOSITORY ${QTANDROIDCMAKE_REPOSITORY}
        GIT_TAG        ${QTANDROIDCMAKE_TAG}
    )
    FetchContent_MakeAvailable(QtAndroidCMake)

    if(FOYLIGHT_ANDROID_KEYSTORE)
    set(KEYSTORE_SIGNATURE
        KEYSTORE ${FOYLIGHT_ANDROID_KEYSTORE} ${FOYLIGHT_ANDROID_KEYSTORE_ALIAS}
        KEYSTORE_PASSWORD ${FOYLIGHT_ANDROID_KEYSTORE_PASSWORD}
        )
    endif() # EREIMOTE_ANDROID_KEYSTORE

    add_qt_android_apk(${FOYLIGHT_TARGET}Apk ${FOYLIGHT_TARGET}
        NAME "Foylight"
        VERSION_NAME ${FOYLIGHT_VERSION}
        VERSION_CODE 1
        PACKAGE_NAME "com.foylight"
        PACKAGE_SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/platform/android/src
        ANDROID_MANIFEST_IN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/platform/android/AndroidManifest.xml.in
        ${KEYSTORE_SIGNATURE}
        )

endif() # ${CMAKE_SYSTEM_NAME} STREQUAL "Android"

# ─────────── IOS ────────────
