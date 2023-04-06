cmake_minimum_required(VERSION 3.0.0)
project(mergedKSortedList VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(mergedKSortedList main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
target_compile_features(mergedKSortedList PUBLIC cxx_std_17)
include(CPack)
