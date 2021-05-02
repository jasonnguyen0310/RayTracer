output: Point.o Vector.o Ray.o test.o
	g++ Point.o Vector.o Ray.o test.o -o a.out

test.o: test.cpp
	g++ -c test.cpp

Point.o: Point.cpp
	g++ -c Point.cpp Point.hpp

Vector.o: Vector.cpp	
	g++ -c Vector.cpp Vector.hpp

Ray.o: Ray.cpp
	g++ -c Ray.cpp Ray.hpp

clean:
	rm *.o a.out