
file(GLOB SOURCES *.cpp)

add_library(gfb-stdgo-src
        ../include/channel.h
        ../include/io.h
        ../include/strings.h
        ../include/strings-templates.h
        ../include/time.h
        ../include/time_win32.h
        ../include/types.h
        ../include/utf8.h
        ${SOURCES})