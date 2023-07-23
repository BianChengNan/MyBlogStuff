#include "stdafx.h"
#include "windows.h"
#include "process.h"

unsigned __stdcall SubWorkProc(void* param)
{
	int* data = (int*)param;
	while (1)
	{
		*data = 1;
		Sleep(1000);
	}

	return 0;
}

unsigned __stdcall WorkProc(void* param)
{
	int data = 0;
	_beginthreadex(NULL, 0, &SubWorkProc, &data, 0, NULL);
	while (1)
	{
		Sleep(1000);
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto hThread = (HANDLE)_beginthreadex(NULL, 0, &WorkProc, NULL, 0, NULL);
	Sleep(1000);
	TerminateThread(hThread, 0xdead);
	Sleep(INFINITE);
	return 0;
}