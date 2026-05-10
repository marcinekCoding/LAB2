CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address -g
LDFLAGS=-fsanitize=address

.PHONY: all clean

all: l5

l5: main.cpp
	$(CXX) $(CXXFLAGS) -o l5 main.cpp $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp -D PART1

clean:
	rm -f *.o l5