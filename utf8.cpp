//
// Created by goforbroke on 06.02.19.
//

#include "utf8.h"

size_t gfb::stdgo::utf8::RuneCountInString(const std::string &s) {
    std::size_t len = 0;
    std::string::const_iterator begin = s.begin(), end = s.end();
    while (begin != end) {
        len += (*begin++ & 0xc0) != 0x80;
    }
    return len;
}
