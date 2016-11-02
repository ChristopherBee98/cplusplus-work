CXX = g++
CXXFLAGS = -Wall
lab4: Student.o
	$(CXX) $(CXXFLAGS) Student.o lab4.cpp -o lab4

Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp
