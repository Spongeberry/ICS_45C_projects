F = -std=c++11
P = string_test

all: $P

string_test: Alloc.cpp Alloc.h String.h String.cpp string_test.cpp
	g++ $F Alloc.cpp String.cpp string_test.cpp -o string_test

clean:
	/bin/rm -f $P
