#include <iostream>

#define DLL_GETINTERFACE_EXPORT

#include "GetInterface.h"

InterfaceBase* GetInterface()
{
    return new Interface1;
}

InterfaceBase* GetInterface1()
{
    return ExportInterface();
}

void FreeInterface(InterfaceBase* if1)
{
    delete if1;
}