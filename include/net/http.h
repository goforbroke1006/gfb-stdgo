#ifndef GFB_STDGO_NET_HTTP_H
#define GFB_STDGO_NET_HTTP_H

#include <string>
#include <map>
#include <map>
#include <bits/shared_ptr.h>

#include "curl/curl.h"
#include "../io.h"

namespace gfb {
    namespace stdgo {
        namespace net {
            namespace http {
                class Transport {
                };

                class Cookie {
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

                    Cookie Cookie(const std::string &name) const;

                    std::vector<gfb::stdgo::net::http::Cookie> Cookies() const;

//                    func (r *Request) ParseForm() error
//                    func (r *Request) ParseMultipartForm(maxMemory int64) error
                    std::string PostFormValue(const std::string &key) const;

                    std::string Referer() const;

                    void SetBasicAuth(const std::string &username, const std::string &password);

                    std::string UserAgent() const;

                private:
                    std::string method;
                    std::string url;
                };

                class Client {
                public:

                    Response Do(const Request &req);

                    Response Get(const std::string &url);

                    Response Head(const std::string &url);

                    Response Post(const std::string &url, const std::string &contentType,
                                  const gfb::stdgo::io::Reader &body);

                    Response PostForm(const std::string &url, const std::map<std::string, std::string> data);
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
