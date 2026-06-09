CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
LDFLAGS = -fsanitize=address,leak

.PHONY: all clean run

all: fixed_stack

fixed_stack: main.cpp fixed_stack.hpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o fixed_stack main.cpp

run: fixed_stack
	./fixed_stack

clean:
	rm -f fixed_stack
