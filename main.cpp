#include <iostream>
#include "Implementation/CoordDown/CoordDownResearcher.h"
#include "Implementation/Function/MyFunction.h"
#include "Implementation/Point.h"

using namespace std;

int main()
{
    MyFunction func;
    CoordDownResearcher researcher(func);
    Point<double, double> minPoint = researcher.getFunctionMinimum();
    cout << "Found minimum f(x) = " <<  minPoint.value << endl;
    cout << func.toString();
    return 0;
}