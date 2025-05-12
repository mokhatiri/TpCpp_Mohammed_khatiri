CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
OBJS = main.o Container.o Pod.o Server.o KubernetesCluster.o Cloud_Util.o

all: cloud

cloud: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Dependencies
main.o: main.cpp Cloud_Util.hpp KubernetesCluster.hpp CloudExceptions.hpp MetricLogger.hpp
Container.o: Container.cpp Container.hpp Resource.hpp
Pod.o: Pod.cpp Pod.hpp Container.hpp
Server.o: Server.cpp Server.hpp Resource.hpp CloudExceptions.hpp
KubernetesCluster.o: KubernetesCluster.cpp KubernetesCluster.hpp Server.hpp Pod.hpp CloudExceptions.hpp
Cloud_Util.o: Cloud_Util.cpp Cloud_Util.hpp KubernetesCluster.hpp CloudExceptions.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o cloud