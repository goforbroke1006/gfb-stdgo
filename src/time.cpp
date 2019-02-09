//
// Created by goforbroke on 06.02.19.
//

#include "../include/time.h"


//const char *gfb::stdgo::time::RFC3339 = "2006-01-02T15:04:05Z07:00";

unsigned long long gfb::stdgo::time::Now() {
    return 0;
}

time_t gfb::stdgo::time::Parse(const std::string &layout, const std::string &value) {

    std::string tmpLayout = layout;

    tmpLayout = gfb::stdgo::strings::Replace(tmpLayout, "2006", "%Y", -1);
    tmpLayout = gfb::stdgo::strings::Replace(tmpLayout, "01", "%m", -1);
    tmpLayout = gfb::stdgo::strings::Replace(tmpLayout, "02", "%d", -1);

    tmpLayout = gfb::stdgo::strings::Replace(tmpLayout, "15", "%H", -1);
    tmpLayout = gfb::stdgo::strings::Replace(tmpLayout, "04", "%M", -1);
    tmpLayout = gfb::stdgo::strings::Replace(tmpLayout, "05", "%S", -1);

    // TODO: add timezone support

    struct tm tm{};
    strptime(value.c_str(), tmpLayout.c_str(), &tm);
    return mktime(&tm);
}
