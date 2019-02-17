project(gfb-stdgo-test)

#find_package (Boost COMPONENTS unit_test_framework REQUIRED)



#include(ExternalProject)
#include(../cmake/External_GTest.cmake)

# Locate GTest
#find_package(GTest REQUIRED)
#find_package(gtest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

set(test1_source main.cpp src/time.cpp)
add_executable(${PROJECT_NAME} ${test1_source} src/strings.cpp)
#target_link_libraries(test1 ctest)

#if(WIN32)
#    find_package (Threads)
##    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} gfb-stdgo-src)
##else()
##    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread gfb-stdgo-src)
#endif()
option(gtest_disable_pthreads "Disable uses of pthreads in gtest." ON)
target_link_libraries(${PROJECT_NAME} gtest_main gfb-stdgo-src)

add_test(NAME Test1 COMMAND ${PROJECT_NAME})
