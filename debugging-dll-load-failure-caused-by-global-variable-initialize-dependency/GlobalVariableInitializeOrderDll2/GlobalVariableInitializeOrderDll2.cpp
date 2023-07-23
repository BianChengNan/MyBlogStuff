#include "stdafx.h"
#include "GlobalVariableInitializeOrderDll2.h"

static int nGlobalVariableInitializeOrderDll2=0;

GLOBALVARIABLEINITIALIZEORDERDLL_API int GetCallCount(void)
{
	return ++nGlobalVariableInitializeOrderDll2;
}
