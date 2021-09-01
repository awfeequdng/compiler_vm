cmake_minimum_required(VERSION 3.17)
project(compiler_vm)

set(CMAKE_CXX_STANDARD 20)

# CTest
enable_testing()

add_subdirectory(ext/fmt)
add_subdirectory(ext/gtest)

add_subdirectory(tests)

include_directories(ext/gtest/googletest)
include_directories(ext/fmt/include common parser)
link_directories(${CMAKE_BINARY_DIR}/fmt)

add_executable(compiler_vm
        main.cc
        common/hex_formatter.hh
        common/hex_formatter.cc
        common/colorizer.hh
        common/colorizer.cc
        common/strutil.cc
        common/strutil.hh
        common/result.hh
        common/result_message.hh
        common/errors.hh
        common/errors.cc
        parser/token.cc
        parser/token.hh
        parser/nfa_state.hh
        parser/nfa_state.cc
        parser/nfa.hh
        parser/lexer.cc
        parser/lexer.hh
        parser/regex.hh
        parser/regex.cc
        parser/dfa.hh
        parser/regex_def.hh
        parser/regex_def.cc
        test.cc)

target_link_libraries(compiler_vm fmt)