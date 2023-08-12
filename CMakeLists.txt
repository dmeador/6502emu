cmake_minimum_required(VERSION 3.1.4)
project(6502emu VERSION 0.1.0 LANGUAGES C CXX)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
#set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)

#include(cmake/UpdateSubmodules.cmake)
#include_directories(external/googletest/include)
set(SOURCE_FILES 
    main.cpp 
    Logger.cpp
    cpu.cpp cpu6502.cpp 
    memory.cpp
    io.cpp 
    system.cpp 
    system6502_basic.cpp
    )
add_executable(6502emu ${SOURCE_FILES})
#add_subdirectory(external)



#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
#include(CTest)

#build tests

add_subdirectory(test)
enable_testing()
#add_test(${TESTNAME} ${TESTNAME})
include(GoogleTest)
project(maintest )
add_executable(maintest main_test.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(maintest gtest gtest_main)
add_test(maintest maintest)
