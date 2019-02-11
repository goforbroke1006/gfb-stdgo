//
// Created by goforbroke on 06.02.19.
//

#include "../include/time.h"


gfb::stdgo::time::Duration
gfb::stdgo::time::Duration::ParseDuration(const std::string &s) {
    return gfb::stdgo::time::Duration(); // TODO: implement me
}

gfb::stdgo::time::Duration
gfb::stdgo::time::Duration::Since(const gfb::stdgo::time::Time &t) {
    return gfb::stdgo::time::Duration(); // TODO: implement me
}

gfb::stdgo::time::Duration
gfb::stdgo::time::Duration::Until(const gfb::stdgo::time::Time &t) {
    return gfb::stdgo::time::Duration(); // TODO: implement me
}


gfb::stdgo::time::Time
gfb::stdgo::time::Time::Date(
        const int &year, const int &month, const int &day,
        const int &hour, const int &min, const int &sec,
        const int &nsec, void *location
) {
    return gfb::stdgo::time::Time(); // TODO: implement me
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::Now() {
    return gfb::stdgo::time::Time();
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::Parse(const std::string &layout, const std::string &value) {
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

//    return {mktime(&tm)};
    return gfb::stdgo::time::Time(
            mktime(&tm)
    );
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::ParseInLocation(const std::string &layout, const std::string &value, void *loc) {
    return gfb::stdgo::time::Time(0); // TODO: implement me
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::Unix(const int64 &sec, const int64 &nsec) {
    return gfb::stdgo::time::Time(0); // TODO: implement me
}

gfb::stdgo::time::Time::Time(time_t t) {
    // TODO: implement me
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::Add(const gfb::stdgo::time::Duration &d) const {
    return gfb::stdgo::time::Time(0); // TODO: implement me
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::AddDate(int years, int months, int days) const {
    return gfb::stdgo::time::Time(0); // TODO: implement me
}

bool
gfb::stdgo::time::Time::After(const gfb::stdgo::time::Time &u) const {
    return this->holder > u.holder;
}


//time_t gfb::stdgo::time::Now() {
//    time_t now = std::time(0);
//    return now;
//}
//
//time_t gfb::stdgo::time::Parse(const std::string &layout, const std::string &value) {
//
//
//}

