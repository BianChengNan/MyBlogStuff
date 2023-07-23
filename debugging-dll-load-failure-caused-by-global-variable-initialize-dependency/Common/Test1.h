#pragma once
#include <map>
#include <string>
class CTest1
{
public:
    CTest1();

    static std::map<std::string, std::string>& GetMap()
    {
        return s_manager;
    }

private:
    static std::map<std::string, std::string> s_manager;
};

