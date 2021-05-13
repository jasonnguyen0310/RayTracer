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

    // two points to get a vector from first point to the second
    Vector get_vector(const Point& p1, const Point& p2);
    // adding vectors together
    Vector operator+(const Vector& v);
    // division operator
    Vector operator/(const Vector& v);
    // scaling vectors with a scalar
    Vector operator*(double scale);
    // negation operator
    Vector operator-();
    // dot product between two vectors
    double dot_product(const Vector& v1, const Vector& v2);
    // cross product between two vectors
    Vector cross_product(const Vector& v1, const Vector& v2);
    // magnitude of vector
    double len();
    // normalize vector
    Vector normalize();
};

#endif /* VECTOR_H */