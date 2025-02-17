CC = g++
CFLAGS = -Wall -std=c++17
SOURCES = exo1.cpp exo2.cpp exo3.cpp exo4.cpp exo5.cpp exo6.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = $(SOURCES:.cpp=)  # Remove .cpp extension

all: $(EXECUTABLES)

# Rule to compile each executable separately
%: %.o
	$(CC) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLES)
