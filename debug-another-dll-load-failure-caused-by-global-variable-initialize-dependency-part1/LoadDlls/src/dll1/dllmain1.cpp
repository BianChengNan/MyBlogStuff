#include <windows.h>
#include <iostream>
#include "../common/autorunner.h"

#include "../dll2/exports.h"

void PrintMajorVersion()
{
    std::cout << "Major Version of dll2.dll is " << MajorVersion() << std::endl;
}

BEGIN_AUTO_RUN
std::cout << "I'm running in dll1.dll, which implicitly depends on dll2.dll." << std::endl;
END_AUTO_RUN

