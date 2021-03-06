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
    ASSERT_TRUE(
            gfb::stdgo::strings::Replace("hello-hell-h-world-wor", "ell", "++++", -1) == "h++++o-h++++-h-world-wor");
    ASSERT_TRUE(gfb::stdgo::strings::Replace("hello", "", "", -1) == "hello");
}

TEST(strings_Split, positive) {
    ASSERT_TRUE(gfb::stdgo::strings::Split("a b c d", " ").size() == 4);
    ASSERT_TRUE(gfb::stdgo::strings::Split("hello#hello#", "#").size() == 3);
}

TEST(strings_Trim, positive) {
    ASSERT_TRUE(gfb::stdgo::strings::Trim("", "") == "");
    ASSERT_TRUE(gfb::stdgo::strings::Trim("  hello  ", " ") == "hello");
    ASSERT_TRUE(gfb::stdgo::strings::Trim("###hello___", "#_") == "hello");
    ASSERT_TRUE(gfb::stdgo::strings::Trim("wildfowl", "") == "wildfowl");
}
