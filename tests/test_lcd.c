/*
 * Unit tests for the Bit Loom scheduler.
 *
 * Copyright (c) 2019. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "unity_fixture.h"
#include "core/scheduler.h"
#include "lcd/lcd.h"

/*
 * Tests to be written:
 */

TEST_GROUP(lcd);
TEST_GROUP_RUNNER(lcd)
{
    RUN_TEST_CASE(lcd, init);
}

TEST_SETUP(lcd)
{
}

TEST_TEAR_DOWN(lcd)
{
}

/*
 * TEST CASES
 */
TEST(lcd, init)
{
    lcd_init();
}

