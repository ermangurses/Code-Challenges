CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o Queue.o
	$(CXX) $(FLAGS) driver.o Queue.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
Queue.o: Queue.cpp Queue.h
	$(CXX) $(FLAGS) -c Queue.cpp -o Queue.o
clean:
	rm *.o driver

.PHONY: all clean	 
