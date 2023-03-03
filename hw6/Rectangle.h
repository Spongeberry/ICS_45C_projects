#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
using namespace std;

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(int cx, int cy, string nm, int l, int w) : Shape(cx, cy, nm), length(l), width(w) {}

    double area(){
        return width * length;
    }

    void draw()
    {
        for ( int row = 0; row < width; row += 2)
        {
            for ( int col = 0; col < length; col++ )
                cout << "*";
            cout << endl;
        }
    }

    void print(){
        Shape::print();
    }
};




#endif

