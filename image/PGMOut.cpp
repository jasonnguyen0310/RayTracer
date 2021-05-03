/*
PGMOut.cpp
Author: Jason Nguyen
May 2, 2021
*/

#include "PGMOut.hpp"
#include <iostream>
using namespace std;

PGMOut::PGMOut()
{

}

void PGMOut::save(vector<vector<int>> image)
{
    cout << "P2\n"; // Magic PBM bytes
    cout << image.size() << ' ' << image[0].size() << '\n';
    cout << "255\n"; // This means that 1 should be displayed as white.

    // Our viewport is in the range [-1;1] in both x in y direction. To convert a pixel into a viewport
    // coordinate, we need to scale it first by (coordinate * 2 / resolution). However, if the resolution
    // is for example 2x2, we don't want rays at the four corners (-1;-1), (-1;1), (1;-1) and (1;1). If the
    // viewport is divided by for pixels, is is a square subdivided by four squares. We want to cast a ray
    // through the middle of each square:
    //
    //  (-1;1) x-+-x (1;1)
    //         |o|o|
    //         +-+-+
    //         |o|o|
    // (-1;-1) x-+-x (-1;1)
    //
    // In this 2x2 viewport, the 'x' are the corners, and the 'o' are the rays we want to trace. To center
    // them, we need to add to them 1/resolution. In the case of resolution=2, this is 0.5.
    //
    // So to scale we do do the same thing for the and y value. For resolution=4, the desired rays are at
    // the coordinates {-0.75, -0.25, 0.25, 0.75} in both x and y direction. The pixel coordinates are in
    // the interval [0;3]. We multiply this with 2/resolution, which scales this value to interval [0;1.5].
    // now we subtract 1 and add 1/resolution to scale it to the interval [-0.75;0.75]. This works for odd
    // and even numbers, except 1, which needs special case handling.
    for (int row = 0; row < image.size(); row++)
    {
        for (int column = 0; column < image[row].size(); column++)
        {
            cout << image[row][column] << " ";
        }
        cout << '\n';
    }  
}