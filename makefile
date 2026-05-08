g++ = CXX
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

.PHONY: all clean

all: main

main: main.o movieCollection.o
	$(CXX) $(CXXFLAGS) -o main main.o movieCollection.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

movieCollection.o: movieCollection.cpp
	$(CXX) $(CXXFLAGS) -c -o movieCollection.o movieCollection.cpp

clean:
	rm -f main.o main
