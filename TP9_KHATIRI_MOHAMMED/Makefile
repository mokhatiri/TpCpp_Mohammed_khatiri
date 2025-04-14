CXX = g++
CXXFLAGS = -std=c++17 -Wall
OBJS = main.o Account.o Savings_Account.o Checking_Account.o Trust_Account.o Account_Util.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Account.o: Account.cpp Account.hpp
	$(CXX) $(CXXFLAGS) -c Account.cpp

Savings_Account.o: Savings_Account.cpp Savings_Account.hpp
	$(CXX) $(CXXFLAGS) -c Savings_Account.cpp

Checking_Account.o: Checking_Account.cpp Checking_Account.hpp
	$(CXX) $(CXXFLAGS) -c Checking_Account.cpp

Trust_Account.o: Trust_Account.cpp Trust_Account.hpp
	$(CXX) $(CXXFLAGS) -c Trust_Account.cpp

Account_Util.o: Account_Util.cpp Account_Util.hpp
	$(CXX) $(CXXFLAGS) -c Account_Util.cpp

clean:
	rm -f *.o main
