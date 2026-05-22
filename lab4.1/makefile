CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3: main.cpp subtask.cpp task.cpp
	$(CXX) -o l3 main.cpp subtask.cpp task.cpp



clean:
	rm -f *.o l3