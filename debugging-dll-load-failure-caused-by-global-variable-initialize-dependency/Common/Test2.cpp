#include "stdafx.h"
#include "conio.h"
#include "Test2.h"

CTest2::CTest2()
{
    printf(__FUNCTION__ " called.\n");
    CTest1::GetMap()["CTest2"] = "CTest2";
}
CTest2 g_t2;