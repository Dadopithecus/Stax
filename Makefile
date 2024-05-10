ListTest : ListTest.o
	g++ -std=c++17 -g -o ListTest.exe ListTest.o

ListTest.o: ListTest.cc node.hh
	g++ -std=c++17 -g -c ListTest.cc 
