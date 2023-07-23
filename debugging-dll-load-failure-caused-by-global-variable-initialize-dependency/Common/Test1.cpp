#include "stdafx.h"
#include "conio.h"
#include "Test1.h"

CTest1::CTest1()
{
    printf(__FUNCTION__ " called.\n");
}

std::map<std::string, std::string> CTest1::s_manager;

CTest1 g_t1;

