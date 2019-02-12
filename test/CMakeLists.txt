project(gfb-stdgo-test)

#find_package (Boost COMPONENTS unit_test_framework REQUIRED)



#include(ExternalProject)
#include(../cmake/External_GTest.cmake)

# Locate GTest
#find_package(GTest REQUIRED)
#find_package(gtest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

set(test1_source main.cpp)
add_executable(${PROJECT_NAME} ${test1_source} src/strings.cpp)
#target_link_libraries(test1 ctest)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread gtest_main gfb-stdgo-src)

add_test(NAME Test1 COMMAND ${PROJECT_NAME})
