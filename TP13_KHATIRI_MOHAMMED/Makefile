CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

EX1_SRCS = Ex1/main.cpp
EX1_HDRS = Ex1/Additionneur.hpp

EX4_SRCS = Ex4/main.cpp
EX4_HDRS = Ex4/Livre.hpp

all: exo1 exo2 exo3 exo4

exo1: $(EX1_SRCS) $(EX1_HDRS)
	$(CXX) $(CXXFLAGS) $(EX1_SRCS) -o $@

exo2: Ex2/main.cpp
	$(CXX) $(CXXFLAGS) Ex2/main.cpp -o $@

exo3: Ex3/main.cpp
	$(CXX) $(CXXFLAGS) Ex3/main.cpp -o $@

exo4: $(EX4_SRCS) $(EX4_HDRS)
	$(CXX) $(CXXFLAGS) $(EX4_SRCS) -o $@

clean:
	rm -f exo1 exo2 exo3 exo4 *.o