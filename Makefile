output: Point.o Vector.o Ray.o Primitive.o Intersection.o Sphere.o Plane.o Scene.o Camera.o PGMOut.o Raytracer.o main.o 
	g++ -std=c++17 Point.o Vector.o Ray.o Primitive.o Intersection.o Sphere.o Plane.o Scene.o Camera.o PGMOut.o Raytracer.o main.o -o a.out

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

Point.o: geometry/Point.cpp
	g++ -std=c++17 -c geometry/Point.cpp geometry/Point.hpp

Vector.o: geometry/Vector.cpp	
	g++ -std=c++17 -c geometry/Vector.cpp geometry/Vector.hpp

Ray.o: geometry/Ray.cpp
	g++ -std=c++17 -c geometry/Ray.cpp geometry/Ray.hpp

Primitive.o: scene/primitive/Primitive.cpp
	g++ -std=c++17 -c scene/primitive/Primitive.cpp scene/primitive/Primitive.hpp

Intersection.o: scene/primitive/Intersection.cpp
	g++ -std=c++17 -c scene/primitive/Intersection.cpp scene/primitive/Intersection.hpp

Sphere.o: scene/primitive/Sphere.cpp
	g++ -std=c++17 -c scene/primitive/Sphere.cpp scene/primitive/Sphere.hpp

Plane.o: scene/primitive/Plane.cpp
	g++ -std=c++17 -c scene/primitive/Plane.cpp scene/primitive/Plane.hpp

Scene.o: scene/Scene.cpp
	g++ -std=c++17 -c scene/Scene.cpp scene/Scene.hpp

Camera.o: scene/Camera/Camera.cpp
	g++ -std=c++17 -c scene/Camera/Camera.cpp scene/Camera/Camera.hpp

PGMOut.o: image/PGMOut.cpp
	g++ -std=c++17 -c image/PGMOut.cpp image/PGMOut.hpp

Raytracer.o: tracer/Raytracer.cpp
	g++ -std=c++17 -c tracer/Raytracer.cpp tracer/Raytracer.hpp

clean:
	rm *.o a.out