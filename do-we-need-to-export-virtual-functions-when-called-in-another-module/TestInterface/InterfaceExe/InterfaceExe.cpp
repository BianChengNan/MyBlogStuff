#include <iostream>
#include "../Interface/Interface.h"

int main()
{
    InterfaceBase* base = GetInterface();
    Interface1* if1 = dynamic_cast<Interface1*>(base);
    if1->Test1(0);

    // Test3() 不是虚函数，调用的话，需要找到实现
    //if1->Test3(0);

    // 下面的代码会实例化 Interface1，实例化的时候需要找到所有虚函数地址，因为需要写到虚表里
    auto if1_error = new Interface1();

    return 0;
}
