F = -std=c++20 -ggdb -Wall -Wextra -Werror -pedantic
P = picture_test
H = Shape.h Circle.h Square.h Triangle.h Rectangle.h Picture.h

def: $P

picture_test:picture_test.cpp $H
	g++ $F picture_test.cpp -o picture_test

clean:
	/bin/rm -rf $P picture_test.dSYM