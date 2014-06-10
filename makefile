all: 
	g++ -std=c++11 `python-config --cflags` test.cpp `python-config --ldflags` -o test
	./test
