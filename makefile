all: 
	g++ `python-config --cflags` test.cpp `python-config --ldflags` -o test
	./test
