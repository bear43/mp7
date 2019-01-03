//
// Created by bear on 28.12.18.
//

#include "CoordDownResearcher.h"

#define LAMBDA_MULTIPLER 2
#define LAMBDA_DIVISIONER 2
#define DEFAULT_LAMBDA 1

CoordDownResearcher::CoordDownResearcher(Function &function, double eps) : Researcher(function, eps)
{}

CoordDownResearcher::CoordDownResearcher(Function &function) : Researcher(function)
{}

double CoordDownResearcher::getFunctionMinimum()
{
    double lambda = DEFAULT_LAMBDA;
    vector<Point<double, double>> points;
    Point<double, double> currentPoint;
    vector<double> x = function.getXes();
    vector<double> startX = function.getXes();
    do
    {
        points.clear();
        for(int xIndex = 0; xIndex < x.size(); xIndex++)
        {
            currentPoint = (function.getMinValueOnRange(-range, range, lambda, xIndex));
            points.push_back(currentPoint);
            x[xIndex] = currentPoint.pos;
            function.setXes(x);
        }
        lambda /= LAMBDA_DIVISIONER;
    } while(abs(points[points.size()-2].value - points[points.size()-1].value) > eps &&
    points[points.size()-2].pos - points[points.size()-1].pos != 0);
    return currentPoint.value;
}
