cmake_minimum_required(VERSION 3.17)
project(compiler_vm)

set(CMAKE_CXX_STANDARD 20)

# CTest
enable_testing()

# Includes.
set(COMPILER_VM_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/common ${PROJECT_SOURCE_DIR}/src/parser)
set(COMPILER_VM_TEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/tests/include)
set(COMPILER_VM_THIRD_PARTY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ext/gtest/googletest ${PROJECT_SOURCE_DIR}/ext/fmt/include)
include_directories(${COMPILER_VM_SRC_INCLUDE_DIR} ${COMPILER_VM_TEST_INCLUDE_DIR} ${COMPILER_VM_THIRD_PARTY_INCLUDE_DIR})
# include_directories(BEFORE src) # This is needed for gtest.


add_subdirectory(ext/fmt)
add_subdirectory(ext/gtest)
add_subdirectory(src)
add_subdirectory(tests)
