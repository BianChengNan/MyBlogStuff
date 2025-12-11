#pragma once

class SheetDataProcessManager
{
public:
    static SheetDataProcessManager& Instance();

    static std::unordered_map<std::wstring, SheetData> ReadSheetDatas(const std::wstring& path);

public:
    void Init(const std::wstring& path);

    void Handle();

public:
    std::unordered_map<std::wstring, SheetDataHandlerPtr> sdhMap;
};

