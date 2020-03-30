#ifndef UNTITLED_MYCLASS_H
#define UNTITLED_MYCLASS_H

#include <memory>

class myClass {

public:

    /*
    * Запрашивается блок памяти, размер которого указывается в параметре (в байтах)
    * Возвращается указатель на выделенный блок, либо кидается исключение std::bad_alloc
    * Если исключение кидает конструктор, то память, выделенная под объект — освобождается.
    */
    void* operator new(size_t size);

    /*
   * Принимает указатель на ранее выделенную память и возвращает ее в кучу.
   */
    void operator delete(void *ptr);

    /*
    * Вариант для массива.
    * Запрашивается блок памяти, размер которого указывается в параметре (в байтах)
    * Возвращается указатель на выделенный блок, либо кидается исключение std::bad_alloc
    * Если исключение кидает конструктор, то память, выделенная под объект — освобождается.
    */
    void* operator new[](size_t size);

    /*
    * Вариант для массива.
    * Принимает указатель на ранее выделенную память и возвращает ее в кучу.
    */
    void operator delete[](void *ptr);

    /*
    * Placement new
    * (Можно вызвать new на уже выделенной памяти)
    * p - указатель на некий статический буфер.
    */
    void* operator new(size_t size, void *ptr);

    /*
    * Placement new
    * Вариант для массива.
    * (Можно вызвать new на уже выделенной памяти)
    * p - указатель на некий статический буфер.
    */
    void* operator new[](std::size_t size, void* ptr);

    /*
    * Оператор new, не бросающий исключение
    * Возвращает nullptr в случае нехватки памяти
    * Параметр std::nothrow имеет тип std::nothrow_t.
    */
    void* operator new(size_t size, const std::nothrow_t &nt) noexcept;

    /*
    * Оператор new, не бросающий исключение
    * Возвращает nullptr в случае нехватки памяти
    * Параметр std::nothrow имеет тип std::nothrow_t.
    */
    void* operator new[](std::size_t size, const std::nothrow_t& nth) noexcept;

    /*
    * Создание собственной формы оператора new.
    */
    void* operator new(size_t size, const std::string &str);

};

#endif //UNTITLED_MYCLASS_H
