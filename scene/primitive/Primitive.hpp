/*
Primitive.hpp
Author: Jason Nguyen
May 9, 2021
*/

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "../../geometry/Point.hpp"
#include "../../geometry/Ray.hpp"
#include "../../geometry/Vector.hpp"
#include "Intersection.hpp"

class Intersection;
// Abstract class : Primitive
class Primitive
{
    public:
    // Pure virtual functions
        Point origin;
        Primitive() : origin(Point(0.0,0.0,0.0)) {}
        Primitive(Point c) : origin(c) {}
        virtual Intersection intersections(Ray r) = 0;
};

#endif /* PRIMITIVE_H */