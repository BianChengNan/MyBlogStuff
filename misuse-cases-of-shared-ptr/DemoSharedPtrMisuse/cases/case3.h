#pragma once
#include <memory>

#include "common.h"

namespace case3
{
    /*
    * after #ReturnRawPointer() and #GetRawPointer() returned, shared_ptr's destructor is called,
    * then the returned raw pointer points to a deleted address. bang!
    */
    static Common::CDerived* ReturnRawPointer()
    {
        auto pData = std::make_shared<Common::CDerived>();
        return pData.get();
    }

    static bool GetRawPointer(Common::CDerived* & pReturnedData)
    {
        auto pData = std::make_shared<Common::CDerived>();
        pReturnedData = pData.get();
        return (pReturnedData != nullptr);
    }

    static void Entry()
    {
        auto pData = ReturnRawPointer();
        pData->DoSomething();

        pData = nullptr;
        GetRawPointer(pData);
        pData->DoSomething();
    }
}