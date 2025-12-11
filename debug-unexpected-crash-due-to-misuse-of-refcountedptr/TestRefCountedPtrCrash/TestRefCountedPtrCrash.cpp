#include <iostream>
#include "SheetRowData.h"
#include "SheetDataHandler.h"
#include "SheetDataProcessManager.h"
int main()
{
    SheetDataProcessManager::Instance().Init(L"test.xlsx");
    std::cout << "Hello World!\n";
}