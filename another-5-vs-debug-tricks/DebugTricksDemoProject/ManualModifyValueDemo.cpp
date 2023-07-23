#include "stdafx.h"
#include <iostream>

bool HaveIMakeEnoughMoney()
{
    return false;
}

void ManualModifyValueDemo()
{
    auto bRich = HaveIMakeEnoughMoney();
    if (bRich)
    {
        std::cout << "Finally, I'm rich!" << std::endl;
    }
    else
    {
        std::cout << "Oops, I'm still poor!" << std::endl;
    }

}