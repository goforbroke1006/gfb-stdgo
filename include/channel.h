//
// Created by goforbroke on 10.02.19.
//

#ifndef GFB_STDGO_CHANNEL_H
#define GFB_STDGO_CHANNEL_H

#include <queue>
#include <condition_variable>

namespace gfb {
    namespace stdgo {

        template<class T>
        class channel;

        template<class T>
        void operator<<(T &val, channel<T> &chan);

        template<class T>
        class channel {
        private:
            size_t capacity;
            std::queue<T> buffer;
            std::mutex buffer_mutex;
            std::condition_variable cv_empty;
            std::condition_variable cv_full;
        public:
            explicit channel(size_t c) : capacity(c) {}

            /**
             * write to channel
             */
            inline void operator<<(const T &obj) {
                std::unique_lock<std::mutex> lock(buffer_mutex);
                cv_full.wait(lock, [this] { return getLength() < getCapacity(); });
                buffer.push(obj);
                cv_empty.notify_one();
            }

            /**
             * read from channel
             */
            inline void operator>>(T &obj) {
                this->copyTo(obj);
            }

            const size_t getLength() const {
                return buffer.size();
            }

            const size_t &getCapacity() const {
                return capacity;
            }

            const bool isFull() const {
                return getLength() == getCapacity();
            }

            const bool isEmpty() const {
                return getLength() == 0;
            }

        private:
            /**
             * read from channel
             */
            void copyTo(T &obj) {
                std::unique_lock<std::mutex> lock(buffer_mutex);
                cv_empty.wait(lock, [this] { return getLength() > 0; });
                obj = buffer.front();
                buffer.pop();
                cv_full.notify_one();
            }

            template<class X>
            friend void operator<<(X &val, channel<X> &chan);
        };

        template<class T>
        void operator<<(T &val, channel<T> &chan) {
            chan.copyTo(val);
        }

    }
}

#endif //GFB_STDGO_CHANNEL_H
