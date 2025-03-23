CXX = g++
CXXFLAGS = -Wall -std=c++11

all: movies

movies: main.o Movies.o Movie.o
	$(CXX) $(CXXFLAGS) -o movies main.o Movies.o Movie.o

main.o: main.cpp Movies.hpp Movie.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Movies.o: Movies.cpp Movies.hpp Movie.hpp
	$(CXX) $(CXXFLAGS) -c Movies.cpp

Movie.o: Movie.cpp Movie.hpp
	$(CXX) $(CXXFLAGS) -c Movie.cpp

clean:
	rm -f *.o movies
