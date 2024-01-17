#include <iostream>

#define DLL_EXPORT__INTERFACE

#include "Interface.h"

Interface1::Interface1()
{
}

Interface1::~Interface1()
{
}

void Interface1::Test1(int a)
{
    std::cout << __FUNCTION__ << " : " << a << std::endl;
}

void Interface1::Test2(int a)
{
    std::cout << __FUNCTION__ << " : " << a << std::endl;
}

void Interface1::Test3(int a)
{
    std::cout << __FUNCTION__ << " : " << a << std::endl;
}

InterfaceBase* GetInterface()
{
    return new Interface1();
}