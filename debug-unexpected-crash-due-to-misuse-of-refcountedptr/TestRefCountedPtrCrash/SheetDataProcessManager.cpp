#include "SheetRowData.h"
#include "SheetDataHandler.h"

#include "SheetDataProcessManager.h"

SheetDataProcessManager& SheetDataProcessManager::Instance()
{
    static SheetDataProcessManager s_instance;
    return s_instance;
}

std::unordered_map<std::wstring, SheetData> SheetDataProcessManager::ReadSheetDatas(const std::wstring& path)
{
    std::unordered_map<std::wstring, SheetData> result;

    // read from excel

    SheetData sheet1;
    sheet1.headers = std::vector<std::wstring>{ L"ID", L"Name", L"Age" };
    sheet1.datasVec = std::vector<std::vector<SheetCellData>>{ std::vector<SheetCellData>{ SheetCellData(L"001"), SheetCellData(L"test"), SheetCellData(L"18") }};
    result[L"Sheet1"] = sheet1;

    result[L"Sheet2"] = SheetData();

    return result;
}


void SheetDataProcessManager::Init(const std::wstring& path)
{
    auto sheetDatas = ReadSheetDatas(path);
    for (auto& it : sheetDatas)
    {
        auto handler = new SheetDataHandler(it.second);
        sdhMap[it.first] = handler;
    }
}

void SheetDataProcessManager::Handle()
{

}
