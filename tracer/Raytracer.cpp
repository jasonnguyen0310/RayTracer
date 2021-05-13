/*
Raytracer.cpp
Author: Jason Nguyen
May 2, 2021
*/

#include "Raytracer.hpp"
#include <cmath>
#include <iostream>
using namespace std;

vector<vector<int>> Raytracer::to_raster(int resolution)
{
    vector<vector<int>> image(resolution);
    double viewport_scale_factor{resolution == 1 ? 1 : 2. / resolution};
    double viewport_shift{1 - 1. / resolution};

    for (int y_pixel = resolution - 1; y_pixel >= 0; --y_pixel) {
        // To get the ray, we need the viewport coordinates. This is the y coordinate...
        double viewport_y_coordinate{y_pixel * viewport_scale_factor - viewport_shift};

        for (int x_pixel = 0; x_pixel < resolution; ++x_pixel) {
            // ... and the x coordinate.
            double viewport_x_coordinate{x_pixel * viewport_scale_factor - viewport_shift};

            Ray r = scene.camera.calculate_rays(viewport_x_coordinate, viewport_y_coordinate);

            std::optional<Intersection> i = scene.find_intersection(r);

            int brightness;
            
            if (i.has_value())
            {
                double distance{i->distance};
                distance = distance < 1 ? 1 : distance;
                brightness = static_cast<int>(1 / sqrt(distance) * 255);
            }
            else
            {
                brightness = 0;
            }
            
            image[y_pixel].push_back(brightness);
            
        }
        
    }

    return image;
}
