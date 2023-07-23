#include "windows.h"
#include "stdio.h"
#include "conio.h"

typedef int(*pfnGetCallCount)();

int wmain(int argc, wchar_t* argv[])
{
	printf("press any key to start\n");
	_getch();

	auto hDll1 = LoadLibraryA("Extension1.dll");
	auto GetCallCount1 = (pfnGetCallCount)GetProcAddress(hDll1, "GetCallCount");

	auto hDll2 = LoadLibraryA("Extension2.dll");
	auto GetCallCount2 = (pfnGetCallCount)GetProcAddress(hDll2, "GetCallCount");

	printf("----> start count\n");
	int idx = 0;
	while (idx++ < 10)
	{
		if (GetCallCount1)
			printf("call count1 is %d\n", GetCallCount1());

		if (GetCallCount2)
			printf("call count2 is %d\n", GetCallCount2());
	}

	printf("function done, press any key to exit\n");
	_getch();

	// not necessary, but good habit.
	FreeLibrary(hDll1);
	FreeLibrary(hDll2);

	return 0;
}
