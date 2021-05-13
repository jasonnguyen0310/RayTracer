/*
Plane.cpp
Author: Jason Nguyen
May 9, 2021
*/

#include "Plane.hpp"
#include <iostream>
using namespace std;

Intersection Plane::intersections(Ray r)
{
    Intersection i;

    Vector utility_vector;
    Vector normal = plane_normal.normalize();
    Vector plane_vector = utility_vector.get_vector(origin, plane_point);
    double distance =  -(utility_vector.dot_product(plane_vector, normal));
    
    double vd = utility_vector.dot_product(r.direction_vector, normal);

    if (vd == 0)
    {
        Point point_of_intersection = r.start_point + r.direction_vector * vd;
        i.intersected_primitive = this;
        i.distance = vd;
        i.point_of_intersection = point_of_intersection;
        return i;
    }
    else
    {
        distance = -(utility_vector.dot_product(normal, (utility_vector.get_vector(origin, r.start_point))) + distance) / vd;
        if (distance > 0)
        {
            Point point_of_intersection = r.start_point + r.direction_vector * distance;
            i.intersected_primitive = this;
            i.distance = distance;
            i.point_of_intersection = point_of_intersection;
            return i;
        }
    }
    return i;
}