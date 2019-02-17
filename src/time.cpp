#include <memory>

//
// Created by goforbroke on 06.02.19.
//

#include "../include/time.h"

std::string gfb::stdgo::time::zeroPadding(int val, unsigned int exp) {
    std::stringstream ss;
    if (exp == 2) {
        if (val < 10)
            ss << "0" << val;
        else ss << val;
    }
    return ss.str(); // TODO: workaround
}


std::shared_ptr<gfb::stdgo::time::Location>
gfb::stdgo::time::Location::LoadLocation(const std::string &name) {
    if (name.empty() || name == "UTC")
        return std::make_shared<gfb::stdgo::time::Location>(0);
    if (name.empty() || name == "MSK")
        return std::make_shared<gfb::stdgo::time::Location>(3, 0);

    throw std::runtime_error("is not implemented");
}

const std::string
gfb::stdgo::time::Location::String() const {
    return std::__cxx11::string();
}

int
gfb::stdgo::time::Location::getTimeShift() const {
    return timeShift;
}


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
        const int &nsec, std::shared_ptr<Location> location
) {
    std::stringstream ss;
    ss << year << "-" << zeroPadding(month, 2) << "-" << zeroPadding(day, 2)
       << " "
       << zeroPadding(hour, 2) << ":" << zeroPadding(min, 2) << ":" << zeroPadding(sec, 2);
    Time dt = gfb::stdgo::time::Time::Parse("2006-01-02 15:04:05", ss.str());
    dt.location = new Location(location->getTimeShift());
    return dt; // TODO: implement me
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::Now() {
    return gfb::stdgo::time::Time(0);
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

    std::istringstream in{value};
    date::sys_seconds tp;
    in >> date::parse(tmpLayout.c_str(), tp);
    return Time(tp.time_since_epoch().count());
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::ParseInLocation(
        const std::string &layout,
        const std::string &value,
        const std::shared_ptr<Location> &loc
) {
    return gfb::stdgo::time::Time(0); // TODO: implement me
}

gfb::stdgo::time::Time
gfb::stdgo::time::Time::Unix(const int64 &sec, const int64 &nsec) {
    return gfb::stdgo::time::Time(0); // TODO: implement me
}

gfb::stdgo::time::Time::Time(int64 t)
        : holder(t),
          location(nullptr) {
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

gfb::stdgo::time::Time
gfb::stdgo::time::Time::UTC() const {
    return gfb::stdgo::time::Time(
            this->holder - (
                    nullptr != this->location ? this->location->getTimeShift()
                                              : 0
            )
    );
}

int64
gfb::stdgo::time::Time::Unix() const {
    return this->holder;
}

gfb::stdgo::time::Time::~Time() {
    if (nullptr != this->location)
        delete this->location;
}
