CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic -g

all: driver.o
	$(CXX) $(FLAGS) driver.o -o driver
driver.o: deforestation.cpp
	$(CXX) $(FLAGS) -c deforestation.cpp -o driver.o
clean:
	rm *.o driver

.PHONY: all clean
