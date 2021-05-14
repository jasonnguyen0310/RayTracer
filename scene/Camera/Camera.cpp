/*
Camera.cpp
Author: Jason Nguyen
May 3, 2021
*/

#include "Camera.hpp"
#include <iostream>
using namespace std;

Camera::Camera(Point pos, Point viewport_center, double viewport_height, double viewport_width)
{
    camera_position = pos;
    Vector utility_vector;
    view_vector = utility_vector.get_vector(pos, viewport_center);
    Vector t(0,1,0);
    right_vector = (utility_vector.cross_product(view_vector, t)).normalize() * (viewport_width / 2.0);
    up_vector = (utility_vector.cross_product(right_vector, view_vector)).normalize() * ( viewport_height / 2.0);
}

Ray Camera::calculate_rays(double viewport_x_coordinate, double viewport_y_coordinate)
{
    Vector horizontal = right_vector * viewport_x_coordinate;
    Vector vertical = up_vector * viewport_y_coordinate;
    Vector direction =  view_vector + horizontal + vertical;
    Ray r(camera_position,direction.normalize());
    return r;
}