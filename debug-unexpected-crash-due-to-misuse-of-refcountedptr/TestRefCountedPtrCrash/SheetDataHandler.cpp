#include "SheetRowData.h"
#include "SheetDataHandler.h"

SheetDataHandler::SheetDataHandler(const SheetData& sheetData)
{
    HandleMissingColumn(this, sheetData);
}

void SheetDataHandler::HandleMissingColumn(SheetDataHandlerPtr helper, const SheetData& sheetData)
{
    auto headers = sheetData.headers;
    auto datasVec = sheetData.datasVec;

    // handle logic

    helper->headers = headers;
    for (auto& rowData : datasVec)
    {
        helper->rowDatas.push_back(std::make_shared<SheetRowData>(helper, rowData));
    }
}
