// testDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"
#include "process.h"
#include "windows.h"

void OutputCurrentThreadId()
{
	TCHAR szBuffer[1024];
	swprintf_s(szBuffer, L"thread [0x%x], running & exiting...\n", GetCurrentThreadId());
	OutputDebugString(szBuffer);
	return;
}

unsigned __stdcall testProc(void *)
{
	OutputCurrentThreadId();
	return 0;
}

HANDLE GenerateThread()
{
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, &testProc, NULL, 0, NULL);
	return hThread;
}
