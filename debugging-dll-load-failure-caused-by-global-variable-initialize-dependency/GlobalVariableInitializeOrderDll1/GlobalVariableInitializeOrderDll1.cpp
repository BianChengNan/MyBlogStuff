#include "stdafx.h"
#include "GlobalVariableInitializeOrderDll1.h"

static int nGlobalVariableInitializeOrderDll1 = 0;

GLOBALVARIABLEINITIALIZEORDERDLL_API int GetCallCount(void)
{
	return ++nGlobalVariableInitializeOrderDll1;
}

