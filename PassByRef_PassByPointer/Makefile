CXX=g++
FLAGS=-std=c++11 -stdlib=libc++ -Wall -Wpedantic

driver: driver.o
	$(CXX) $(FLAGS) driver.o  -o driver
driver.o: reference_pointer.cpp
	$(CXX) $(FLAGS) -c reference_pointer.cpp -o driver.o
clean:
	rm *.o driver
	 
.PHONY: all clean
