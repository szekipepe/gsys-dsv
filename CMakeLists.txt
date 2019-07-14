cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)

project(GSysDSV
    VERSION 0.0.1
    DESCRIPTION "Delimiter-separated values parser and serializer"
    HOMEPAGE_URL "https://github.com/szekipepe/gsys-dsv/"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "The minimum version of C++ standard.")

option(GSYS_DSV_BUILD_STATIC_LIB "Build a static version of library" OFF)
option(GSYS_DSV_ENABLE_TESTING   "Enable unit tests"                 ON)

set(gsys_dsv_SRCS
    src/Config.cpp
    src/Parser.cpp
)

if(GSYS_DSV_ENABLE_TESTING)
    enable_testing()
    find_package(GTest)

    if(GTEST_FOUND)
        add_subdirectory(tests)
    endif(GTEST_FOUND)
endif(GSYS_DSV_ENABLE_TESTING)

# Project include
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/GSys/DSV)

if(GSYS_DSV_BUILD_STATIC_LIB)
    add_library(GSysDSV STATIC ${gsys_dsv_SRCS})
else(GSYS_DSV_BUILD_STATIC_LIB)
    add_library(GSysDSV SHARED ${gsys_dsv_SRCS})
endif(GSYS_DSV_BUILD_STATIC_LIB)

target_include_directories(GSysDSV
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
