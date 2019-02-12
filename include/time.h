//
// Created by goforbroke on 06.02.19.
//

#pragma once

#ifndef GFB_STDGO_TIME_H
#define GFB_STDGO_TIME_H

#include <string>
#include <ctime>

#ifdef _WIN32
#include "time_win32.h"
#endif

#include "types.h"
#include "strings.h"

namespace gfb {
    namespace stdgo {
        namespace time {

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
                        const int &nsec, void *location
                );

                static Time Now();

                static Time Parse(const std::string &layout, const std::string &value);

                static Time ParseInLocation(const std::string &layout, const std::string &value, void *loc);

                static Time Unix(const int64 &sec, const int64 &nsec);

            private:
                time_t holder;

                explicit Time(time_t t);

                Time Add(const Duration &d) const;

                Time AddDate(int years, int months, int days) const;

                bool After(const Time &u) const;
            };

        }
    }
}

#endif //GFB_STDGO_TIME_H
