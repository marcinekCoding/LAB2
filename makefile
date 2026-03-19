CXX=g++

.PHONY: all clean

all: lab2

lab2: main.o vars.o libgreeter.a
	${CXX} -o lab2 main.o vars.o libgreeter.a

main.o: main.cpp
	${CXX} -c main.cpp -o main.o

vars.o: vars.cpp
	${CXX} -c vars.cpp -o vars.o

greeter.o: greeter.cpp
	${CXX} -c greeter.cpp -o greeter.o

rome.o: rome.cpp
	${CXX} -c -o rome.o  rome.cpp

libgreeter.a: greeter.o 
	ar rcs libgreeter.a greeter.o

librome.s: rome.o
	g++ -shared -o librome.so rome.o

clean:
	rm -f lab2 main.o vars.o greeter.o libgreeter.a