#include "stdafx.h"
#include "windows.h"

double ToGb(size_t bytes)
{
	return bytes / 1024.0 / 1024.0 / 1024.0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LPVOID result = VirtualAllocEx(GetCurrentProcess(), (LPVOID)0, 0x1000, MEM_RESERVE | MEM_TOP_DOWN, PAGE_READWRITE);
	printf("highest address : %0x, about %.3lfGB", result, ToGb((size_t)result));
	return 0;
}