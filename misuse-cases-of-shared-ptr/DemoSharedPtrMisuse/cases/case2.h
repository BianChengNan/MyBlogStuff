#pragma once
#include <memory>

#include "common.h"

namespace case2
{
    static void Use(std::shared_ptr<Common::CDerived> pData)
    {
        pData->DoSomething();
    }

    static std::shared_ptr<Common::CBase> GetData()
    {
        return std::make_shared<Common::CDerived>();
    }
    static void Entry()
    {
        auto pTest = std::make_shared<Common::CDerived>();

        // Oops, double free
        std::shared_ptr<Common::CBase> pData = GetData();
        auto pRawData = pData.get();
        Common::CDerived* pDerived = dynamic_cast<Common::CDerived*>(pRawData);
        if (pDerived)
        {
            Use(std::shared_ptr<Common::CDerived>(pDerived));
        }

        // code below is good
        //Use(std::dynamic_pointer_cast<Common::CDerived>(pData));
    }
}