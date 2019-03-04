//
// Created by goforbroke on 04.03.19.
//

#include <iostream>

#include "../../include/net/http.h"

int main() {
    const gfb::stdgo::net::http::Response &response = gfb::stdgo::net::http::Get("http://hello.w0r1d.net/");
    std::cout << response.getContent() << std::endl;
}
