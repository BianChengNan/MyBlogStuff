#pragma once
#include <vector>
#include <string>
#include <memory>

#include "RefCountedPtr.h"

class SheetCellData
{
public:
    SheetCellData() = default;

    SheetCellData(const std::wstring& data_) : data(data_), type(0){}

public:
    std::wstring data;
    int type;
};

class SheetDataHandler;
typedef RefCountedPtr<SheetDataHandler> SheetDataHandlerPtr;

class SheetRowData
{
public:
    SheetRowData() = default;
    SheetRowData(SheetDataHandlerPtr sdhPtr, std::vector<SheetCellData> cells);

public:
    std::vector<SheetCellData> cells;
    SheetDataHandlerPtr sdhPtr;
};

typedef std::shared_ptr<SheetRowData> SheetRowDataPtr;
