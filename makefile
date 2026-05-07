g++ = CXX
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

.PHONY: all clean

all: main

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

clean:
	rm -f main.o main
