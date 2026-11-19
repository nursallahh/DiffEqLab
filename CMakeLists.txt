cmake_minimum_required(VERSION 3.20)
project(DiffEqLab VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Kendi hedeflerimiz icin katı derleyici uyarilari
function(diffeqlab_set_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /WX)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
endfunction()

# 1. Cekirdek kutuphane (mathcore)
add_library(mathcore STATIC
    mathcore/expr/smoke.cpp
)
target_include_directories(mathcore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
diffeqlab_set_warnings(mathcore)

# 2. Terminal arayuzu (cli)
add_executable(diffeqlab_cli
    cli/main.cpp
)
target_link_libraries(diffeqlab_cli PRIVATE mathcore)
diffeqlab_set_warnings(diffeqlab_cli)

# 3. Testler (GoogleTest)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(diffeqlab_tests
    tests/test_smoke.cpp
)
target_link_libraries(diffeqlab_tests PRIVATE mathcore GTest::gtest_main)
diffeqlab_set_warnings(diffeqlab_tests)

include(GoogleTest)
gtest_discover_tests(diffeqlab_tests)