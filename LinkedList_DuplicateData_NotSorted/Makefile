driver: clean driver.o LinkedList.o
	g++ driver.o LinkedList.o -o driver
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp -o LinkedList.o
clean:
	rm *.o driver
	 
