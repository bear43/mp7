//
// Created by bear on 28.12.18.
//

#ifndef UNTITLED1_FUNCTION_H
#define UNTITLED1_FUNCTION_H

#include <vector>
#include <cmath>
#include <string>
#include <limits>
#include "../Implementation/Point.h"

using namespace std;

struct Function
{
private:
    bool vectorInRange(vector<double> &lawVectorStart, vector<double> &lawVectorEnd, vector<double> &comparingVector)
    {
        double currentStart, currentEnd;
        for(int i = 0; i < lawVectorStart.size(); i++)
        {
            if(lawVectorEnd[i] < lawVectorStart[i])
            {
                currentEnd = lawVectorStart[i];
                currentStart = lawVectorEnd[i];
            }
            else
            {
                currentEnd = lawVectorEnd[i];
                currentStart = lawVectorStart[i];
            }
            if (comparingVector[i] > currentEnd || comparingVector[i] < currentStart)
            {
                return false;
            }
        }
        return true;
    }
    void addToVector(vector<double> &addition, vector<double> &dst)
    {
        for(int i = 0; i < dst.size(); i++)
        {
            dst[i] += addition[i];
        }
    }
public:
    virtual double evaluate() = 0;//Returns f(x) value which evaluates with all function variables;
    virtual vector<double> evaluateGradient() = 0;//evaluates an array with data like { x1, x2, x3, ... }
    virtual vector<double> getXes() = 0;//Returns an array with all variables of function
    virtual void setXes(vector<double>& xes) = 0;//Set xes
    virtual string toString() = 0;
    virtual void reset() = 0;
    virtual double evaluateDerivative() = 0;
    static double evaluateScalarGradient(vector<double> &vec)
    {
        double sum = 0.0;
        for(double& g : vec)
            sum += g*g;
        return sqrt(sum);
    }
    double evaluateScalarGradient()//Returns scalar value of grad(f(x))
    {
        vector<double> vec = evaluateGradient();
        return evaluateScalarGradient(vec);
    }
    vector<double> normalizeGradient()
    {
        vector<double> gradient = evaluateGradient();
        double gradientAbs = evaluateScalarGradient();
        for(double& component : gradient)
            component /= gradientAbs;
        return gradient;
    }
    Point<double, double> getMinValueOnRange(double start, double end, double step, int xIndex)//Finds min value on [start; end]. Freezes all variables but xIndex.
    {
        double minValue = MAXFLOAT, minX = NAN, currentValue;
        vector<double> x = getXes();
        for(double currentX = start; currentX <= end; currentX += step) // NOLINT(cert-flp30-c)
        {
            x[xIndex] = currentX;
            setXes(x);
            currentValue = evaluate();
            if(currentValue < minValue)
            {
                minValue = currentValue;
                minX = currentX;
            }
        }
        return { minX, minValue };
    }

    double getMinValueOnVectorRange(vector<double> &startPoints, vector<double> &endPoints, vector<double> &step)//Finds min value on [start; end]. Freezes all variables but xIndex.
    {
        double minValue = MAXFLOAT, minX = NAN, currentValue;
        //vector<double> originalXes = getXes();
        vector<double> currentPoints(startPoints);
        vector<double> savedMinPoints;
        while(vectorInRange(startPoints, endPoints, currentPoints))
        {
            setXes(currentPoints);
            currentValue = evaluate();
            if(currentValue < minValue)
            {
                minValue = currentValue;
                savedMinPoints = currentPoints;
            }
            addToVector(step, currentPoints);
        }
        setXes(savedMinPoints);
        return minValue;
    }
};

#endif //UNTITLED1_FUNCTION_H
