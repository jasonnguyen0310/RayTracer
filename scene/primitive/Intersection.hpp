/*
Intersection.hpp
Author: Jason Nguyen
May 9, 2021
*/

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Primitive.hpp"

class Primitive;
struct Intersection
{
    Primitive* intersected_primitive;
    double distance;
    Point point_of_intersection;
    Intersection() {}
};

#endif /* INTERSECTION_H */