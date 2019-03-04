#ifndef GFB_STDGO_NET_HTTP_H
#define GFB_STDGO_NET_HTTP_H

#include <string>
#include <map>

namespace gfb {
    namespace stdgo {
        namespace net {
            namespace http {
                class Transport {};
                class Client {};
                class Server {
                public:
                    Server(const std::string &addr, void *handler, 
                        const ssize_t &readTimeout, const ssize_t &writeTimeout);
                };
                
                class Response {
                public:
                    Response(const std::string &content);
                private:
                    std::string content;
                };
                
                Response Get(const std::string &url);
                Response Post(const std::string &url, const std::string &contentType, const std::string &body);
                Response PostForm(const std::string &url, const std::map<std::string, std::string> &data);
            }
        }
    }
}

#endif //GFB_STDGO_NET_HTTP_H
