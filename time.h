//
// Created by goforbroke on 06.02.19.
//

#pragma once

#ifndef PROJECT_TIME_H
#define PROJECT_TIME_H

#include <string>
#include <ctime>

#include "strings.h"

namespace gfb {
    namespace stdgo {
        namespace time {

            const std::string RFC3339 = "2006-01-02T15:04:05Z07:00";
//            const char *RFC3339;

//            class Time {
//            public:
//                explicit Time() {}
//                Time operator+(int interval)
//            };

            unsigned long long Now();

            time_t Parse(const std::string &layout, const std::string &value);

        }
    }
}

#endif //PROJECT_TIME_H
