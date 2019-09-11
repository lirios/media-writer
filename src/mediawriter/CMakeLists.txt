liri_add_executable(LiriMediaWriter
    OUTPUT_NAME
        "mediawriter"
    SOURCES
        crashhandler.cpp
        crashhandler.h
        downloadmanager.cpp
        downloadmanager.h
        drivemanager.cpp
        drivemanager.h
        fakedrivemanager.cpp
        fakedrivemanager.h
        main.cpp
        notifications.cpp
        notifications.h
        releasemanager.cpp
        releasemanager.h
        utilities.cpp
        utilities.h
        versionchecker.cpp
        versionchecker.h
    RESOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/qml.qrc"
        "${CMAKE_CURRENT_SOURCE_DIR}/assets.qrc"
        "${CMAKE_SOURCE_DIR}/translations/translations.qrc"
    DEFINES
        QT_NO_CAST_FROM_ASCII
        QT_NO_FOREACH
        MEDIAWRITER_VERSION="${PROJECT_VERSION}"
    LIBRARIES
        Qt5::Core
        Qt5::Widgets
        Qt5::Network
        Qt5::X11Extras
        Qt5::Qml
        Qt5::Quick
        MediaWriter::IsoMD5
)

liri_extend_target(LiriMediaWriter
    CONDITION LINUX
    SOURCES
        linuxdrivemanager.cpp
        linuxdrivemanager.h
    LIBRARIES
        Qt5::DBus
)

liri_extend_target(LiriMediaWriter
    CONDITION APPLE_OSX
    SOURCES
        macdrivearbiter.h
        macdrivemanager.cpp
        macdrivemanager.h
)

liri_extend_target(LiriMediaWriter
    CONDITION WIN32
    SOURCES
        windrivemanager.cpp
        windrivemanager.h
)
