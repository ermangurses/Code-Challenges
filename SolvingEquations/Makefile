CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: Driver.o Solver.o
	$(CXX) $(FLAGS) Driver.o Solver.o -o driver
Driver.o: Driver.cpp Solver.h
	$(CXX) $(FLAGS) -c Driver.cpp -o Driver.o
Solver.o: Solver.cpp Solver.h
	$(CXX) $(FLAGS) -c Solver.cpp -o Solver.o
clean:
	rm *.o driver
 
.PHONY: all clean
