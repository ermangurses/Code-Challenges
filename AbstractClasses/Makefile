CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o List.o LinkedList.o
	$(CXX) $(FLAGS) driver.o LinkedList.o -o driver
driver.o: driver.cpp LinkedList.h
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
List.o: List.cpp List.h
	$(CXX) $(FLAGS) -c List.cpp -o List.o
LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) $(FLAGS) -c LinkedList.cpp -o LinkedList.o
clean:
	rm *.o driver

.PHONY: all clean
