/*
Sphere.cpp
Author: Jason Nguyen
May 2, 2021
*/

#include "Sphere.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Sphere::Sphere() : Primitive()
{
    radius = 0;
}


Intersection Sphere::intersections(Ray r)
{
    Intersection i;
    // To compute intersections, consider this article:
    // http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/
    // delta_{x,y,z} is the vector A-C
    Vector delta{r.start_point.x - origin.x,
                    r.start_point.y - origin.y,
                    r.start_point.z - origin.z};


    // Now we can use the formula from the link to calculate b and c. Note that we can omit a, because
    // ray.dot(ray)=1. This is, because we normalized it.
    double b{(delta.x * r.direction_vector.x +
                delta.y * r.direction_vector.y +
                delta.z * r.direction_vector.z) *
                2};

    double c{(delta.x * delta.x +
                delta.y * delta.y +
                delta.z * delta.z) -
                radius * radius};

    double discriminant{b * b - 4 * c};
    double distance;

    if (discriminant < 0)
    {
        distance = 0.0;
        Point point_of_intersection = r.start_point + r.direction_vector * distance;
        i.intersected_primitive = this;
        i.distance = distance;
        i.point_of_intersection = point_of_intersection;
    }
    else
    {
        double distance1 = (-b + sqrt(discriminant)) / 2;
        double distance2 = (-b - sqrt(discriminant)) / 2;
        if (distance1 > distance2)
        {
            distance = distance2;
        }
        else
        {
            distance = distance1;
        }
        
        Point point_of_intersection = r.start_point + r.direction_vector * distance;
        i.intersected_primitive = this;
        i.distance = distance;
        i.point_of_intersection = point_of_intersection;
    }

    return i;

}

