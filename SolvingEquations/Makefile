CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all:Driver.o MySolver.o
	$(CXX) $(FLAGS) Driver.o MySolver.o -o driver
Driver.o: Driver.cpp
	$(CXX) $(FLAGS) -c Driver.cpp -o Driver.o
MySolver.o: MySolver.cpp MySolver.h
	$(CXX) $(FLAGS) -c MySolver.cpp -o MySolver.o
clean:
	rm *.o driver
	 
.PHONY: all clean
