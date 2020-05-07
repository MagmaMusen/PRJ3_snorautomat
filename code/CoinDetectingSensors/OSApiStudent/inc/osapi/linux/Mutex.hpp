#ifndef OSAPI_LINUX_MUTEX_HPP
#define OSAPI_LINUX_MUTEX_HPP

#include <pthread.h>

namespace osapi
{
    class Conditional;              //Forward declaration

    class Mutex
    {
    public:
        Mutex();
        void lock();
        void unlock();
        ~Mutex();
        
    private:
        friend class Conditional;
        pthread_mutex_t mut_;
        
    };
}

#endif