//
// Created by goforbroke on 11.02.19.
//

#include <gtest/gtest.h>

#include "../../include/strings.h"

TEST(strings_Repeat, positive) {
    ASSERT_TRUE(gfb::stdgo::strings::Repeat("", 1) == "");
    ASSERT_TRUE(gfb::stdgo::strings::Repeat("", 2) == "");
    ASSERT_TRUE(gfb::stdgo::strings::Repeat("asd", 1) == "asd");
    ASSERT_TRUE(gfb::stdgo::strings::Repeat("zxc", 3) == "zxczxczxc");
}

TEST(strings_Replace, positive) {
    ASSERT_TRUE(gfb::stdgo::strings::Replace("hello-world###789", "hello", "under", -1) == "under-world###789");
//    ASSERT_TRUE(gfb::stdgo::strings::Replace("", "", "", -1) == "");
//    ASSERT_TRUE(gfb::stdgo::strings::Replace("", "", "", -1) == "");
//    ASSERT_TRUE(gfb::stdgo::strings::Replace("", "", "", -1) == "");
}

TEST(strings_Split, positive) {
    ASSERT_TRUE(gfb::stdgo::strings::Split("a b c d", " ").size() == 4);
    ASSERT_TRUE(gfb::stdgo::strings::Split("hello#hello#", "#").size() == 3);
//    ASSERT_TRUE(gfb::stdgo::strings::Split("", "").size() == 0);
//    ASSERT_TRUE(gfb::stdgo::strings::Split("", "").size() == 0);
}

TEST(strings_Trim, positive) {
    ASSERT_TRUE(gfb::stdgo::strings::Trim("  hello  ", " ") == "hello");
//    ASSERT_TRUE(gfb::stdgo::strings::Trim("", "") == "");
//    ASSERT_TRUE(gfb::stdgo::strings::Trim("", "") == "");
//    ASSERT_TRUE(gfb::stdgo::strings::Trim("", "") == "");
}
