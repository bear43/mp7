//
// Created by bear on 28.12.18.
//

#include "CoordDownResearcher.h"

#define LAMBDA_MULTIPLER 2
#define LAMBDA_DIVISIONER 2
#define DEFAULT_LAMBDA 1.0

CoordDownResearcher::CoordDownResearcher(Function &function, double eps) : Researcher(function, eps)
{}

CoordDownResearcher::CoordDownResearcher(Function &function) : Researcher(function)
{}

double CoordDownResearcher::getFunctionMinimum()
{
    double min, lambda = DEFAULT_LAMBDA, current;
    int currentXindex = 0;
    bool changeSignFlag = false;
    vector<double> xes = function.getXes();
    vector<double> fx, tmpfx;
    fx.push_back(function.evaluate());
    tmpfx.push_back(fx[0]);
    while(fx.size() < xes.size() + 1 || abs(fx[fx.size()-2] - fx[fx.size()-1]) >= eps)
    {
        if(currentXindex < xes.size())
        {
            xes[currentXindex] += lambda;
            if(xes[currentXindex] > range || xes[currentXindex] < -range)
            {
                xes[currentXindex] -= lambda;
                changeSignFlag = false;
                currentXindex++;
                lambda /= LAMBDA_DIVISIONER;
                range *= 2;
                fx.push_back(function.evaluate());
            }
            else
            {
                function.setXes(xes);
                current = function.evaluate();
                if (current < tmpfx[tmpfx.size() - 1])
                {
                    tmpfx.push_back(function.evaluate());
                }
                else if (current == tmpfx[tmpfx.size() - 1])
                {
                    lambda *= LAMBDA_MULTIPLER;
                }
                else
                {
                    if (changeSignFlag)
                    {
                        changeSignFlag = false;
                        xes[currentXindex] -= lambda;
                        currentXindex++;
                        if (tmpfx.size() >= 2)
                            tmpfx.erase(tmpfx.begin(), tmpfx.end() - 1);
                        fx.push_back(tmpfx[0]);
                    }
                    else
                    {
                        lambda = -lambda;
                        xes[currentXindex] += lambda;
                        changeSignFlag = true;
                    }
                }
            }

        }
        else
        {
            currentXindex = 0;
            lambda /= LAMBDA_DIVISIONER;
            tmpfx.clear();
            tmpfx.push_back(fx[fx.size()-1]);
        }
    }
    function.setXes(xes);
    min = fx[fx.size()-1];
    return min;
}
