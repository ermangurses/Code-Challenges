CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

driver: driver.o LinkedList.o
	$(CXX) $(FLAGS) driver.o LinkedList.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o
LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) $(FLAGS) -c LinkedList.cpp -o LinkedList.o
clean:
	rm *.o driver

.PHONY: all clean
