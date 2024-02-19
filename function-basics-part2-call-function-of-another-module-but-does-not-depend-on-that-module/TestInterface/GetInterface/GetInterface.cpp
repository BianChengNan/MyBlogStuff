#include <iostream>

#define DLL_GETINTERFACE_EXPORT

#include "GetInterface.h"

InterfaceBase* GetInterface()
{
    return new Interface1();
}

void FreeInterface(InterfaceBase* if1)
{
    delete if1;
}