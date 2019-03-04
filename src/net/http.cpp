//
// Created by goforbroke on 04.03.19.
//

#include "../../include/net/http.h"

size_t __write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

gfb::stdgo::net::http::Response::Response(const std::string &content) {
    this->content = content;
}

gfb::stdgo::net::http::Response gfb::stdgo::net::http::Get(const std::string &url) {
    CURL *c = curl_easy_init();
    if (c == nullptr) {
        throw std::runtime_error("CURL init error");
    }

    struct curl_slist *chunk = NULL;
    //chunk = curl_slist_append(chunk, "accept:          text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
    //chunk = curl_slist_append(chunk, "accept-language: ru,en-US;q=0.9,en;q=0.8,uk;q=0.7");
    chunk = curl_slist_append(chunk, "x-compress:      null");
    chunk = curl_slist_append(chunk, "cache-control:   max-age=0");
    //chunk = curl_slist_append(chunk, "user-agent:      Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36");

    curl_easy_setopt(c, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(c, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt(c, CURLOPT_URL, url.c_str());
    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, __write_callback);
    std::string respData;
    curl_easy_setopt(c, CURLOPT_WRITEDATA, &respData);

    CURLcode res = curl_easy_perform(c);
    curl_easy_cleanup(c);

    if (res != CURLE_OK) {
        std::cerr << "CURL (" << res << ") : " << curl_easy_strerror(res) << std::endl;
        throw std::runtime_error(curl_easy_strerror(res));
    }
    gfb::stdgo::net::http::Response resp(respData);
    return resp;
}

