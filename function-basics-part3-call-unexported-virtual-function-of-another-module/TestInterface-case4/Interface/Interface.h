#pragma once

#include <string>

#ifndef DLL_INTERFACE_EXPORT
#define DLL_EXPORT __declspec(dllimport)
#else
#define DLL_EXPORT __declspec(dllexport)
#endif

class InterfaceBase
{
public:
    virtual void Test1(int) = 0;
    virtual ~InterfaceBase() {}
};

class Interface1 : public InterfaceBase
{
public:
    Interface1();
    virtual void Test1(int);
    virtual void Test2(int);
    virtual void Test3(const std::string&);
    void Test4(int);
    virtual void Test5() {};
};

DLL_EXPORT InterfaceBase* ExportInterface();
