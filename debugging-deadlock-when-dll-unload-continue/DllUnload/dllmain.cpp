#include "pch.h"

#include "process.h"
#include <stdio.h>

HANDLE g_hThread;

volatile bool g_quit = false;

unsigned __stdcall procThread(void*)
{
    while (!g_quit)
    {
        OutputDebugStringA("====procThread running.\n");
        Sleep(100);
    }

    OutputDebugStringA("====procThread quitting.\n");

    return 0;
}

unsigned __stdcall quitDemoProc(void*)
{
    int idx = 0;
    while (idx++ < 5)
    {
        OutputDebugStringA("====quitDemoProc running!!!!!!!!\n");
        Sleep(10);
    }
    OutputDebugStringA("====quitDemoProc quitting!!!\n");
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        g_hThread = (HANDLE)_beginthreadex(NULL, 0, &procThread, NULL, 0, NULL);
        CloseHandle((HANDLE)_beginthreadex(NULL, 0, &quitDemoProc, NULL, 0, NULL));
    }
    break;
    case DLL_THREAD_ATTACH:
    {
        OutputDebugStringA("====DLL_THREAD_ATTACH called.\n");
    }
    break;
    case DLL_THREAD_DETACH:
    {
        OutputDebugStringA("====DLL_THREAD_DETACH called.\n");
    }
    break;
    case DLL_PROCESS_DETACH:
    {
        char buffer[256] = "";
        sprintf_s(buffer, "====DLL_PROCESS_DETACH begin wait for thread=%x\n", (int)g_hThread);
        OutputDebugStringA(buffer);
        g_quit = true;
        DWORD waitResult = WaitForSingleObject(g_hThread, INFINITE);

        sprintf_s(buffer, "====DLL_PROCESS_DETACH end wait for thread=%x, result=%x\n", (int)g_hThread, waitResult);
        OutputDebugStringA(buffer);
    }
    break;
    }
    return TRUE;
}