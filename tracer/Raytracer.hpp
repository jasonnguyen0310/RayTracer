/*
Raytracer.hpp
Author: Jason Nguyen
May 2, 2021
*/

#include <vector>
#include "../geometry/Ray.hpp"
#include "../scene/primitive/Sphere.hpp"
#include "../scene/Camera/Camera.hpp"
#include "../scene/Scene.hpp"

#ifndef RAYTRACER_H
#define RAYTRACER_H

using namespace std;

class Scene;
class Raytracer
{
    private:
        Scene scene;
    public:
        Raytracer(Scene s) : scene(move(s)) {}
        // Creates vector for image 
        vector<vector<int>> to_raster(int resolution);
};

#endif /* RAYTRACER_H */