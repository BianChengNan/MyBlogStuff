#include <iostream>

#define DLL_INTERFACE_EXPORT

#include "Interface.h"

Interface1::Interface1()
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
void Interface1::Test3(const std::string& a)
{
    std::cout << __FUNCTION__ << " : " << a << std::endl;
}
void Interface1::Test4(int a)
{
    std::cout << __FUNCTION__ << " : " << a << std::endl;
}