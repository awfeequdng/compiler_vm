file(GLOB COMPILER_VM_TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*test.cc")

#############
## make targets
#############


##########################################
# "make check-tests"
##########################################
add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)
add_custom_target(check-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

##########################################
# "make XYZ_test"
##########################################
foreach (compiler_vm_test_source ${COMPILER_VM_TEST_SOURCES})
    # Create a human readable name.
    get_filename_component(compiler_vm_test_filename ${compiler_vm_test_source} NAME)
    string(REPLACE ".cc" "" compiler_vm_test_name ${compiler_vm_test_filename})

    # Add the test target separately and as part of "make check-tests".
    add_executable(${compiler_vm_test_name} EXCLUDE_FROM_ALL ${compiler_vm_test_source})
    add_dependencies(build-tests ${compiler_vm_test_name})
    add_dependencies(check-tests ${compiler_vm_test_name})

    target_link_libraries(${compiler_vm_test_name} gtest gmock_main)

    # Set test target properties and dependencies.
    set_target_properties(${compiler_vm_test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
        COMMAND ${compiler_vm_test_name}
    )

    # Add the test under CTest.
    add_test(${compiler_vm_test_name} ${VALGRIND_BIN} ${VALGRIND_OPTIONS}
    --suppressions=${VALGRIND_SUPPRESSIONS_FILE} ${CMAKE_BINARY_DIR}/tests/${compiler_vm_test_name}
    --gtest_color=yes --gtest_output=xml:${CMAKE_BINARY_DIR}/tests/unit_${test_name}.xml)
    add_test(${compiler_vm_test_name} ${CMAKE_BINARY_DIR}/tests/${compiler_vm_test_name} --gtest_color=yes
            --gtest_output=xml:${CMAKE_BINARY_DIR}/tests/${compiler_vm_test_name}.xml)
endforeach(compiler_vm_test_source ${COMPILER_VM_TEST_SOURCES})