/*
Point.cpp
Author: Jason Nguyen
May 3, 2021
*/

#include "Point.hpp"

Point::Point()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Point Point::operator+(const Vector v)
{
    Point e;
    e.x = this->x + v.x;
    e.y = this->y + v.y;
    e.z = this->z + v.z;
    
    return e;
}