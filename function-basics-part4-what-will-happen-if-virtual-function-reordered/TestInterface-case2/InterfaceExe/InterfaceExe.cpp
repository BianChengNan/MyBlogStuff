#include "../Interface/Interface.h"
int main()
{
    Interface1* if1 = dynamic_cast<Interface1*>(GetInterface());
    if1->Test4(0);
    return 0;
}
