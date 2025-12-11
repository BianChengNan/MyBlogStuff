#include "SheetRowData.h"
#include "SheetDataHandler.h"

SheetRowData::SheetRowData(SheetDataHandlerPtr sdhPtr_, std::vector<SheetCellData> cells_) : sdhPtr(sdhPtr_), cells(cells_)
{

}
