cmake_minimum_required(VERSION 3.0.0)
project(6502emu VERSION 0.1.0 LANGUAGES C CXX)

include(cmake/UpdateSubmodules.cmake)
add_subdirectory(external)


include(CTest)
enable_testing()



include_directories(external/googletest/incldue)
set(SOURCE_FILES 
    main.cpp 
    Logger.cpp
    cpu.cpp cpu6502.cpp 
    memory.cpp
    io.cpp 
    system.cpp 
    system6502_basic.cpp
    main_test.cpp
    )
add_executable(6502emu ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
