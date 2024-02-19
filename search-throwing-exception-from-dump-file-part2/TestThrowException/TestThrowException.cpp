#include <iostream>

int main()
{
    int* p1 = (int*)0x10000000;
    int* p2 = (int*)0x10000004;
    auto diff = p2 - p1;
    //std::cout << typeid(diff)->name;

    throw std::bad_alloc();
    return 0;
}
