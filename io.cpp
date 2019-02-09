//
// Created by goforbroke on 07.02.19.
//

#include "io.h"

std::string gfb::stdgo::io::ioutil::ReadFile(const std::string &filename) {
    std::stringstream ss;
    std::string line;
    std::ifstream f(filename);
    if (!f.is_open()) {
        throw std::runtime_error("can't open file");
    }
    while (std::getline(f, line)) {
        ss << line << std::endl;
    }
    f.close();

    return ss.str();
}
