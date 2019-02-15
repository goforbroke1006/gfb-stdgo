//
// Created by goforbroke on 15.02.19.
//

#include <gtest/gtest.h>

#include "../../include/time.h"

constexpr int64 DATE_0 = 1262304000; // 1th Jan 2010 00:00:00
constexpr int64 DATE_1 = 1293101100; // 23th Dec 2010 10:45:00

TEST(time_Time_getUnixDaysCount, positive) {
    ASSERT_EQ(0, gfb::stdgo::time::Time::getUnixDaysCount(1970, 1, 1));
    ASSERT_EQ(365, gfb::stdgo::time::Time::getUnixDaysCount(1971, 1, 1));
    ASSERT_EQ(730, gfb::stdgo::time::Time::getUnixDaysCount(1972, 1, 1));
    ASSERT_EQ(14610, gfb::stdgo::time::Time::getUnixDaysCount(2010, 1, 1));
}

TEST(time_Time_Unix, positive) {
    ASSERT_EQ(DATE_0, gfb::stdgo::time::Time::Date(2010, 1, 1, 0, 0, 0, 0, nullptr).Unix());
    ASSERT_EQ(DATE_1, gfb::stdgo::time::Time::Date(2010, 12, 23, 10, 45, 0, 0, nullptr).Unix());
}