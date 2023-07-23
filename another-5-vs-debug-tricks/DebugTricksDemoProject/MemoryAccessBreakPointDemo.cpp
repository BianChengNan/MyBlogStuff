#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define MY_DOLLARS  10000
int g_dollar = MY_DOLLARS;

void ModifyGlobalVariableRandom()
{
    std::vector<int> moneys;
    for (int idx = 0; idx < 1024; ++idx)
    {
        moneys.push_back(idx + 1);
    }

    std::random_shuffle(moneys.begin(), moneys.end());

    if (moneys[512] < 512)
    {
        g_dollar = 0;
    }
}

void MemoryAccessBreakPointDemo()
{
    getchar();

    ModifyGlobalVariableRandom();

    if (g_dollar < MY_DOLLARS)
    {
        std::cout << "Oops, who touches my money?" << std::endl;
    }

}

