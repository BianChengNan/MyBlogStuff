#include "../Interface/Interface.h"
int main()
{
    Interface1* if1 = dynamic_cast<Interface1*>(GetInterface());
    Interface1* if2 = new Interface1();
    if1->Test2(0);
    if2->Test2(1);
    return 0;
}
