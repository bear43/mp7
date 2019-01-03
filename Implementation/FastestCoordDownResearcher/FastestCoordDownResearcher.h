//
// Created by bear on 02.01.19.
//

#ifndef UNTITLED1_FASTESTCOORDDOWNRESEARCHER_H
#define UNTITLED1_FASTESTCOORDDOWNRESEARCHER_H

#include "../../Interface/FunctionResearcher.h"

#define DEFAULT_LAMBDA 0.5

class FastestCoordDownResearcher : public Researcher
{
public:
    FastestCoordDownResearcher(Function &function, double eps, double range) : Researcher(function, eps, range)
    {}

    FastestCoordDownResearcher(Function& function, double eps) : FastestCoordDownResearcher(function, eps, 10.0)
    {}

    explicit FastestCoordDownResearcher(Function& function) : FastestCoordDownResearcher(function, 0.0000000000000000000000000000000000000000000000000000000000001)
    {}

private:
    bool bExitCondition(vector<double> &old, vector<double> &_new, double eps)
    {
        if(_new.empty() || old.empty())
        {
            return false;
        }
        double scalarOld = Function::evaluateScalarGradient(old),
               scalarNew = Function::evaluateScalarGradient(_new);
        return (scalarNew-scalarOld) <= eps;
    }
    double getFunctionMinimumWithNormalizedGradient()
    {
        vector<double> gradF, x;
        double fx, lambda = DEFAULT_LAMBDA, scalarGrad;
        do
        {
            gradF = function.normalizeGradient();
            x = function.getXes();
            for(int i = 0; i < x.size(); i++)
                x[i] -= gradF[i];
            function.setXes(x);
            function.evaluate();
            scalarGrad = function.evaluateScalarGradient();
        }
        while(scalarGrad >= eps);
        return function.evaluate();
    }
    double getFunctionMinimum() override
    {
        vector<double> gradF, x, endPoint, normalizedVector;
        double fx, lambda = DEFAULT_LAMBDA, scalarGradOld, scalarGradNew = MAXFLOAT;
        do
        {
            scalarGradOld = scalarGradNew;
            gradF = function.evaluateGradient();
            normalizedVector = function.normalizeGradient();
            x = function.getXes();
            endPoint = x;
            for(int i = 0; i < x.size(); i++)
                endPoint[i] -= gradF[i];
            for(double& value : normalizedVector)
                value = -value/10;
            function.getMinValueOnVectorRange(x, endPoint, normalizedVector);
            scalarGradNew = function.evaluateScalarGradient();
        }
        while((abs(scalarGradOld-scalarGradNew)) > eps);
        return function.evaluate();
    }
};


#endif //UNTITLED1_FASTESTCOORDDOWNRESEARCHER_H
