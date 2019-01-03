#include <iostream>
#include "Implementation/CoordDown/CoordDownResearcher.h"
#include "Implementation/Function/MyFunction.h"
#include "Implementation/Point.h"
#include "Implementation/FastestCoordDownResearcher/FastestCoordDownResearcher.h"

using namespace std;

int main()
{
    MyFunction func;
    Researcher* researcher = new CoordDownResearcher(func);
    double fx = researcher->getFunctionMinimum();
    cout << "Found minimum f(x) = " <<  fx << endl;
    cout << func.toString() << endl;
    delete researcher;
    func.reset();
    researcher = new FastestCoordDownResearcher(func);
    fx = researcher->getFunctionMinimum();
    cout << "Found minimum f(x) = " <<  fx << endl;
    cout << func.toString() << endl;
    delete researcher;
    return 0;
}