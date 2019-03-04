//
// Created by goforbroke on 04.03.19.
//

#include "../../include/net/http.h"

gfb::stdgo::net::http::Cookie::Cookie(const std::string &name, const std::string &val)
        : name(name),
          val(val) {
    //
}

const std::string &
gfb::stdgo::net::http::Cookie::getName() const {
    return name;
}

void
gfb::stdgo::net::http::Cookie::setName(const std::string &name) {
    Cookie::name = name;
}

const std::string &
gfb::stdgo::net::http::Cookie::getVal() const {
    return val;
}

void
gfb::stdgo::net::http::Cookie::setVal(const std::string &val) {
    Cookie::val = val;
}

gfb::stdgo::net::http::Response::Response(const std::string &content) {
    this->content = content;
}

const std::string &
gfb::stdgo::net::http::Response::getContent() const {
    return content;
}

void
gfb::stdgo::net::http::Response::setContent(const std::string &content) {
    Response::content = content;
}

gfb::stdgo::net::http::Request
gfb::stdgo::net::http::Request::NewRequest(
        const std::string &method,
        const std::string &url,
        const gfb::stdgo::io::Reader &body
) {
    return {};
}

void
gfb::stdgo::net::http::Request::AddCookie(const gfb::stdgo::net::http::Cookie &c) {
    this->__cookies.push_back(c);
}

std::shared_ptr<gfb::stdgo::net::http::Cookie>
gfb::stdgo::net::http::Request::Cookie(const std::string &name) const {
    for (const auto &c : this->__cookies) {
        if (c.getName() == name) {
//            gfb::stdgo::net::http::Cookie *cookie = new gfb::stdgo::net::http::Cookie();
            return std::make_shared<gfb::stdgo::net::http::Cookie>(c.getName(), c.getVal());
        }
    }
    return nullptr;
}

std::vector<gfb::stdgo::net::http::Cookie>
gfb::stdgo::net::http::Request::Cookies() const {
    return std::vector<gfb::stdgo::net::http::Cookie>();
}

std::string
gfb::stdgo::net::http::Request::PostFormValue(const std::string &key) const {
    return "";
}

std::string
gfb::stdgo::net::http::Request::Referer() const {
    return "";
}

void
gfb::stdgo::net::http::Request::SetBasicAuth(const std::string &username, const std::string &password) {

}

std::string
gfb::stdgo::net::http::Request::UserAgent() const {
    return "";
}

size_t __write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Get(const std::string &url) {
    CURL *c = curl_easy_init();
    if (c == nullptr) {
        throw std::runtime_error("CURL init error");
    }

    struct curl_slist *chunk = nullptr;
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
        throw std::runtime_error(curl_easy_strerror(res));
    }
    gfb::stdgo::net::http::Response resp(respData);
    return resp;
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Post(const std::string &url, const std::string &contentType, const std::string &body) {
    return gfb::stdgo::net::http::Response("");
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Client::Do(const gfb::stdgo::net::http::Request &req) const {
    return gfb::stdgo::net::http::Response("");
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Client::Get(const std::string &url) const {
    return gfb::stdgo::net::http::Response("");
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Client::Head(const std::string &url) const {
    return gfb::stdgo::net::http::Response("");
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Client::Post(
        const std::string &url,
        const std::string &contentType,
        const gfb::stdgo::io::Reader &body
) const {
    return gfb::stdgo::net::http::Response("");
}

gfb::stdgo::net::http::Response
gfb::stdgo::net::http::Client::PostForm(
        const std::string &url,
        const std::map<std::string, std::string> &data
) const {
    return gfb::stdgo::net::http::Response("");
}

gfb::stdgo::net::http::Server::Server(
        const std::string &addr,
        void *handler,
        const ssize_t &readTimeout,
        const ssize_t &writeTimeout
) {
    //
}
