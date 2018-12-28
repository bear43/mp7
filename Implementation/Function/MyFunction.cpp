//
// Created by bear on 28.12.18.
//

#include "MyFunction.h"

double MyFunction::evaluate()
{
    return (5*x1*x1) - (4*x1*x2) + (5*x2*x2) - x1 - x3;
}

vector<double> MyFunction::evaluateGradient() {
    vector<double> values;
    values.push_back((10*x1)-(4*x2) - 1);
    values.push_back((-4*x1) + (10*x2));
    values.push_back(-1);
    return values;
}

MyFunction::MyFunction(double x1, double x2, double x3) : x1(x1), x2(x2), x3(x3)
{

}

vector<double> MyFunction::getXes()
{
    return vector<double> {x1, x3, x3};
}

void MyFunction::setXes(vector<double>& xes)
{
    x1 = xes[0];
    x2 = xes[1];
    x3 = xes[2];
}

MyFunction::MyFunction() : MyFunction(0.0, 0.0, 0.0)
{}

string MyFunction::toString()
{
    stringstream ss;
    ss << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3;
    return ss.str();
}
