#ifndef UNTITLED_MYALLOCATOR_H
#define UNTITLED_MYALLOCATOR_H

#include <new>
#include <stdexcept>

template <class T>
class myAllocator {

public:

    myAllocator(std::size_t n) noexcept : _size(n) {};

    T* allocate(std::size_t n) const {
        if (n > _size) {
            throw std::bad_alloc();
        }
        else {
           return new T[n];
        }
    }

    void deallocate(T* p, std::size_t n) const noexcept {
        delete[] p;
    }

    template< typename... Args >
    void construct(T* p, const Args&... args) const {
        new(p) T(args...);
    }

    void destroy(T* p) const {
        p->~T();
    }

    T max_size() const noexcept {
        return sizeof(T);
    }

private:

    size_t _size;
};

template <class T,class U>
bool operator==(const myAllocator <T>&, const myAllocator <U>&) { return true; }

template <class T,class U>
bool operator!=(const myAllocator <T>&, const myAllocator <U>&) { return false; }

#endif //UNTITLED_MYALLOCATOR_H
