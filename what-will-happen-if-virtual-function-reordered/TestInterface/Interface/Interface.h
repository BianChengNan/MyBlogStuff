#pragma once

#ifdef DLL_EXPORT_INTERFACE
#define DLL_EXPORT_INTERFACE __declspec(dllexport)
#else
#define DLL_EXPORT_INTERFACE __declspec(dllimport)
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
    virtual void Test1(int);
    virtual void Test2(int);
    virtual void Test3(int);
};

DLL_EXPORT_INTERFACE InterfaceBase* GetInterface();
