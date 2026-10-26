cmake_minimum_required(VERSION 3.20)
project(SynergyCase4GoogleTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Для Windows: не переопределять настройки CRT.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(interface_tests
  tests/interface_tests.cpp
)
target_include_directories(interface_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(interface_tests PRIVATE GTest::gtest_main GTest::gmock)

include(GoogleTest)
gtest_discover_tests(interface_tests)
