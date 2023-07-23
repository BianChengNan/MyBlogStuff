#include "stdafx.h"

extern void ConditionBreakPointDemo();
extern void MemoryAccessBreakPointDemo();
extern void ManualModifyValueDemo();
extern void DragToSpecificLineDemo();
extern void ExceptionDemo();

int _tmain(int argc, _TCHAR* argv[])
{
    ConditionBreakPointDemo();
    MemoryAccessBreakPointDemo();
    ManualModifyValueDemo();
    DragToSpecificLineDemo();
    //ExceptionDemo();
	return 0;
}

