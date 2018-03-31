CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o Tree.o
	$(CXX) $(FLAGS) driver.o Tree.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
Tree.o: Tree.cpp Tree.h
	$(CXX) $(FLAGS) -c Tree.cpp -o Tree.o
clean:
	rm *.o driver
	
.PHONY: all clean
