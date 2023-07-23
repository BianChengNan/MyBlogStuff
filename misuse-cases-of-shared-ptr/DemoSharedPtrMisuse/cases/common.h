#pragma once

#include <stdio.h>

namespace Common
{
    class CBase
    {
    public:
        CBase() { printf(__FUNCTION__ "\n"); }
        virtual ~CBase() { printf(__FUNCTION__ "\n"); }
        virtual void DoSomething() const { printf(__FUNCTION__ "\n"); }
    };

    class CDerived : public CBase
    {
    public:
        CDerived() { printf(__FUNCTION__ "\n"); }
        virtual ~CDerived() { printf(__FUNCTION__ "\n"); }
        virtual void DoSomething() const override { printf(__FUNCTION__ "\n"); }
    };
}