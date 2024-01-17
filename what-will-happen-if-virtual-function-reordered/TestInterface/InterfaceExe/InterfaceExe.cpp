#include "../Interface/Interface.h"
int main()
{
    InterfaceBase* base = GetInterface();
    Interface1* if1 = dynamic_cast<Interface1*>(base);
    if1->Test2(0);
    return 0;
}
