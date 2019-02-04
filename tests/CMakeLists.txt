cmake_minimum_required(VERSION 3.12)
project(bitloom_lcd_test C)

set(CMAKE_C_STANDARD 99)
set(UNITY_HOME $ENV{UNITY_HOME})
set(BITLOOM_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." CACHE STRING "Root folder for all Bitloom projects")
set(BITLOOM_CONFIG ${CMAKE_CURRENT_SOURCE_DIR})

message("BITLOOM_ROOT: ${BITLOOM_ROOT}")
message("UNITY_HOME: ${UNITY_HOME}")
message("Config dir: ${BITLOOM_CONFIG}")

include_directories(${UNITY_HOME}/src)
include_directories(${UNITY_HOME}/extras/fixture/src)
add_subdirectory(${BITLOOM_ROOT}/bitloom-costumes libs)

add_compile_options(-Wall -Wextra -Wpedantic)

set(UNITY_FILES
        ${UNITY_HOME}/extras/fixture/src/unity_fixture.c
        ${UNITY_HOME}/src/unity.c
        )

add_executable(bitloom_lcd_test
        ${UNITY_FILES}
        #${BITLOOM_ROOT}/bitloom-lcd/include/lcd/lcd.h
        test_lcd_main.c
        test_lcd.c
        )

# The following directory includes the project specific configurations
# Hence it needs to be available for all targets.
include_directories(${BITLOOM_CONFIG})

target_include_directories(bitloom_lcd_test PRIVATE ${BITLOOM_ROOT}/bitloom-lcd/include)
target_include_directories(bitloom_lcd_test PRIVATE ${BITLOOM_ROOT}/bitloom-core/include)

add_subdirectory(${BITLOOM_ROOT}/bitloom-lcd/src libs/lcd)

target_link_libraries(bitloom_lcd_test bitloom-costumes)
target_link_libraries(bitloom_lcd_test lcd)

