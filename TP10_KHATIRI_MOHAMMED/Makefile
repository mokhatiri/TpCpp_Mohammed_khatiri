CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGETS = maximum conteneur Paire Matrix

all: $(TARGETS)

maximum: maximum.cpp
	$(CXX) $(CXXFLAGS) -o maximum maximum.cpp

conteneur: conteneur.cpp
	$(CXX) $(CXXFLAGS) -o conteneur conteneur.cpp

Paire: Paire.cpp
	$(CXX) $(CXXFLAGS) -o Paire Paire.cpp

Matrix: Matrix.cpp
	$(CXX) $(CXXFLAGS) -o Matrix Matrix.cpp

clean:
	rm -f $(TARGETS)
