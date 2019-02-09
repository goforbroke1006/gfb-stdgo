//
// Created by goforbroke on 07.02.19.
//

#ifndef PROJECT_IO_H
#define PROJECT_IO_H

#include <string>
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

#endif //PROJECT_IO_H
