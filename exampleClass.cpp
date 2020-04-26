#include "exampleClass.h"
#include "PoolAllocator.h"

void *ExampleClass::operator new(std::size_t size)throw (std::bad_alloc){
    if (size == 0) size = 1;
    if (void* ptr = allocator.allocate(size))
        return ptr;
    throw std::bad_alloc();
}

void *ExampleClass::operator new(std::size_t size, const std::nothrow_t &) noexcept{
    if (size == 0) size = 1;
    if (void* ptr =  allocator.allocate(size))
        return ptr;
    return nullptr;
}

void *ExampleClass::operator new[](std::size_t size) throw (std::bad_alloc){
    return operator new (size);
}

void *ExampleClass::operator new[](std::size_t size, const std::nothrow_t &)  throw ( ){
    return operator new (size, std::nothrow);
}

void ExampleClass::operator delete(void *ptr)throw (){
    if (ptr) allocator.deallocate(ptr, sizeof(ExampleClass));
}

void ExampleClass::operator delete(void *ptr, const std::nothrow_t &) noexcept {
    if (ptr)allocator.deallocate(ptr, sizeof(ExampleClass));
}

void ExampleClass::operator delete[](void *ptr)  noexcept{
    operator delete (ptr);
}

void ExampleClass::operator delete[](void *ptr, const std::nothrow_t &)  noexcept{
    operator delete (ptr, std::nothrow);
}
