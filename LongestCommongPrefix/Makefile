CXX=g++
FLAGS=-std=c++11 -Wall -Wpedantic

driver: driver.o
	$(CXX) $(FLAGS) driver.o -o driver
driver.o: driver.cpp
	$(CXX) $(FLAGS) -c driver.cpp -o driver.o

clean:
	rm *.o driver

.PHONY: all clean	 
