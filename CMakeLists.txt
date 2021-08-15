cmake_minimum_required(VERSION 3.0.0)
project(CppSOP VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SDL2 CONFIG REQUIRED)
add_executable(CppSOP main.cpp)
target_link_libraries(CppSOP PRIVATE SDL2::SDL2 SDL2::SDL2main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
