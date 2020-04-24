#ifndef LLIST_H
#define LLIST_H

#include <cstddef>
#include <new>

// Linked list of integers

class ExampleClass
{

public:

    void* operator new(std::size_t size) throw (std::bad_alloc);
    void* operator new(std::size_t size, const std::nothrow_t&) throw ();
    void* operator new[](std::size_t size) throw (std::bad_alloc);
    void* operator new[](std::size_t size, const std::nothrow_t&) throw( );
    void operator delete(void* ptr) throw( );
    void operator delete(void* ptr, const std::nothrow_t&) throw( );
    void operator delete[](void* ptr) throw( );
    void operator delete[](void* ptr, const std::nothrow_t&) throw( );
	ExampleClass() = default;
	~ExampleClass() = default;

};

#endif //LLIST_H
