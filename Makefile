output: Point.o Vector.o Ray.o Primitive.o Intersection.o Sphere.o Plane.o Scene.o Camera.o PGMOut.o Raytracer.o main.o 
	g++ -std=c++17 Point.o Vector.o Ray.o Primitive.o Intersection.o Sphere.o Plane.o Scene.o Camera.o PGMOut.o Raytracer.o main.o -o a.out

main.o: main.cpp
	g++ -std=c++17 -c -ggdb3 main.cpp

Point.o: geometry/Point.cpp
	g++ -std=c++17 -c -ggdb3 geometry/Point.cpp geometry/Point.hpp

Vector.o: geometry/Vector.cpp	
	g++ -std=c++17 -c -ggdb3 geometry/Vector.cpp geometry/Vector.hpp

Ray.o: geometry/Ray.cpp
	g++ -std=c++17 -c -ggdb3 geometry/Ray.cpp geometry/Ray.hpp

Primitive.o: scene/primitive/Primitive.cpp
	g++ -std=c++17 -c -ggdb3 scene/primitive/Primitive.cpp scene/primitive/Primitive.hpp

Intersection.o: scene/primitive/Intersection.cpp
	g++ -std=c++17 -c -ggdb3 scene/primitive/Intersection.cpp scene/primitive/Intersection.hpp

Sphere.o: scene/primitive/Sphere.cpp
	g++ -std=c++17 -c -ggdb3 scene/primitive/Sphere.cpp scene/primitive/Sphere.hpp

Plane.o: scene/primitive/Plane.cpp
	g++ -std=c++17 -c -ggdb3 scene/primitive/Plane.cpp scene/primitive/Plane.hpp

Scene.o: scene/Scene.cpp
	g++ -std=c++17 -c -ggdb3 scene/Scene.cpp scene/Scene.hpp

Camera.o: scene/Camera/Camera.cpp
	g++ -std=c++17 -c -ggdb3 scene/Camera/Camera.cpp scene/Camera/Camera.hpp

PGMOut.o: image/PGMOut.cpp
	g++ -std=c++17 -c -ggdb3 image/PGMOut.cpp image/PGMOut.hpp

Raytracer.o: tracer/Raytracer.cpp
	g++ -std=c++17 -c -ggdb3 tracer/Raytracer.cpp tracer/Raytracer.hpp

clean:
	rm *.o a.out