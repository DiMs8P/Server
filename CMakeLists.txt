cmake_minimum_required(VERSION 3.29)
project(ClionTest)

set(CMAKE_CXX_STANDARD 26)

find_package(PostgreSQL REQUIRED)
find_package(libpqxx REQUIRED)
find_package(CURL REQUIRED)
find_package(benchmark REQUIRED)

include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(${libpqxx_INCLUDE_DIRS})

add_executable(ClionTest main.cpp)

target_include_directories(ClionTest PRIVATE ${CURL_INCLUDE_DIRS})

target_link_libraries(ClionTest ${PostgreSQL_LIBRARIES} pqxx pq)
target_link_libraries(ClionTest benchmark::benchmark)
target_link_libraries(ClionTest ${CURL_LIBRARIES})
