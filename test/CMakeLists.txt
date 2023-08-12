# Build output setup
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
project(googletest-git NONE)
################################
# Tests
################################
# Add test cpp file
enable_testing()
set(TESTNAME "TestRunner")
project(${TESTNAME})
add_executable(${TESTNAME} testgtest.cpp)
# Link test executable against gtest & gtest_main


target_link_libraries(${TESTNAME} gtest gtest_main)
add_test(${TESTNAME} ${TESTNAME})
#include(GoogleTest)
#gtest_discover_tests(${TESTNAME})