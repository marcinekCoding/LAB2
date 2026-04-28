CXXFLAGS = -Wall -Wextra -std=c++17

.PHONY: all clean

all: main

main: main.o
	g++ $(CXXFLAGS) -o main main.o

main.o: main.cpp
	g++ $(CXXFLAGS) -c -o main.o main.cpp

clean:	
	rm -f main.o main
