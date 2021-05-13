/*
Camera.hpp
Author: Jason Nguyen
May 3, 2021
*/

#ifndef CAMERA_H
#define CAMERA_H

#include "../../geometry/Point.hpp"
#include "../../geometry/Ray.hpp"
#include "../../geometry/Vector.hpp"

class Camera
{

    public:
        Point camera_position;
        Vector view_vector;
        Vector up_vector;
        Vector right_vector;
        Camera() {}
        Camera(Point pos, Point viewport_center, double height, double width);
        Ray calculate_rays(double viewport_x_coordinate, double viewport_y_coordinate);
};


#endif /* CAMERA_H */