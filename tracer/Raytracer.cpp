/*
Raytracer.cpp
Author: Jason Nguyen
May 2, 2021
*/

#include "Raytracer.hpp"
#include <cmath>
#include <iostream>
using namespace std;
Raytracer::Raytracer()
{

}

vector<vector<int>> Raytracer::to_raster(int resolution)
{
    vector<vector<int>> image(resolution);
    double viewport_scale_factor{resolution == 1 ? 1 : 2. / resolution};
    double viewport_shift{1 - 1. / resolution};

    // The camera is located at (x=0;y=0;z=5).
    Point camera{0, 0, 5};

    // And there is a sphere at (0;0;-5) with radius 1.
    Sphere sphere(Point(0,0,-5), 1);

    for (int y_pixel = 0; y_pixel < resolution; ++y_pixel) {
        // To get the ray, we need the viewport coordinates. This is the y coordinate...
        double viewport_y_coordinate{y_pixel * viewport_scale_factor - viewport_shift};
        for (int x_pixel = 0; x_pixel < resolution; ++x_pixel) {
            // ... and the x coordinate.
            double viewport_x_coordinate{x_pixel * viewport_scale_factor - viewport_shift};

            // Now we get the vector from the camera to the viewport.
            Vector ray_direction{viewport_x_coordinate - camera.x,
                                    viewport_y_coordinate - camera.y,
                                    -camera.z};

            // And we want to make sure to normalize the ray we want to trace to a length of 1, because this will
            // simplify many computations.
            double ray_length = sqrt(ray_direction.x * ray_direction.x +
                                     ray_direction.y * ray_direction.y +
                                     ray_direction.z * ray_direction.z);
            ray_direction.x /= ray_length;
            ray_direction.y /= ray_length;
            ray_direction.z /= ray_length;

            Ray r(camera,ray_direction);
            Vector v = sphere.intersections(r);
            double distance;
            if (v.x > v.y)
            {
                distance = v.y;
            }
            else
            {
                distance = v.x;
            }
            double brightness = 10 - distance;
            
            if (brightness < 0) brightness = 0;
            int pixel_brightness = static_cast<int>(brightness * 255);

            image[y_pixel].push_back(pixel_brightness);
        }
    }

    return image;
}
