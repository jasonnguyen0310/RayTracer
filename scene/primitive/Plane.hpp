/*
Plane.hpp
Author: Jason Nguyen
May 9, 2021
*/

#ifndef PLANE_H
#define PLANE_H

#include "Primitive.hpp"

class Plane : public Primitive
{
    public:
        Point plane_point;
        Vector plane_normal;
        Plane(Point p, Vector n) : Primitive(), plane_point(p), plane_normal{n} {}
        Intersection intersections(Ray r) override;
};

#endif /* PLANE_H */