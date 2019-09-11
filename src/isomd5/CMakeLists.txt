add_library(isomd5 STATIC
    libcheckisomd5.c
    libcheckisomd5.h
    md5.c
    md5.h
)
add_library("MediaWriter::IsoMD5" ALIAS "isomd5")
target_include_directories("isomd5"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9")
