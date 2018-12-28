//
// Created by kostya on 28.12.18.
//

#ifndef UNTITLED1_POINT_H
#define UNTITLED1_POINT_H

template <typename T, typename T2>
class Point
{
public:
    T2 pos;
    T value;
    Point(T2 pos, T value) : pos(pos), value(value)
    {}
    Point() : Point(0, 0)
    {}
};


#endif //UNTITLED1_POINT_H
