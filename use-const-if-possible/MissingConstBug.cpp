#include "stdafx.h"
#include "DemoObject.h"

int _tmain(int argc, _TCHAR* argv[])
{
    CDemoObject object;
    AdjustInfo info;
    auto bytes = AdjustInfoByteConverter::ToBytes(info);
    object.SetAdjustInfo(bytes);

    // in real project, object will be serialized, and deserialized.
    // following code may run on another thread.
    std::vector<byte> restoreBytes;
    object.GetAdjustInfo(restoreBytes);
    auto info1 = AdjustInfoByteConverter::FromBytes(restoreBytes);

    return 0;
}