#include "stdafx.h" 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> GenerateRandomData()
{
    std::vector<int> moneys;
    for (int idx = 0; idx < 1024; ++idx)
    {
        moneys.push_back(idx + 1);
    }

    std::random_shuffle(moneys.begin(), moneys.end());

    return moneys;
}

void DragToSpecificLineDemo()
{
    auto moneys = GenerateRandomData();
    auto totalMoney = std::accumulate(moneys.begin(), moneys.end(), 0);
    if (totalMoney > 100 * 10000)
    {
        std::cout << "Finally, I have one million dollars." << std::endl;
    }
    else
    {
        std::cout << "Oops, I still need to work hard." << std::endl;
    }
}