#include "stdafx.h"

int CalculateSumByIndex(int index)
{
    if (index == 1024)
    {
        return -1024;
    }

    return index;
}

void ConditionBreakPointDemo()
{
    auto sum = 0;
    for (int idx = 0; idx < 10000; ++idx)
    {
        auto curValue = CalculateSumByIndex(idx);
        sum += curValue;
    }
}