#pragma once
#include <memory>

#include "common.h"

namespace case1
{
    /*
    * pRawData is already managed by a shared_ptr (pData in function #Entry()),
    * in function #Use(), another shared_ptr (pNewData) manages the raw pointer too.
    * now, we have two shared_ptr manage the same raw pointer. Oops, double free!
    */
    static void Use(Common::CDerived* pRawData)
    {
        std::shared_ptr<Common::CDerived> pNewData(pRawData);
        pNewData->DoSomething();
    }

    static void Entry()
    {
        auto pData = std::make_shared<Common::CDerived>();
        Use(pData.get());
    }
}