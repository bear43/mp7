//
// Created by bear on 28.12.18.
//

#ifndef UNTITLED1_FUNCTION_H
#define UNTITLED1_FUNCTION_H

#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct Function
{
public:
    virtual double evaluate() = 0;//Returns f(x) value which evaluates with all function variables;
    virtual vector<double> evaluateGradient() = 0;//evaluates an array with data like { x1, x2, x3, ... }
    virtual vector<double> getXes() = 0;//Returns an array with all variables of function
    virtual void setXes(vector<double>& xes) = 0;//Set xes
    virtual string toString() = 0;
    double evaluateScalarGradient()//Returns scalar value of grad(f(x))
    {
        vector<double> grad = evaluateGradient();
        double sum = 0.0;
        for(double& g : grad)
            sum += g*g;
        return sqrt(sum);
    }
};

#endif //UNTITLED1_FUNCTION_H
