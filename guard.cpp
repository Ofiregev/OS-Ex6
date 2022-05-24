#include <thread>
#include <iostream>

pthread_mutex_t locker = PTHREAD_MUTEX_INITIALIZER;

class my_guard {      
  private:             
    pthread_mutex_t *lock;
    public:
    my_guard(pthread_mutex_t* lock) {  
    this->lock = lock;
    pthread_mutex_lock(this->lock);
    }
    ~my_guard() { 
        pthread_mutex_unlock(this->lock);
    } 
};
//The C library function char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimiter delim.
//we won't be able to use this function with this guard because many threads may be calling strtok with different strings.
// and it will only remember the last one and return the wrong result.
