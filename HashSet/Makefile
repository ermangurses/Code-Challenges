CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

all: driver.o
	$(CXX) $(FLAGS) driver.o -o driver
driver.o: hashSetDriver.cpp
	$(CXX) $(FLAGS) -c hashSetDriver.cpp -o driver.o
clean:
	rm *.o driver

.PHONY: all clean
