driver: driver.o Queue.o
	g++ driver.o Queue.o -o driver
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp -o Queue.o
clean:
	rm *.o driver
	 
