cmake_minimum_required(VERSION 3.31)
project(LogWatch C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(logwatch STATIC src/logwatch.c)

target_include_directories(logwatch PUBLIC include)

add_executable(test tests/test_logwatch.c)
target_link_libraries(test logwatch)

if(UNIX)
  target_link_libraries(logwatch pthread)
  target_link_libraries(test pthread)
endif()
