#pragma once
#include <memory>

#include "common.h"

namespace case4
{
    /*
    * CTest::pData is managed by CTest, but when call #Use(), it is used to construct a shared_pt,
    * then it is also managed by a shared_ptr. double free!
    */
    class CTest
    {
    public:
        CTest() { pData = new Common::CDerived(); }

        ~CTest() { delete pData; }

        Common::CDerived* pData;
    };

    static void Use(std::shared_ptr<Common::CDerived> pData)
    {
        pData->DoSomething();
    }

    static void Entry()
    {
        auto pTest = std::make_shared<CTest>();
        Use(std::shared_ptr<Common::CDerived>(pTest->pData));
    }
}