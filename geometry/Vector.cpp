/*
Vector.cpp
Author: Jason Nguyen
May 3, 2021
*/

#include "Vector.hpp"
#include <cmath>
using namespace std;

Vector::Vector()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector Vector::get_vector(const Point& p1, const Point& p2)
{
    Vector vector;
    vector.x = p2.x-p1.x;
    vector.y = p2.y-p1.y;
    vector.z = p2.z-p1.z;
    return vector;
}

Vector Vector::operator+(const Vector& v)
{
    Vector vector;
    vector.x = this->x + v.x;
    vector.y = this->y + v.y;
    vector.z = this->z + v.z;
    return vector;
}

Vector Vector::operator*(double scale)
{
    Vector vector;
    vector.x = this->x * scale;
    vector.y = this->y * scale;
    vector.z = this->z * scale;
    return vector;
}

Vector Vector::operator-()
{
    Vector vector;
    vector.x = -this->x;
    vector.y = -this->y;
    vector.z = -this->z;
    return vector;
}

Vector Vector::operator/(const Vector& v)
{
    Vector vector;
    vector.x = this->x / v.x;
    vector.y = this->y / v.y;
    vector.z = this->z / v.z;
    return vector;
}

double Vector::dot_product(const Vector& v1, const Vector& v2)
{
    double product = 0;
    product += v1.x * v2.x;
    product += v1.y * v2.y;
    product += v1.z * v2.z;
    return product;
}

Vector Vector::cross_product(const Vector& v1, const Vector& v2)
{
    Vector vector;
    vector.x = (v1.y * v2.z) - (v1.z * v2.y);
    vector.y = (v1.z * v2.x) - (v1.x * v2.z);
    vector.z = (v1.x * v2.y) - (v1.y * v2.x);
    return vector;
}

double Vector::len()
{
    double magnitude;
    magnitude = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    return magnitude;
}

Vector Vector::normalize()
{
    Vector unit_vector;
    unit_vector.x = this->x / len();
    unit_vector.y = this->y / len();
    unit_vector.z = this->z / len();

    return unit_vector;
}