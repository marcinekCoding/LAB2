CXX=g++
CXXFLAGS=-std=c++17

.PHONY: all clean

all: l5

l5: main.cpp
	$(CXX) $(CXXFLAGS) -o l5 main.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp -D PART2

clean:
	rm -f *.o l5