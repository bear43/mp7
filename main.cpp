#include <iostream>
#include "Implementation/CoordDown/CoordDownResearcher.h"
#include "Implementation/Function/MyFunction.h"

using namespace std;

int main()
{
    MyFunction func;
    CoordDownResearcher researcher(func);
    cout << "Found minimum f(x) = " << researcher.getFunctionMinimum() << endl;
    cout << func.toString();
    return 0;
}