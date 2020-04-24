#include "exampleClass.h"

int main(){
    ExampleClass *test1 = new ExampleClass;
    delete test1;
    ExampleClass *test2 = new ExampleClass[10];
    delete[](test2);

    return 0;
}
