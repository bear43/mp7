//
// Created by bear on 28.12.18.
//

#ifndef UNTITLED1_MYFUNCTION_H
#define UNTITLED1_MYFUNCTION_H

#include "../../Interface/Function.h"
#include <sstream>

struct MyFunction : Function
{
private:
    double x1;
    double x2;
    double x3;
public:

    MyFunction(double x1, double x2, double x3);

    MyFunction();

    double evaluate() override;

    vector<double> evaluateGradient() override;

    vector<double> getXes() override;

    void setXes(vector<double>& xes) override;

    string toString() override;

};


#endif //UNTITLED1_MYFUNCTION_H
