#Compiler and flags
CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic -g 

# Implementation and driver file names
IMPLEMENTATION=Variable
DRIVER=Driver

all: Driver.o Variable.o
	$(CXX) $(FLAGS) Driver.o Variable.o -o driver
Driver.o: Driver.cpp Variable.h
	$(CXX) $(FLAGS) -c Driver.cpp -o Driver.o
Variable.o: Variable.cpp Variable.h
	$(CXX) $(FLAGS) -c Variable.cpp -o Variable.o
clean:
	rm *.o driver
 
.PHONY: all clean
