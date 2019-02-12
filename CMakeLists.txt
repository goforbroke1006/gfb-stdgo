cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)
project(gfb-stdgo
        VERSION 1.0.0
        DESCRIPTION "Clone of Golang standard library for C++"
        )
include(GNUInstallDirs)

file(GLOB SOURCES src/*.cpp)
add_library(${PROJECT_NAME} SHARED
        ${SOURCES}
        include/all.h
        include/channel.h
        include/types.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME} PRIVATE .)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
        DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h*")

add_subdirectory(src)
#target_link_libraries(gfb-stdgo-src)


include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)
enable_testing()
add_subdirectory(test)