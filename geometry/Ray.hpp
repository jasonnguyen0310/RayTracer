/*
Ray.hpp
Author: Jason Nguyen
May 3, 2021
*/

#ifndef RAY_H
#define RAY_H

#include "Point.hpp"
#include "Vector.hpp"

class Ray 
{
    public:
        // starting point of ray
        Point start_point;
        // direction vector of ray
        Vector direction_vector;
        Ray(Point p, Vector v) : start_point(p), direction_vector(v) {}
};

#endif /* RAY_H */