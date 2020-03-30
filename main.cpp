#include "myClass.h"
#include "myAllocator.h"

int main () {

    myClass* a = new myClass;
    delete a;

    myClass* e = new myClass[10];
    delete[] e;

    char* ptrFirst = new char [sizeof(myClass)];
    myClass* b = new(ptrFirst) myClass;
    b->~myClass();
    delete[] ptrFirst;

    char* ptrSecond = new char [sizeof(myClass) * 10];
    myClass* f = new(ptrSecond) myClass[10];
    f->~myClass();
    delete[] ptrSecond;

    myClass* c = new(std::nothrow) myClass;
    delete c;

    myClass* j = new(std::nothrow) myClass[10];
    delete[] j;

    myClass* d = new("Hello!") myClass;
    delete d;

    myAllocator<int> allocator(8);
    int* alloc = allocator.allocate(8);
    int* array = new int[8];
    allocator.construct(array, 0);
    allocator.destroy(array);
    allocator.deallocate(array, 8);

    return 0;
}
