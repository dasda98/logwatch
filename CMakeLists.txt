cmake_minimum_required(VERSION 3.31)
project(LogWatch C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(logger STATIC src/logger.c)

target_include_directories(logger PUBLIC include)

add_executable(test tests/test_logger.c)
target_link_libraries(test logger)

if(UNIX)
  target_link_libraries(logger pthread)
  target_link_libraries(test pthread)
endif()
