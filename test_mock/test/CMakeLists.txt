cmake_minimum_required(VERSION 3.16.3)

project(test_mock CXX)

set(APP_DIR
    ../app
)

# テスト用のソースファイル
set(TEST_SOURCES
    src/AirConditionerController_test.cpp
)

# インクルードパス
include_directories(
    ${APP_DIR}/include
    ./include
    ./mock
)

add_subdirectory(${APP_DIR} build)

# GoogleTest/GoogleMockのライブラリのディレクトリ
link_directories(./lib)

add_executable(
    test_main
    ${TEST_SOURCES}
)

target_link_libraries(
    test_main
    APP
    gtest
    gtest_main
    gmock
    gmock_main
    pthread
)