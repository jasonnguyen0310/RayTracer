/*
Sphere.hpp
Author: Jason Nguyen
May 2, 2021
*/

#ifndef SPHERE_H
#define SPHERE_H

#include "Primitive.hpp"


class Sphere : public Primitive
{
    public:
        int radius;
        Sphere();
        Sphere(Point c, int r) : Primitive{c}, radius{r} {}
        // Calculate the distances of the intersections
        Intersection intersections(Ray r) override;
};

#endif /* SPHERE_H */