cmake_minimum_required(VERSION 3.0)

project(gfb-stdgo)

add_library(gfb-stdgo SHARED
        src/io.cpp
        src/strings.cpp
        src/time.cpp
        src/utf8.cpp
        )


set_target_properties(gfb-stdgo PROPERTIES PUBLIC_HEADER
        "include/all.h"
#        include/io.h
#        include/strings.h
#        include/strings-templates.h
#        include/time.h
#        include/utf8.h
        )
install(
        TARGETS gfb-stdgo
        LIBRARY DESTINATION lib
)
install(
        DIRECTORY include/
        DESTINATION include/${PROJECT_NAME}
)