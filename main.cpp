#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "image/PGMOut.hpp"
#include "tracer/Raytracer.hpp"
#include "scene/Scene.hpp"
using namespace std;

int main(int, char *argv[]) {
    Scene scene{argv[1]};
    int resolution = static_cast<int>(strtol(argv[2], nullptr, 10));
    Raytracer raytracer{move(scene)};
    PGMOut().save(raytracer.to_raster(resolution));
    return 0;
}