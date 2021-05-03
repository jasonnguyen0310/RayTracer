/*
Vector.hpp
Author: Jason Nguyen
May 3, 2021
*/

#ifndef VECTOR_H
#define VECTOR_H
#include "Point.hpp"
struct Vector
{
    double x;
    double y;
    double z;
    Vector();
    Vector(double x_coord, double y_coord, double z_coord) : x(x_coord), y(y_coord), z(z_coord) {}
    Vector get_vector(const Point& p1, const Point& p2);
    Vector operator+(const Vector& v);
    Vector operator*(double scale);
    Vector dot_product(const Vector& v1, const Vector& v2);
    double len();
    Vector unit_vector();
};

#endif /* VECTOR_H */