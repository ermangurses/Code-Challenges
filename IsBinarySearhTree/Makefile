driver: driver.o Tree.o
	clang++ -std=c++11 -stdlib=libc++ -Weverything driver.o Tree.o -o driver
driver.o: driver.cpp
	clang++ -std=c++11 -stdlib=libc++ -Weverything -c  driver.cpp -o driver.o
Tree.o: Tree.cpp Tree.h
	clang++ -std=c++11 -stdlib=libc++ -Weverything -c Tree.cpp -o Tree.o
clean:
	rm *.o driver
	 
