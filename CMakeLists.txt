cmake_minimum_required(VERSION 3.10.0)

project("MediaWriter"
    VERSION "0.0.0"
    DESCRIPTION "Writes Liri OS images to the disk"
    LANGUAGES CXX C
)

set(LIRI_LOCAL_ECM TRUE)
list(APPEND CMAKE_MODULE_PATH "/home/plfiorini/tmp/lirios/libraries/cmake-shared/modules")

## Shared macros and functions:
if(NOT LIRI_LOCAL_ECM)
    find_package(LiriCMakeShared "1.0.0" REQUIRED NO_MODULE)
    list(APPEND CMAKE_MODULE_PATH "${LCS_MODULE_PATH}")
endif()

## Set minimum versions required:
set(QT_MIN_VERSION "5.10.0")

## Add some paths to check for CMake modules:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

## Liri specific setup common for all modules:
include(LiriSetup)

## Find Qt 5:
find_package(Qt5 "${QT_MIN_VERSION}"
    CONFIG REQUIRED
    COMPONENTS
        Core
        DBus
        Gui
        Widgets
        X11Extras
        Qml
        Quick
        QuickControls2
        LinguistTools
)

## Add subdirectories:
if(LINUX)
    add_subdirectory(src/helper/linux)
endif()
#if(WIN32)
#    add_subdirectory(src/helper/win)
#endif()
#if(APPLE_OSX)
#    add_subdirectory(src/helper/mac)
#endif()
add_subdirectory(src/isomd5)
add_subdirectory(src/mediawriter)
