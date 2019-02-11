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

namespace gfb {
    namespace stdgo {
        namespace io {

            namespace ioutil {
                std::string ReadFile(const std::string &filename);
            }

        }
    }
}

#endif //GFB_STDGO_IO_H
