#include "myClass.h"

void* myClass::operator new(size_t size) {
    return std::malloc(size);
}

void myClass::operator delete(void *ptr) {
    std::free(ptr);
}

void* myClass::operator new[](size_t size) {
    return nullptr;
}

void myClass::operator delete[](void *ptr) {

}

void* myClass::operator new(size_t size, void *ptr) {
    return ptr;
}

void *myClass::operator new[](std::size_t size, void *ptr) {
    return nullptr;
}

void* myClass::operator new(size_t size, const std::nothrow_t &nt) noexcept {
    return nullptr;
}

void *myClass::operator new[](std::size_t size, const std::nothrow_t &nth) noexcept {
    return nullptr;
}

void* myClass::operator new(size_t size, const std::string &str) {
    return nullptr;
}



