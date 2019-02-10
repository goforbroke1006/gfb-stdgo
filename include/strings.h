//
// Created by goforbroke on 23.01.19.
//

#pragma once

#ifndef GFB_STDGO_STRINGS_H
#define GFB_STDGO_STRINGS_H

#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

namespace gfb {
    namespace stdgo {
        namespace strings {

            std::vector<std::string> Split(const std::string &s, const std::string &sep);

            std::string Trim(std::string s, const std::string &cutset = "\n\t\r ");

            std::string Repeat(const std::string &s, size_t count);

            std::string Replace(const std::string &s, const std::string &old, const std::string &_new, int n);

        }
    }
}

#endif //GFB_STDGO_STRINGS_H
