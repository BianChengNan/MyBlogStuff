#include "windows.h"

int main(int argc, char* argv[])
{
    HMODULE module = LoadLibraryA(".\\DllUnload.dll");
    Sleep(1000);
    FreeLibrary(module);
    return 0;
}