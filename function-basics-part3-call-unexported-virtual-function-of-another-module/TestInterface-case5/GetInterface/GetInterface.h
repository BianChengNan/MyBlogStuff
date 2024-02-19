#pragma once
#include "../Interface/Interface.h"

#ifndef DLL_GETINTERFACE_EXPORT
#define DLL_EXPORT_GET __declspec(dllimport)
#else
#define DLL_EXPORT_GET __declspec(dllexport)
#endif

DLL_EXPORT_GET InterfaceBase* GetInterface();
DLL_EXPORT_GET InterfaceBase* GetInterface1();
DLL_EXPORT_GET void FreeInterface(InterfaceBase*);
