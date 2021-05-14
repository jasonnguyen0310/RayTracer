/*
Scene.hpp
Author: Jason Nguyen
May 3, 2021
*/

#ifndef SCENE_H
#define SCENE_H

#include "primitive/Primitive.hpp"
#include "primitive/Intersection.hpp"
#include "primitive/Sphere.hpp"
#include "primitive/Plane.hpp"
#include "Camera/Camera.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>
#include <memory>


class Scene
{
    public:
        Camera camera;
        std::vector<std::unique_ptr<Primitive>> primitives;
        Scene() {}
        Scene(const std::string& filepath);
        std::optional<Intersection> find_intersection(Ray r);
};



#endif /* SCENE_H */