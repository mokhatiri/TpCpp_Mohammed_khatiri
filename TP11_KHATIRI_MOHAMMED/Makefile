CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

EX1_DIR = Ex1
EX2_DIR = Ex2
EX3_DIR = Ex3

# Exercise 1 sources
EX1_SRCS = $(EX1_DIR)/calculate.cpp $(EX1_DIR)/main.cpp
EX1_HDRS = $(EX1_DIR)/calculate.hpp $(EX1_DIR)/DivideByZeroException.hpp $(EX1_DIR)/InvalidOperationException.hpp

# Exercise 2 sources  
EX2_SRCS = $(EX2_DIR)/Inventory.cpp $(EX2_DIR)/main.cpp
EX2_HDRS = $(EX2_DIR)/Inventory.hpp $(EX2_DIR)/InsufficientStockException.hpp $(EX2_DIR)/NegativeQuantityException.hpp

# Exercise 3 sources
EX3_SRCS = $(EX3_DIR)/Stack.cpp $(EX3_DIR)/main.cpp
EX3_HDRS = $(EX3_DIR)/Stack.hpp $(EX3_DIR)/StackEmptyException.hpp $(EX3_DIR)/StackFullException.hpp

all: exo1 exo2 exo3

exo1: $(EX1_SRCS) $(EX1_HDRS)
	$(CXX) $(CXXFLAGS) $(EX1_SRCS) -o $@

exo2: $(EX2_SRCS) $(EX2_HDRS)
	$(CXX) $(CXXFLAGS) $(EX2_SRCS) -o $@

exo3: $(EX3_SRCS) $(EX3_HDRS)
	$(CXX) $(CXXFLAGS) $(EX3_SRCS) -o $@

clean:
	rm -f exo1 exo2 exo3 *.o