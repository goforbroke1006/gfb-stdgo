cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)
project(gfb-stdgo
        VERSION 1.0.0
        DESCRIPTION "Clone of Golang standard library for C++"
        )
include(GNUInstallDirs)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DNDEBUG")

file(GLOB SOURCES src/*.cpp)
add_library(${PROJECT_NAME} SHARED
        ${SOURCES}
        include/all.h
        include/channel.h
        include/types.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME} PRIVATE .)

#install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
if (WIN32 OR MSVC)
    install(TARGETS ${NAME} RUNTIME DESTINATION ${LIB_INSTALL_DIR})
else ()
    #    install(TARGETS ${NAME} LIBRARY DESTINATION path)
    install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif ()


install(
        DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h*")

add_subdirectory(src)

#option(CI_TESTS "CI test suit" ON)
if (UNIX)
    include(test/cmake/googletest.cmake)
    fetch_googletest(
            ${PROJECT_SOURCE_DIR}/test/cmake
            ${PROJECT_BINARY_DIR}/googletest
    )
    enable_testing()
    add_subdirectory(test)
endif (UNIX)