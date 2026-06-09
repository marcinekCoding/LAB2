CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
LDFLAGS = -fsanitize=address,leak

.PHONY: all clean run

all: ring_buffer

ring_buffer: main.cpp ring_buffer.hpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o ring_buffer main.cpp

run: ring_buffer
	./ring_buffer

clean:
	rm -f ring_buffer
