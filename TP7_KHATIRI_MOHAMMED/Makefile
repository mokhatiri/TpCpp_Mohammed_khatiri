CC = g++
CFLAGS = -Wall -std=c++17 -fsanitize=address -g
SOURCES = exo1.cpp exo2.cpp exo3.cpp exo4.cpp exo5.cpp exo6.cpp exo7.cpp
OBJECTS = $(SOURCES:.cpp=.o)  # Replace .cpp with .o
EXECUTABLES = $(SOURCES:.cpp=)  # Replace .cpp with nothing

all: $(EXECUTABLES)

# Link object files into executables
%: %.o
	$(CC) $(CFLAGS) $< -o $@

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLES)
	[ -e "test.txt" ] && rm test.txt
