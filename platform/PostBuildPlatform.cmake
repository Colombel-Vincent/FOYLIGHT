MESSAGE(STATUS "Post Build Platform Dependancies Configuration")

# ───────── WINDOWS ──────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    IF(FOYLIGHT_BUILD_EXE)

        MESSAGE(STATUS "Add QtWindowsCMake for ${FOYLIGHT_TARGET}")
        add_qt_windows_exe( ${FOYLIGHT_TARGET}
            ALL
            NAME "Foy-light"
            VERSION ${FOYLIGHT_VERSION}
            PUBLISHER "Vincent"
            PRODUCT_URL "www.foy-light.com"
            PACKAGE "com.vincent"
            ICON ${CMAKE_CURRENT_SOURCE_DIR}/platform/windows/icon.ico
            ICON_RC ${CMAKE_CURRENT_SOURCE_DIR}/platform/windows/icon.rc
            QML_DIR ${QT_WINDOWS_QT_ROOT}/qml
            NO_TRANSATION
            VERBOSE_LEVEL_DEPLOY 1
            VERBOSE_INSTALLER
         )

    ENDIF(FOYLIGHT_BUILD_EXE)
ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

# ────────── LINUX ───────────

# ────────── MACOS ───────────

# ───────── ANDROID ──────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "Android")

    # Set keystore variable
    IF(FOYLIGHT_ANDROID_KEYSTORE)
    SET(KEYSTORE_SIGNATURE
        KEYSTORE ${FOYLIGHT_ANDROID_KEYSTORE} ${FOYLIGHT_ANDROID_KEYSTORE_ALIAS}
        KEYSTORE_PASSWORD ${FOYLIGHT_ANDROID_KEYSTORE_PASSWORD}
        )
    ENDIF(FOYLIGHT_ANDROID_KEYSTORE)

    add_qt_android_apk(${FOYLIGHT_TARGET}Apk ${FOYLIGHT_TARGET}
        NAME "Foy & lumiere"
        VERSION_NAME ${FOYLIGHT_VERSION}
        VERSION_CODE 1 # Must be incremented on each release
        PACKAGE_NAME "foy & lumiere"
        PACKAGE_SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/platform/android/src
        ANDROID_MANIFEST_IN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/platform/android/AndroidManifest.xml.in
        ${KEYSTORE_SIGNATURE}
    )

ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "Android")

# ─────────── IOS ────────────

IF(${CMAKE_SYSTEM_NAME} STREQUAL "iOS")

    # We can't have empty flags
    IF(NOT TEAM_ID)
        SET(TEAM_ID "AAAAAAAA")
    ENDIF(NOT TEAM_ID)

    add_qt_ios_app(${FOYLIGHT_TARGET}
        NAME "Qml foy & lumiere"
        BUNDLE_IDENTIFIER "com.oliv.materialGallery"
        VERSION ${FOYLIGHT_VERSION}
        LONG_VERSION ${FOYLIGHT_VERSION}.${FOYLIGHT_VERSION_TAG}
        CODE_SIGN_IDENTITY "iPhone Developer"
        TEAM_ID ${TEAM_ID} # TEAM_ID must be specified when executing cmake or later in XCode
        COPYRIGHT "Copyright Vincent Colombel 2019"
        ASSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/platform/ios/Assets.xcassets"
        LAUNCHSCREEN_STORYBOARD "${CMAKE_CURRENT_SOURCE_DIR}/platform/ios/LaunchScreen.storyboard"
        MAIN_STORYBOARD "${CMAKE_CURRENT_SOURCE_DIR}/platform/ios/Main.storyboard"
        ORIENTATION_PORTRAIT
        ORIENTATION_PORTRAIT_UPDOWN
        ORIENTATION_LANDSCAPE_LEFT
        ORIENTATION_LANDSCAPE_RIGHT
        SUPPORT_IPHONE
        SUPPORT_IPAD
        VERBOSE
    )
ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "iOS")


