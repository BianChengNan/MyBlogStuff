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
    DLL_EXPORT virtual void Test1(int);
    DLL_EXPORT virtual void Test2(int);
    DLL_EXPORT virtual void Test3(const std::string&);
    DLL_EXPORT void Test4(int);
};

