/*
Point.hpp
Author: Jason Nguyen
May 3, 2021
*/

#ifndef POINT_H
#define POINT_H
struct Point
{
    double x;
    double y;
    double z;
    Point(double x_coord, double y_coord, double z_coord) : x(x_coord), y(y_coord), z(z_coord) {}
};

#endif /* POINT_H */