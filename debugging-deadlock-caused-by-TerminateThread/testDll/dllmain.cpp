// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "windows.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString(L"====> DLL_PROCESS_ATTACH called.\n");
		break;
	case DLL_THREAD_ATTACH:
		OutputDebugString(L"----> DLL_THREAD_ATTACH called.\n");
		break;
	case DLL_THREAD_DETACH:
		OutputDebugString(L"<---- DLL_THREAD_DETACH called.\n");
		// with LdrpLoaderLock held! sleep 5 seconds. 
		Sleep(5000);
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugString(L"<==== DLL_PROCESS_DETACH called.\n");
		break;
	}
	return TRUE;
}

