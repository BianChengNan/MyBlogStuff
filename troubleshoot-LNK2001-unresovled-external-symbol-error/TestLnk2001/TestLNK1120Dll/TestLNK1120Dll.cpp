
#include "TestLNK1120Dll.h"

#define DLL_EXPORT


#ifdef TRIGGER_LINK_ERROR_1120
std::string& GetStaticData()
#else
std::string GetStaticData()
#endif
{
	static std::string s_data = "data";
	return s_data;
}


