cmake_minimum_required(VERSION 3.17)
project(compiler_vm)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(ext/fmt)
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
        parser/token.cc
        parser/token.hh
        parser/nfa_state.hh
        parser/nfa_state.cc
        parser/nfa.hh
        parser/lexer.cc
        parser/lexer.hh
        parser/regex.hh
        parser/dfa.hh
        parser/definition.hh
        parser/definition.cc
        test.cc)

target_link_libraries(compiler_vm fmt)