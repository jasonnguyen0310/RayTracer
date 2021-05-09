/*
Sphere.cpp
Author: Jason Nguyen
May 2, 2021
*/

#include "Sphere.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Sphere::Sphere()
{
    center = Point(0.0,0.0,0.0);
    radius = 0;
}

Vector Sphere::intersections(Ray r)
{

    // To compute intersections, consider this article:
    // http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/
    // delta_{x,y,z} is the vector A-C

    Vector delta{r.start_point.x - center.x,
                    r.start_point.y - center.y,
                    r.start_point.z - center.z};

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
    Vector vector;
    if (discriminant < 0)
    {
        vector.x = 11.0;
        vector.y = 11.0;
    }
    else
    {
        double distance1 = (-b + sqrt(discriminant)) / 2;
        double distance2 = (-b - sqrt(discriminant)) / 2;
        vector.x = distance1;
        vector.y = distance2;
    }
    return vector;

}
