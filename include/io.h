//
// Created by goforbroke on 07.02.19.
//

#ifndef GFB_STDGO_IO_H
#define GFB_STDGO_IO_H

#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>

namespace gfb {
    namespace stdgo {
        namespace io {

            class Reader {
            public:
                virtual void Read(std::string &p) const = 0;

                virtual void Read(std::vector<char> p) const = 0;
            };

            namespace ioutil {
                std::string ReadAll(const Reader &r);

                std::string ReadFile(const std::string &filename);
            }

        }
    }
}

#endif //GFB_STDGO_IO_H
