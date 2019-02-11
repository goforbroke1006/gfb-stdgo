//
// Created by goforbroke on 06.02.19.
//

#pragma once

#ifndef GFB_STDGO_UTF8_H
#define GFB_STDGO_UTF8_H

#include <string>
#include <cstdio>

namespace gfb {
    namespace stdgo {
        namespace utf8 {

            size_t RuneCountInString(const std::string &s);

        }
    }
}

#endif //GFB_STDGO_UTF8_H
