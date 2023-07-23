#include "stdafx.h"
#include "Base.h"

std::map<std::string, std::string>& CObjectManager::GetMap()
{
	static std::map<std::string, std::string> s_manager;
	return s_manager;
}