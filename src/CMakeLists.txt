# This is hacky :(
file(GLOB_RECURSE compiler_vm_sources ${PROJECT_SOURCE_DIR}/src/*/*.cc ${PROJECT_SOURCE_DIR}/src/*/*/*.cc)

add_library(compiler_vm_shared SHARED ${compiler_vm_sources})

# link_directories(${CMAKE_BINARY_DIR}/fmt)

add_executable(compiler_vm main.cc ${compiler_vm_sources})

target_link_libraries(compiler_vm fmt)