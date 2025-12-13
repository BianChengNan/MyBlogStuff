#include <iostream>
#include <string>

class CResult
{
public:
    CResult(const std::wstring& data_)
        : data(data_)
    {
    }

protected:
    std::wstring data;
};

int DoModify()
{
    // a lot logic code, return error code
    return 1;
}

std::wstring GetErrorStr(int error)
{
    switch (error)
    switch (error)
    {
    case 0:
        return L"Ok";
    case -1:
        return L"Invalid Param";
    case 1:
        return L"Operation Failed";
    // a lot more other cases
    default:
        return L"N/A";
    }
}

int main()
{
    auto modifyResult = DoModify();
    CResult result(GetErrorStr(modifyResult));
}