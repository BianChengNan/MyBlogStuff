#pragma once

#ifdef DLL_EXPORT_INTERFACE
#define DLL_EXPORT_INTERFACE __declspec(dllexport)
#else
#define DLL_EXPORT_INTERFACE __declspec(dllimport)
#endif

class InterfaceBase
{
public:
    virtual ~InterfaceBase() {}
};

class Interface1 : public InterfaceBase
{
public:
    DLL_EXPORT_INTERFACE virtual void Test1(int);
    DLL_EXPORT_INTERFACE virtual void Test3(int);
    DLL_EXPORT_INTERFACE virtual void Test2(int);
    DLL_EXPORT_INTERFACE virtual void Test4(int);
};

DLL_EXPORT_INTERFACE InterfaceBase* GetInterface();
