cmake_minimum_required(VERSION 3.17)
project(Multimap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
add_executable(${PROJECT_NAME} ${SOURCES})