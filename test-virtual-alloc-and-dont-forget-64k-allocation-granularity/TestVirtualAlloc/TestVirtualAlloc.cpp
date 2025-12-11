#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main(int argc, char *argv[])
{
	int nk = 4;
	if (argc < 2)
	{
		printf("usage: TestVirtualAlloc.exe N(kb). default 4kb");
	}
	else
	{
		nk = atoi(argv[1]);
	}

    int idx = 0;
    while (true)
    {
        auto pAddr = VirtualAlloc(nullptr, nk * 1024, MEM_RESERVE, PAGE_READWRITE);
        if (pAddr == nullptr)
        {
			printf("VirtualAlloc(%dkb) loop %6d failed. last error 0n%d\r\n", nk, idx++, GetLastError());
            getchar();
        }
        else
        {
			printf("VirtualAlloc(%dkb) loop %6d succeed. address 0x%08x\r\n", nk, idx++, pAddr);
        }
    }
}
