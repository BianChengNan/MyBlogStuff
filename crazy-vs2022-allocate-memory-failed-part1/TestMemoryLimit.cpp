#include <iostream>
#include "windows.h"

const size_t one_gb = 1LL * 1024LL * 1024LL * 1024LL; // 1 GB

double ToGb(size_t bytes)
{
    return bytes / 1024.0 / 1024.0 / 1024.0;
}

double ToTb(size_t bytes)
{
    return bytes / 1024.0 / 1024.0 / 1024.0 / 1024.0;
}

size_t TestMaxAllocateMemory(size_t init_size, size_t decrease_size, DWORD allocation_type)
{
    LPVOID p = nullptr;
    while (nullptr == (p = VirtualAlloc(nullptr, init_size, allocation_type, PAGE_READWRITE)))
    {
        auto last_error = GetLastError();
        std::cout << "allocate " << ToGb(init_size) << " GB failed. last error:" << last_error
            << ". try allocate " << ToGb(init_size - decrease_size) << " GB." << std::endl;

        init_size -= decrease_size;
    }

    return init_size;
}

void TestMaxReserveMemory()
{
    size_t size_reserve = 128LL * 1024LL * one_gb;  // 128 TB
    size_reserve = TestMaxAllocateMemory(size_reserve, one_gb, MEM_RESERVE);
    std::cout << "allocate " << ToTb(size_reserve) << " TB reserver memory success." << std::endl;
}

void TestMaxCommitMemory()
{
    size_t size_commit = 128LL * one_gb; // 128 GB
    size_commit = TestMaxAllocateMemory(size_commit, one_gb, MEM_COMMIT);
    std::cout << "allocate " << ToGb(size_commit) << " GB commit memory success." << std::endl;
}

int main()
{
    TestMaxReserveMemory();
    //TestMaxCommitMemory();
    std::getchar();
    return 0;
}




