XX = g++
CXXFLAGS = -Wall
money: Money.o
	$(CXX) $(CXXFLAGS) Money.o moneyTest.cpp -o moneyTest
Money.o: Money.cpp Money.h
	$(CXX) $(CXXFLAGS) -c Money.cpp
