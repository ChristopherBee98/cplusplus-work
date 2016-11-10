CXX = g++
CXXFLAGS = -Wall

inherit1: Shape.o Rectangle.o Triangle.o
	  $(CXX) $(CXXFLAGS) Shape.o Rectangle.o Triangle.o inherit1.cpp -o inherit1

Shape.o: Shape.cpp Shape.h
	$(CXX) $(CXXFLAGS) -c Shape.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CXX) $(CXXFLAGS) -c Rectangle.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CXX) $(CXXFLAGS) -c Triangle.cpp

clean:
	rm *.o
	rm *~
run:
	./inherit1