// testTerminateThread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "process.h"

typedef HANDLE (*pfnGenerateThread)();

HANDLE RunProcess(const TCHAR* app_name, const TCHAR* cmd)
{
	SHELLEXECUTEINFO shex = {sizeof(SHELLEXECUTEINFO)};
	shex.fMask = SEE_MASK_NOCLOSEPROCESS;
	shex.lpVerb = _T("open");
	shex.lpFile = app_name; 
	shex.lpParameters = cmd; 
	shex.lpDirectory = NULL; 
	shex.nShow = SW_NORMAL;

	if (!::ShellExecuteEx(&shex))
	{
		return INVALID_HANDLE_VALUE;
	}

	return shex.hProcess;
}

int _tmain(int argc, _TCHAR* argv[])
{
	while ( 1 )
	{
		HMODULE hModule = LoadLibrary(_T("testDll.dll"));
		if ( NULL == hModule )
			return 0;

		pfnGenerateThread pfn = (pfnGenerateThread)GetProcAddress(hModule, "GenerateThread");
		if ( NULL == pfn )
			return 0;

		HANDLE hThread = pfn();

		// give thread time to start up
		Sleep(1000);
		
		// terminate thread.
		BOOL bOk = TerminateThread(hThread, 0);

		// dead lock in this function...
		RunProcess(argv[0], NULL);

		FreeLibrary(hModule);
	}

	return 0;
}

