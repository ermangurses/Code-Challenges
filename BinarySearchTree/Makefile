CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o BSTree.o
	$(CXX) $(FLAGS) driver.o BSTree.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
BSTree.o: BSTree.cpp BSTree.h
	$(CXX) $(FLAGS) -c BSTree.cpp -o BSTree.o
clean:
	rm *.o driver
	 
.PHONY: all clean
