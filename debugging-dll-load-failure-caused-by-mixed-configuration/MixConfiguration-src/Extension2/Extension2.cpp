#include "stdafx.h"
#include "Extension2.h"	 
#include "..\Base\Base.h"

int nExtension2 = 0;

EXTENSION_API int GetCallCount(void)
{
	return ++nExtension2;
}

class CExtension2
{
public:
	CExtension2()
	{
		printf(__FUNCTION__ " called.\n");
		CObjectManager::GetMap()["CExtension2"] = "CExtension2";
	}
};

static CExtension2 g_extension2;