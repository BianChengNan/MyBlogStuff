#pragma once
#include <vector>
#include <map>

class PropertyValue
{
public:
    enum { VALUENULL, INT, DOUBLE, Bool, String, Block } m_type;
    PropertyValue() : m_type(VALUENULL) {}

    struct
    {
        std::vector<byte> m_valueByte;
    } m_value;

    template<class T>
    PropertyValue(T value)
    {
        m_type = Block;
        unsigned __int32 nSize = sizeof(value);
        byte *data = (byte*)&value;
        for (unsigned __int32 i = 0; i < nSize; ++i)
        {
            m_value.m_valueByte.push_back((byte)(*(data + i)));
        }
    }

    PropertyValue(std::vector<byte>& value)
    {
        m_type = Block;
        m_value.m_valueByte = value;
    }
};

class ExtendPropertySet
{
public:
    void SetSubParam(const std::string& name, PropertyValue param)
    {
        m_SubParamMap[name] = param;
    }

    bool GetSubParam(const std::string& name, PropertyValue& param) const
    {
        auto it = m_SubParamMap.find(name);
        if (it != m_SubParamMap.end())
        {
            param = it->second;
            return true;
        }
        return false;
    }

private:
    std::map<std::string, PropertyValue>  m_SubParamMap;
};