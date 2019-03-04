project(001-net-http-get-request)

add_executable(${PROJECT_NAME} main.cpp
        ${CMAKE_SOURCE_DIR}/src/net/http.cpp)

target_link_libraries(${PROJECT_NAME} curl)