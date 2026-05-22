CXX=g++
CXXFLAGS=-std=c++17

.PHONY: all clean

all: l5

l5: main.o sensor.o
	$(CXX) $(CXXFLAGS) -o l5 main.o sensor.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp -D PART3

sensor.o: SensorCollection.cpp
	$(CXX) $(CXXFLAGS) -c -o sensor.o SensorCollection.cpp

clean:
	rm -f *.o l5