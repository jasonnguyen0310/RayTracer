#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "geometry/Ray.hpp"
#include "scene/Sphere.hpp"
#include "image/PGMOut.hpp"
#include "tracer/Raytracer.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    Raytracer tracer;
    PGMOut out;
    int resolution = atoi(argv[1]);
    out.save(tracer.to_raster(resolution));
    return 0;
}