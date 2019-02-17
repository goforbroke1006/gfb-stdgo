//
// Created by goforbroke on 06.02.19.
//

#pragma once

#ifndef GFB_STDGO_TIME_H
#define GFB_STDGO_TIME_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

#include "../vendor/date.h"

#ifdef _WIN32
#include "time_win32.h"
#endif

#include "types.h"
#include "strings.h"

namespace gfb {
    namespace stdgo {
        namespace time {

            std::string zeroPadding(int val, unsigned int exp);

            class Location {
            public:
                explicit Location(int ts) : timeShift(ts) {}

                explicit Location(int hour, int minute) {
                    this->timeShift = hour * 60 * 60 + minute * 60;
                }

                static std::shared_ptr<Location> LoadLocation(const std::string &name);

                const std::string String() const;

                int getTimeShift() const;

            private:
                int timeShift;
            };

            const std::string RFC3339 = "2006-01-02T15:04:05Z07:00";

            class Time;

            class Duration {
            public:
                static Duration ParseDuration(const std::string &s);

                static Duration Since(const Time &t);

                static Duration Until(const Time &t);
            };

            class Time {
            public:
                static Time Date(
                        const int &year, const int &month, const int &day,
                        const int &hour, const int &min, const int &sec,
                        const int &nsec, std::shared_ptr<Location> location
                );

                static Time Now();

                static Time Parse(const std::string &layout, const std::string &value);

                static Time ParseInLocation(
                        const std::string &layout,
                        const std::string &value,
                        const std::shared_ptr<Location> &loc
                );

                static Time Unix(const int64 &sec, const int64 &nsec);

                Time Add(const Duration &d) const;

                Time AddDate(int years, int months, int days) const;

                bool After(const Time &u) const;

                bool Equal(const Time &u) const;

                std::string Format(const std::string &layout) const;

                Time UTC() const;

                int64 Unix() const;

                virtual ~Time();

            private:
                int64 holder;
                Location *location;

                explicit Time(int64 t);

            };

        }
    }
}

#endif //GFB_STDGO_TIME_H
