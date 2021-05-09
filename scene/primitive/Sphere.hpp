/*
Sphere.hpp
Author: Jason Nguyen
May 2, 2021
*/

#include "../geometry/Point.hpp"
#include "../geometry/Ray.hpp"
#include "../geometry/Vector.hpp"

#ifndef SPHERE_H
#define SPHERE_H

class Sphere
{
    public:
        Point center;
        int radius;
        Sphere();
        Sphere(Point c, int r) : center(c), radius(r) {}

        // Calculate the distances of the intersections
        Vector intersections(Ray r);
};

#endif /* SPHERE_H */