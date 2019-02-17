//
// Created by goforbroke on 15.02.19.
//

#include <gtest/gtest.h>

#include "../../include/time.h"


TEST(time_Time_Parse, positive) {
//    ASSERT_EQ(0, gfb::stdgo::time::Time::Parse("2006-01-02 15:04:05 %z", "1970-01-01 00:00:00 +0000").Unix());
    ASSERT_EQ(0, gfb::stdgo::time::Time::Parse("%Y-%m-%d %H:%M:%S %z", "1970-01-01 00:00:00 +0000").Unix());
}


TEST(time_Time_Unix, positive) {

    auto locUTC = gfb::stdgo::time::Location::LoadLocation("UTC");
    auto locMSK = gfb::stdgo::time::Location::LoadLocation("MSK");

    int64 date1 = gfb::stdgo::time::Time::Date(2010, 1, 1, 0, 0, 0, 0, locUTC).Unix();
    int64 date2 = gfb::stdgo::time::Time::Date(2010, 1, 1, 3, 0, 0, 0, locMSK).UTC().Unix();
    ASSERT_EQ(date1, date2);

    const int THREE_HOURS_BEFORE_EPOCH_ON_UTC = -10800; // Wed, 31 Dec 1969 21:00:00 GMT
    ASSERT_EQ(
            THREE_HOURS_BEFORE_EPOCH_ON_UTC,
            gfb::stdgo::time::Time::Date(1970, 1, 1, 0, 0, 0, 0, locMSK).UTC().Unix()
    );

    const int64 DATE_0 = 1262304000; // 1th Jan 2010 00:00:00
    ASSERT_EQ(DATE_0, gfb::stdgo::time::Time::Date(2010, 1, 1, 0, 0, 0, 0, locUTC).Unix());

    const int64 DATE_1 = 1293101100; // 23th Dec 2010 10:45:00
    ASSERT_EQ(DATE_1, gfb::stdgo::time::Time::Date(2010, 12, 23, 10, 45, 0, 0, locUTC).Unix());
}