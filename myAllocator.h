#ifndef UNTITLED_MYALLOCATOR_H
#define UNTITLED_MYALLOCATOR_H

#include <new>
#include <stdexcept>

template <class T>
class myAllocator {

public:

    explicit myAllocator(std::size_t n) : _size(n) {};

    T* allocate(std::size_t n) const {
        if (n > _size) {
            throw std::invalid_argument("Wrong value");
        }
        else {
           return new T[n];
        }
    }

    void deallocate(T* p, std::size_t n) const {
        delete[] p;
    }

    template< typename... Args >
    void construct(T* p, const Args&... args) const {
        new(p) T(args...);
    }

    void destroy(T* p) const {
        p->~T();
    }

private:

    size_t _size;
};

#endif //UNTITLED_MYALLOCATOR_H
