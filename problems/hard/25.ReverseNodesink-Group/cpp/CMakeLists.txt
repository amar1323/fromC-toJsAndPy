cmake_minimum_required(VERSION 3.0.0)
project(inverseKlist VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(inverseKlist main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
target_compile_features(inverseKlist PUBLIC cxx_std_17)
include(CPack)
