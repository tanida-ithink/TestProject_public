cmake_minimum_required(VERSION 3.16.3)

project(test_option C CXX)

# GTestパッケージを利用可能にする
find_package(GTest REQUIRED)

add_executable(
    test_main
    isodd.cpp
    sample_test.cpp
)

target_link_libraries(
    test_main
    gtest
    gtest_main
    pthread
)

