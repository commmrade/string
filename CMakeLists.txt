cmake_minimum_required(VERSION 3.0.0)
project(proj VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(proj string.cpp str.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
