#pragma once
#include <memory>

#include "common.h"

namespace case5
{
    /*
    * data is on stack, after managed by a shared_ptr, it will be deleted.
    * we CAN NOT delete am address on stack!
    */
    static void Use(std::shared_ptr<Common::CDerived> pData)
    {
        pData->DoSomething();
    }

    static void Entry()
    {
        // well, I have simplify this error quite much.
        Common::CDerived data;
        auto pData = std::shared_ptr<Common::CDerived>(&data);

        Use(pData);
    }
}