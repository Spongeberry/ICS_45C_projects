#include <iostream>
using namespace std;

#include "Picture.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

#define N_TESTS 10

void add_shapes(Picture & pic, int i, int param1, [[maybe_unused]] int param2)
{
    pic.add(new Circle(0, 0, "Circle_" + to_string(i), i * param1));
    pic.add(new Rectangle(0, 0, "Rectangle_" + to_string(i), i * param1, i * param2));
    pic.add(new Triangle(0, 0, "Triangle_" + to_string(i), i * param1, i * param2));
    pic.add(new Square(0, 0, "Square_" + to_string(i), i * param1));
    // incrementally add Rectangle, Triangle, then Square
    // pic.add(new Rectangle(0, 0, "Triangle_" + to_string(i),
    //          i * param1, i * param2));
}

int main()
{
    Picture collage;
    for ( int i = 1; i <= N_TESTS; ++i )
        add_shapes(collage, i, 2, 3);
    collage.print_all();
    return 0;
}