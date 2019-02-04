cmake_minimum_required(VERSION 3.12)
project(lcd C)

set(CMAKE_C_STANDARD 99)

add_library(lcd
        lcd.c
        ${BITLOOM_ROOT}/bitloom-lcd/include/lcd/lcd.h
        )

target_include_directories(lcd PUBLIC ${BITLOOM_ROOT}/bitloom-lcd/include)
#target_include_directories(lcd PRIVATE ${BITLOOM_PROJECT_CONFIG})
