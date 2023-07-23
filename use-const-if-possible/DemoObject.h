#pragma once
#include "ObjectProperty.h"
#include "AdjustInfo.h"
#include "AdjustInfoByteConverter.h"

class CDemoObject
{
private:
    ExtendPropertySet extendProperty;

public:
    void SetAdjustInfo(const std::vector<byte>& bytes)
    {
        PropertyValue value(bytes);
        extendProperty.SetSubParam("AdjustInfo", value);
    }

    int GetAdjustInfo(std::vector<byte>& bytes) const
    {
        PropertyValue value;
        extendProperty.GetSubParam("AdjustInfo", value);
        bytes = value.m_value.m_valueByte;
        return (int)bytes.size();
    }
};