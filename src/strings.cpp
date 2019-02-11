//
// Created by goforbroke on 06.02.19.
//

#include "../include/strings.h"

std::vector<std::string> gfb::stdgo::strings::Split(const std::string &s, const std::string &sep) {
    std::vector<std::string> res;

    unsigned long start = 0;
    long next = 0;
    std::string token;
    for (;;) {
        next = s.find(sep, start);
        if (next < 0) {
            token = s.substr(start, s.length() - start);
            res.push_back(token);
            break;
        }

        token = s.substr(start, next - start);

        res.push_back(token);
        start = next + sep.length();
    }

    return res;
}

std::string gfb::stdgo::strings::Trim(std::string s, const std::string &cutset) {
    if (s.empty() || cutset.empty())
        return s;
    for (long i = 0; i < cutset.length(); ++i) {

        const char &ch = cutset.at(i);

        if (s.at(0) == ch) {
            s = s.substr(1);
            i = -1;
            continue;
        }
        if (s.at(s.length() - 1) == ch) {
            s = s.substr(0, s.length() - 1);
            i = -1;
            continue;
        }
    }
    return s;
}

std::string gfb::stdgo::strings::Repeat(const std::string &s, size_t count) {
    std::string res;
    for (size_t i = 0; i < count; ++i) {
        res += s;
    }
    return res;
}

std::string gfb::stdgo::strings::Replace(const std::string &s, const std::string &old, const std::string &_new, int n) {
    std::string res = s;
    if (old.empty())
        return s;
    auto next = static_cast<size_t>(n < 0 ? 0 : n);
    while (true) {
        next = res.find(old, next);
        if (next == std::string::npos)
            break;
        res = res.replace(next, old.length(), _new);
        next += _new.length();
    }
    return res;
}
