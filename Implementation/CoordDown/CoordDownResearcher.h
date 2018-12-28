//
// Created by bear on 28.12.18.
//

#ifndef UNTITLED1_MYRESEARCHER_H
#define UNTITLED1_MYRESEARCHER_H

#include "../../Interface/FunctionResearcher.h"
#include <vector>

class CoordDownResearcher : Researcher
{
public:
    CoordDownResearcher(Function &function, double eps);

    explicit CoordDownResearcher(Function &function);

    double getFunctionMinimum() override;

};


#endif //UNTITLED1_MYRESEARCHER_H
