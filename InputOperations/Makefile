CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o
	$(CXX) $(FLAGS) driver.o -o driver
driver.o: input_operations.cpp
	$(CXX) $(FLAGS) -c input_operations.cpp -o driver.o
clean:
	rm *.o driver

.PHONY: all clean
