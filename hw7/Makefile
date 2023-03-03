F = -std=c++11 -ggdb -Wall -Wextra -Werror -pedantic
P = matrix_test
H = Array.h Matrix.h 

def: $P 

matrix_test: matrix_test.cpp $H 
	g++ $F matrix_test.cpp -o matrix_test

clean:
	/bin/rm -rf $P matrix_test.dSYM