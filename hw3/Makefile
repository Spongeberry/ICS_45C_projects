F = -std=c++11 -ggdb
P = string_test standard_main

all: $P

string_test: string_test.cpp String.h
	g++ $F string_test.cpp -o string_test

standard_main: standard_main.cpp String.h
	g++ $F standard_main.cpp -o standard_main

clean:
	/bin/rm -f $P