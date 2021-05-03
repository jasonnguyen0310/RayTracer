output: Point.o Vector.o Ray.o Sphere.o PGMOut.o Raytracer.o main.o 
	g++ -std=c++17 Point.o Vector.o Ray.o Sphere.o PGMOut.o Raytracer.o main.o -o a.out

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

Point.o: geometry/Point.cpp
	g++ -std=c++17 -c geometry/Point.cpp geometry/Point.hpp

Vector.o: geometry/Vector.cpp	
	g++ -std=c++17 -c geometry/Vector.cpp geometry/Vector.hpp

Ray.o: geometry/Ray.cpp
	g++ -std=c++17 -c geometry/Ray.cpp geometry/Ray.hpp
	
Sphere.o: scene/Sphere.cpp
	g++ -std=c++17 -c scene/Sphere.cpp scene/Sphere.hpp

PGMOut.o: image/PGMOut.cpp
	g++ -std=c++17 -c image/PGMOut.cpp image/PGMOut.hpp

Raytracer.o: tracer/Raytracer.cpp
	g++ -std=c++17 -c tracer/Raytracer.cpp tracer/Raytracer.hpp

clean:
	rm *.o a.out