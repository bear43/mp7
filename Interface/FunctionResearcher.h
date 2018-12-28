//
// Created by bear on 28.12.18.
//

#ifndef UNTITLED1_FUNCTIONRESEARCHER_H
#define UNTITLED1_FUNCTIONRESEARCHER_H

#define DEFAULT_EPS 0.001
#define DEFAULT_RANGE 10.0

#include "Function.h"
#include "../Implementation/Point.h"

class Researcher
{
protected:
    Function& function;
    double eps;
    double range;
public:
    virtual Point<double, double> getFunctionMinimum() = 0;
    Researcher(Function& function, double eps, double range) : function(function), eps(eps), range(range)
    {}
    Researcher(Function& function, double eps) : Researcher(function, eps, DEFAULT_RANGE)
    {
    }
    explicit Researcher(Function& function) : Researcher(function, DEFAULT_EPS)
    {
    }
};

#endif //UNTITLED1_FUNCTIONRESEARCHER_H
