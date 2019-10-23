cmake_minimum_required(VERSION 3.10)

project(fast_strcat_test LANGUAGES CXX)

add_executable(fast_strcat_test
    test/main.cpp
)

target_include_directories(fast_strcat_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(fast_strcat_test PRIVATE cxx_std_17)
