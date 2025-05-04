CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: exo1 exo2 exo3

exo1 : main1.cpp
	$(CXX) $(CXXFLAGS) main1.cpp -o $@
exo2 : main2.cpp
	$(CXX) $(CXXFLAGS) main2.cpp -o $@
exo3 : main3.cpp
	$(CXX) $(CXXFLAGS) main3.cpp -o $@

clean:
	rm -f exo1 exo2 exo3 *.o

cleanall:
	rm -f exo1 exo2 exo3 *.o
	rm -f *.txt