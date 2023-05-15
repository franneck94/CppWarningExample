cmake_minimum_required(VERSION 3.16)

project(
    "CppTemplate"
    VERSION 1.0.0
    LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." ON)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)

# Project/Library Names
set(LIBRARY_NAME "lib")
set(UNIT_TEST_NAME "unit_tests")
set(EXECUTABLE_NAME "main")

# CMAKE MODULES

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(FetchContent)

include(Warnings)
include(Tools)

add_clang_format_target()

# LIB

set(APP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/BVNS.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Helper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/InitialMODI.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/InitialSolution.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/LocalSearch.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MODI.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Neighborhood.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Shaking.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Solution.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/TestSet.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/UpdateXij.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/VNS.cpp"
)
add_library(${LIBRARY_NAME} STATIC ${APP_SOURCES})

target_set_warnings(
    TARGET
    ${LIBRARY_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})
add_linter_tool_to_target(${LIBRARY_NAME})

# MAIN

set(APP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp"
)
add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})

target_link_libraries(
    ${EXECUTABLE_NAME}
    PUBLIC ${LIBRARY_NAME})

target_set_warnings(
    TARGET
    ${EXECUTABLE_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})
add_linter_tool_to_target(${EXECUTABLE_NAME})
