#include <windows.h>
#include <map>
#include <string>

#define DLL_EXPORT_DLL2
#include "exports.h"

///////////////////////////////////////////////////////////////////////////////
int MajorVersion() { return 1; }

///////////////////////////////////////////////////////////////////////////////
static std::map<std::string, void(*)()> s_init_callbacks;
void RegisterInitCallback(const char* key, void(*callback)())
{
    s_init_callbacks.insert(std::make_pair(key, callback));
}

///////////////////////////////////////////////////////////////////////////////
class MyGlobalVariable
{
public:
    MyGlobalVariable() { auto module = LoadLibrary(L"dll3.dll"); }
};

MyGlobalVariable s_culprit;

///////////////////////////////////////////////////////////////////////////////
static std::map<std::string, void(*)()> s_callbacks;

void RegisterCallback(const char* key, void(*callback)())
{
    s_callbacks.insert(std::make_pair(key, callback));
}

///////////////////////////////////////////////////////////////////////////////
void Init()
{
    for (auto it : s_init_callbacks)
    {
        it.second();
    }
}
