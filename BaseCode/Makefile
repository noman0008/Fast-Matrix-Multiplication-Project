# the compiler:
CC = g++

# compiler flags:
CFLAGS = -g -Wall 

# the build target executable

all:
	make test generator

test: Product.h Product.cpp test.cpp Matrix.hpp
	$(CC) $(CFLAGS) Product.cpp Product.h Matrix.hpp test.cpp -o test

generator: testdataGenerator.cpp Matrix.hpp 
	$(CC) $(CFLAGS) testdataGenerator.cpp Matrix.hpp -o generator

clean:
	rm -f *.o *~ test generator

