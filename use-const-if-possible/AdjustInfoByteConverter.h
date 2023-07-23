#pragma once
#include <vector>
#include <sstream>
#include "AdjustInfo.h"
#include "cereal/archives/binary.hpp"

class AdjustInfoByteConverter
{
public:
static std::vector<byte> ToBytes(const AdjustInfo& windowReduceInfo)
{
    std::ostringstream oss;
    {
        cereal::BinaryOutputArchive archive(oss);
        archive(windowReduceInfo);
    }

    auto str = oss.str();
    std::vector<byte> data(str.begin(), str.end());

    return data;
}

static AdjustInfo FromBytes(const std::vector<byte>& datas)
{
    std::stringstream ss;
    std::copy(datas.begin(), datas.end(), std::ostream_iterator<byte>(ss));
    cereal::BinaryInputArchive deserializer(ss);

    AdjustInfo windowReduceInfo;
    deserializer(windowReduceInfo);
    return windowReduceInfo;
}
};
