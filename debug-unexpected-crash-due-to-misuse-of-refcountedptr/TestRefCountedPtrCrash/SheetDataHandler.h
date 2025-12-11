#pragma once

#include <unordered_map>

#include <vector>

#include "RefCountedPtr.h"

class SheetData
{
public:
    std::vector<std::wstring> headers;
    std::vector<std::vector<SheetCellData>> datasVec;
};

class SheetDataHandler;
typedef RefCountedPtr<SheetDataHandler> SheetDataHandlerPtr;

class SheetDataHandler : public RefCounted<IRefCounted>
{
public:
    SheetDataHandler(const SheetData& sheetData);

public:
    static void HandleMissingColumn(SheetDataHandlerPtr helper, const SheetData& sheetData);

public:
    std::vector<SheetRowDataPtr> rowDatas;
    std::vector<std::wstring> headers;
};

