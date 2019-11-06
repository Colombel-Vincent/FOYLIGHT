message(STATUS "Pre Build Platform Dependancies Configuration")
message(STATUS "CMAKE_SYSTEM_NAME :         ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_HOST_SYSTEM_NAME :    ${CMAKE_HOST_SYSTEM_NAME}")

# ───────── WINDOWS ──────────

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

	set(FOYLIGHT_PLATFORM_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/platform/windows/icon.rc")
	set(FOYLIGHT_PLATFORM_TARGET WIN32)

endif() # ${CMAKE_SYSTEM_NAME} STREQUAL "Windows"

# ────────── LINUX ───────────

# ────────── MACOS ───────────

# ───────── ANDROID ──────────

if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")

    set(FOYLIGHT_BUILD_SHARED ON CACHE BOOL "Build as a shared library" FORCE)
    set(FOYLIGHT_BUILD_STATIC OFF CACHE BOOL "Build as a static library" FORCE)
    set(FOYLIGHT_BUILD_EXE OFF CACHE BOOL "Build as an executable" FORCE)

endif() # ${CMAKE_SYSTEM_NAME} STREQUAL "Android"

# ─────────── IOS ────────────