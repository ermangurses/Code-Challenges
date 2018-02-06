driver: driver.o BSTree.o
	g++ driver.o BSTree.o -o driver
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
BSTree.o: BSTree.cpp BSTree.h
	g++ -c BSTree.cpp -o BSTree.o
clean:
	rm *.o driver
	 
