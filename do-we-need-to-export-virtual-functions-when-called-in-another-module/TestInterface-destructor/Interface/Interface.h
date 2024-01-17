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
    ~InterfaceBase() {}
};

class Interface1 : public InterfaceBase
{
public:
    DLL_EXPORT_INTERFACE Interface1();
    ~Interface1();
    virtual void Test1(int);
    virtual void Test2(int);
    void Test3(int);
};

DLL_EXPORT_INTERFACE InterfaceBase* GetInterface();
