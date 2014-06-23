all: 
	g++ `python-config --cflags | sed s/-Wstrict-prototypes//` test.cpp `python-config --ldflags` -o test
	./test
