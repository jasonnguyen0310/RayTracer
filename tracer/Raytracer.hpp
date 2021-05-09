/*
Raytracer.hpp
Author: Jason Nguyen
May 2, 2021
*/

#include <vector>
#include "../geometry/Ray.hpp"
#include "../scene/Sphere.hpp"

#ifndef RAYTRACER_H
#define RAYTRACER_H

using namespace std;

class Raytracer
{
    public:
        Raytracer();

        // Creates vector for image 
        vector<vector<int>> to_raster(int resolution);
};

#endif /* RAYTRACER_H */