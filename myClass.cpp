#include "myClass.h"
#include <iostream>

void* myClass::operator new(size_t size) {
    void* ptr = std::malloc(size);
    if (ptr) {
        return ptr;
    }
    else {
        throw std::bad_alloc();
    }
}


void myClass::operator delete(void *ptr) {
    std::free(ptr);
}


void* myClass::operator new[](size_t size) {
    void* ptr = std::malloc(size);
    if (ptr) {
        return ptr;
    }
    else {
        throw std::bad_alloc();
    }
}


void myClass::operator delete[](void *ptr) {
    std::free(ptr);
}


void* myClass::operator new(size_t size, void *ptr) {
    return ptr;
}


void* myClass::operator new[](std::size_t size, void *ptr) {
    return ptr;
}


void* myClass::operator new(size_t size, const std::nothrow_t &nt) noexcept {
    return std::malloc(size);
}


void *myClass::operator new[](std::size_t size, const std::nothrow_t &nth) noexcept {
    return std::malloc(size);
}


void* myClass::operator new(size_t size, const std::string &str) {
    std::cout << str << std::endl;  // Допустим, это то, для чего нам нужно передавать строку в new
    return std::malloc(size);
}



