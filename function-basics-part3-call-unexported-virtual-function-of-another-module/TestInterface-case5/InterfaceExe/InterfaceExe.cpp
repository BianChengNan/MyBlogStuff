
#include "../GetInterface/GetInterface.h"

int main()
{
    InterfaceBase* base = GetInterface();
    InterfaceBase* base1 = GetInterface1();
    Interface1* if1 = dynamic_cast<Interface1*>(base);
    if1->Test1(0);

    //if1->Test4(0);

    FreeInterface(if1);
    return 0;
}
