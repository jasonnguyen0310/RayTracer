/*
Vector.hpp
Author: Jason Nguyen
May 3, 2021
*/

#ifndef VECTOR_H
#define VECTOR_H

struct Vector
{
    double x;
    double y;
    double z;
    Vector(double x_coord, double y_coord, double z_coord) : x(x_coord), y(y_coord), z(z_coord) {}
};

#endif /* VECTOR_H */