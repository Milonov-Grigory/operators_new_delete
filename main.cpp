#include <iostream>
#include "exampleClass.h"

int main(){
    ExampleClass *test1 = new ExampleClass;
    for(int i = 65; i < 31 + 65; ++i){
        test1->someData[i - 65] = i;
    }
    test1->someData[31] = '\0';
    std::cout << test1->someData << std::endl;
    delete test1;
    ExampleClass *test2 = new ExampleClass[10];
    delete[](test2);

    return 0;
}
