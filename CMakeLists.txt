cmake_minimum_required(VERSION 3.9)
project(async)

set(CMAKE_CXX_STANDARD 14)

add_library(async SHARED async.cpp async.h "content.h" "content.cpp")

add_executable(async_cli main.cpp "content.h" "content.cpp")

target_link_libraries(async_cli async)