CXX = g++
CXXFLAGS = -std=c++20 -Wall -fsanitize=address -g
LDFLAGS = -fsanitize=address

.PHONY: all clean

all: l7

l7: main.cpp 
	$(CXX) $(CXXFLAGS) -o l7 main.cpp

clean:
	rm -f *.o l7