CXX = g++
CXXFLAGS = -Wall

proj4: Monster.o Ben.o Pyronite.o Crystalsapien.o Game.o
	$(CXX) $(CXXFLAGS) Ben.o Game.o Monster.o Pyronite.o Crystalsapien.o proj4.cpp -o proj4

Crystalsapien.o: Crystalsapien.cpp Crystalsapien.h
	$(CXX) $(CXXFLAGS) -c Crystalsapien.cpp

Monster.o: Monster.cpp Monster.h
	$(CXX) $(CXXFLAGS) -c Monster.cpp

Pyronite.o: Pyronite.cpp Pyronite.h
	$(CXX) $(CXXFLAGS) -c Pyronite.cpp

Ben.o: Ben.cpp Ben.h
	$(CXX) $(CXXFLAGS) -c Ben.cpp

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

clean:
	rm *.o
	rm *~
run:
	./proj4
