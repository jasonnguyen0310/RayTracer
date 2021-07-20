# RayTracer

# What is a raytracer

Raytracing is a technique to generate photorealistic pictures on your computer.
Let us recap first how regular 3D rendering techniques work, as they are used in
video games: in video games your scene is represented with millions of triangles,
which are then projected onto a two dimensional surface. This can be realized
very efficiently on hardware, because the amount work that has to be done for
every polygon is (relatively) simple and can be easily parallelized for a GPU.
Raytracing in contrast represents the scene with geometric objects, like planes
or spheres. Then, for every pixel on your screen, a ray is cast through the scene.
Then the raytracer calculates with analytical geometry, whether a given ray
intersects with any object of the scene. Using an intersection as start point for
new rays you can then trace rays to all light sources, to determine the brightness
of the object. Or if the object has a reflective surface, you calculate the rays
for reflections. You might have heard that modern nVidia GPUs have built-in
raytracing support and that there are some games which make use of that.
Over the next few assignments, you will build a raytracer step by step, with
every assignment being a checkpoint. It is important to complete all assignments,
as the next assignment will build on top of the previous one.
