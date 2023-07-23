#pragma once
#include "cereal/cereal.hpp"

struct AdjustInfo
{
    bool bEnable;
    int top;
    int bottom;
    int left;
    int right;

    AdjustInfo() :
        bEnable(false)
        , top(50)
        , bottom(50)
        , left(50)
        , right(50)
    {}

    template<class Archive>
    void serialize(Archive & ar)
    {
        int version = 1;
        ar(version);
        ar(CEREAL_NVP(bEnable));
        ar(CEREAL_NVP(top));
        ar(CEREAL_NVP(bottom));
        ar(CEREAL_NVP(left));
        ar(CEREAL_NVP(right));
    }
};