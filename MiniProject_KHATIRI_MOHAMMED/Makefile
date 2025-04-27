CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
OBJS = main.o Container.o Pod.o Server.o KubernetesCluster.o Cloud_Util.o

all: cloud

cloud: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
canv
clean:
	rm -f *.o cloud