#include "stdafx.h"
#include <memory>
#include <iostream>
#include "RefCountedPtr.h"

class PBObject : public RefCounted<IRefCounted>
{
public:
    virtual double Volume() { return 0.0; }
};

class PBWall : public PBObject
{
public:
    virtual double Volume() { return 100.0; }

    ~PBWall() { std::cout << __FUNCTION__ << std::endl; }
};

void Test()
{
    RefCountedPtr<PBObject> pWall(new PBWall());
    std::shared_ptr<PBObject> pSharedWall(pWall.get(), 
        [](PBObject* p){ /* p->Release(); */ } // this is a our customized deleter, do nothing, can't call p->Release();
    );

    auto pCopyWall = pSharedWall;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test();
    return 0;
}

