#include "stdafx.h"

#include <string>
#include <iostream>

#include <vector>

#pragma comment(lib, "TestLNK1120Dll.lib")

extern  std::string GetStaticData();
int _tmain(int argc, _TCHAR* argv[])
{
	std::string data = GetStaticData();
	std::cout << data << std::endl;
	return 0;
}

