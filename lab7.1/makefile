CXX=g++
CXXFLAGS=-std=c++20 -Wall -fsanitize=address,leak -g

LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l7

l7: main.cpp matrix.cpp 
	$(CXX) -o l7 main.cpp matrix.cpp 

clean:
	rm -f *.o l7