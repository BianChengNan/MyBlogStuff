#include <windows.h>
#include <iostream>

#include "../common/autorunner.h"
#include "../dll2/exports.h"

///////////////////////////////////////////////////////////////////////////////
void Dll3InitCallback()
{
    std::cout << "I'm callback from dll3.dll" << std::endl;
}

BEGIN_AUTO_RUN
RegisterInitCallback("dll3", Dll3InitCallback);
END_AUTO_RUN

///////////////////////////////////////////////////////////////////////////////
void Dll3Callback()
{
    std::cout << "I'm callback from dll3.dll" << std::endl;
}

BEGIN_AUTO_RUN
RegisterCallback("dll3", Dll3Callback);
END_AUTO_RUN
