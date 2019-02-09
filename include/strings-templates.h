//
// Created by goforbroke on 08.02.19.
//

#ifndef PROJECT_STRINGS_TEMPLATES_H
#define PROJECT_STRINGS_TEMPLATES_H

#include <list>

namespace gfb {
    namespace stdgo {
        namespace strings {

            template<typename E>
            std::string Join(const std::list<E> &a, const std::string &sep) {
                if (a.empty())
                    return "";
                std::ostringstream imploded;
                std::copy(a.begin(), a.end(), std::ostream_iterator<E>(imploded, sep.c_str()));
                std::string res = imploded.str();
                res = res.substr(0, res.length() - sep.length());
                return res;
            }

            template<typename E>
            std::string Join(const std::vector<E> &a, const std::string &sep) {
                if (a.empty())
                    return "";
                std::ostringstream imploded;
                std::copy(a.begin(), a.end(), std::ostream_iterator<E>(imploded, sep.c_str()));
                std::string res = imploded.str();
                res = res.substr(0, res.length() - sep.length());
                return res;
            }

        }
    }
}

#endif //PROJECT_STRINGS_TEMPLATES_H
