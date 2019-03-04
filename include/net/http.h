#ifndef GFB_STDGO_NET_HTTP_H
#define GFB_STDGO_NET_HTTP_H

#include <string>
#include <map>
#include <map>

#include <curl/curl.h>
#include <memory>

#include "../io.h"

namespace gfb {
    namespace stdgo {
        namespace net {
            namespace http {
                class Transport {
                };

                class Cookie {
                public:
                    explicit Cookie(const std::string &name, const std::string &val);

                    const std::string &getName() const;

                    void setName(const std::string &name);

                    const std::string &getVal() const;

                    void setVal(const std::string &val);

                private:
                    std::string name;
                    std::string val;
                };

                class Response {
                public:
                    explicit Response(const std::string &content);

                    const std::string &getContent() const;

                    void setContent(const std::string &content);

                private:
                    std::string content;
                };

                class Request {
                public:
                    static Request NewRequest(const std::string &method, const std::string &url,
                                              const gfb::stdgo::io::Reader &body);

                    void AddCookie(const Cookie &c);

                    std::shared_ptr<gfb::stdgo::net::http::Cookie> Cookie(const std::string &name) const;

                    std::vector<gfb::stdgo::net::http::Cookie> Cookies() const;

                    std::string PostFormValue(const std::string &key) const;

                    std::string Referer() const;

                    void SetBasicAuth(const std::string &username, const std::string &password);

                    std::string UserAgent() const;

                private:
                    std::string method;
                    std::string url;

                    std::vector<gfb::stdgo::net::http::Cookie> __cookies;
                };

                class Client {
                public:

                    Response Do(const Request &req) const;

                    Response Get(const std::string &url) const;

                    Response Head(const std::string &url) const;

                    Response Post(const std::string &url, const std::string &contentType,
                                  const gfb::stdgo::io::Reader &body) const;

                    Response PostForm(const std::string &url,
                                      const std::map<std::string, std::string> &data) const;
                };

                class Server {
                public:
                    Server(const std::string &addr, void *handler,
                           const ssize_t &readTimeout, const ssize_t &writeTimeout);
                };

                Response Get(const std::string &url);

                Response Post(const std::string &url, const std::string &contentType, const std::string &body);

                Response PostForm(const std::string &url, const std::map<std::string, std::string> &data);
            }
        }
    }
}

#endif //GFB_STDGO_NET_HTTP_H
