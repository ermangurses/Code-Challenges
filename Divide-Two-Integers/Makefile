CXX=g++
FLAGS=-std=c++11 -Wall -Wpedantic

all: driver.o Divide.o
	$(CXX) $(FLAGS) driver.o Divide.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
Divide.o: Divide.cpp Divide.h
	$(CXX) $(FLAGS) -c Divide.cpp -o Divide.o
clean:
	rm *.o driver

.PHONY: all clean	 
