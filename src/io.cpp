//
// Created by goforbroke on 07.02.19.
//

#include "../include/io.h"

std::string gfb::stdgo::io::ioutil::ReadAll(const gfb::stdgo::io::Reader &r) {
    std::string res;
    r.Read(res);
    return res;
}

std::string gfb::stdgo::io::ioutil::ReadFile(const std::string &filename) {
    std::stringstream ss;
    std::string line;
    std::ifstream f(filename.c_str());
    if (!f.is_open()) {
        throw std::runtime_error("can't open file");
    }
    while (std::getline(f, line)) {
        ss << line << std::endl;
    }
    f.close();

    return ss.str();
}
