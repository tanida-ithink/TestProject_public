cmake_minimum_required(VERSION 3.16.3)

include_directories(
    include
)

add_library(APP
    src/AirConditionerController.cpp
    driver/TemperatureSensor.cpp
)

