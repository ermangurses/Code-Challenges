driver: driver.o Stack.o
	g++ driver.o Stack.o -o driver
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp -o Stack.o
clean:
	rm *.o driver
	 
