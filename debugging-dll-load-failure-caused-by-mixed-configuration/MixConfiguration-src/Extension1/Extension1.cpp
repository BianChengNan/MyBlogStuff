#include "stdafx.h"
#include "Extension1.h"
#include "..\Base\Base.h"

int nExtension1=0;
EXTENSION_API int GetCallCount(void)
{
	return ++nExtension1;
}

class CExtension1
{
public:
	CExtension1()
	{
		printf(__FUNCTION__ " called.\n");
		CObjectManager::GetMap()["CExtension1"] = "CExtension1";
	}
};

static CExtension1 g_extension1;
