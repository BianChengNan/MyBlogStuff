#include "windows.h"
#include <iostream>
#include <map>
#include <vector>

typedef void (*PFN_Init)();

std::map<std::string, HMODULE> LoadPlugins(const char* plugins[])
{
    std::map<std::string, HMODULE> result;
    for (int idx = 0; ; ++idx)
    {
        const char* plugin = plugins[idx];
        if (plugin == nullptr)
        {
            break;
        }

        HMODULE module = LoadLibraryA(plugin);
        if (module == nullptr)
        {
            DWORD lastError = GetLastError();
            std::cout << "[+] load ［" << plugin << "] failed with error " << lastError << std::endl;
        }
        else
        {
            result[plugin] = module;
        }
    }

    return result;
}

void InitPlugins(const std::map<std::string, HMODULE>& loaded_plugins)
{
    for (auto& it : loaded_plugins)
    {
        auto init_entry = (PFN_Init)GetProcAddress(it.second, "Init");
        if (init_entry != nullptr)
        {
            init_entry();
        }
    }
}

int main()
{
    std::cout << "[+] load plugin start." << std::endl;

    const char* plugins[] = { "dll1.dll", /*"dll2.dll", "dll3.dll",*/ nullptr };
    auto loaded_module_map = LoadPlugins(plugins);

    std::cout << "[+] load plugin done, press any key to init plugins." << std::endl;
    system("pause");

    InitPlugins(loaded_module_map);
    return 0;
}