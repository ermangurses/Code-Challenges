CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o Stack.o
	$(CXX) $(FLAGS) driver.o Stack.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
Stack.o: Stack.cpp Stack.h
	$(CXX) $(FLAGS) -c Stack.cpp -o Stack.o
clean:
	rm *.o driver

.PHONY: all clean	 
