#ifndef UNTITLED_MYALLOCATOR_H
#define UNTITLED_MYALLOCATOR_H
//#include <memory>
#include <cstddef>

//Обертка над вызовами new и delete (дефолтный аллокатор)
template <class T>
class myAllocator {
public:

    T* allocate(size_t n) const {
        (T*)new T [n * sizeof(T)];
    }

    void deallocate(T* p, size_t n) const {
        delete[] p;
    }

    template< typename... Args >
    void construct(T* p, const Args&... args) const {
        return new(p) T(args...);
    }

    void destroy(T* p) const {
        p->~T();
    }
};

#endif //UNTITLED_MYALLOCATOR_H
