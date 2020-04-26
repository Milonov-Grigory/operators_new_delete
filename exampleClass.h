
#pragma once
#include <cstddef>
#include <new>
#include "PoolAllocator.h"


// Linked list of integers

class ExampleClass
{

public:
    char someData[32];
    static PoolAllocator allocator;
    void* operator new(std::size_t size) throw (std::bad_alloc);
    void* operator new(std::size_t size, const std::nothrow_t&) throw ();
    void* operator new[](std::size_t size) throw (std::bad_alloc);
    void* operator new[](std::size_t size, const std::nothrow_t&) throw();
    void operator delete(void* ptr) throw();
    void operator delete(void* ptr, const std::nothrow_t&) throw();
    void operator delete[](void* ptr) throw();
    void operator delete[](void* ptr, const std::nothrow_t&) throw();
	ExampleClass() = default;
	~ExampleClass() = default;

};
PoolAllocator ExampleClass::allocator{12};
