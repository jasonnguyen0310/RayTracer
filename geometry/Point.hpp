/*
Point.hpp
Author: Jason Nguyen
May 3, 2021
*/

#include "Vector.hpp"

#ifndef POINT_H
#define POINT_H

class Vector;

struct Point
{
    double x;
    double y;
    double z;
    Point();
    Point(double x_coord, double y_coord, double z_coord) : x(x_coord), y(y_coord), z(z_coord) {}
    Point operator+(const Vector p);
};

#endif /* POINT_H */