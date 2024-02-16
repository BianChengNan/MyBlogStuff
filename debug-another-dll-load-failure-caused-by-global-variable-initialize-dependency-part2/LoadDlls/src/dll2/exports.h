#pragma once

#ifdef DLL_EXPORT_DLL2
#define DLL_EXPORT extern "C" __declspec(dllexport)
#else
#define DLL_EXPORT extern "C" __declspec(dllimport)
#endif

DLL_EXPORT int MajorVersion();

DLL_EXPORT void RegisterInitCallback(const char* key, void(*callback)());
DLL_EXPORT void RegisterCallback(const char* key, void(*callback)());

DLL_EXPORT void Init();

