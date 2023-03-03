#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

class Shape
{
    int centerX;
    int centerY;
    string name;

public:

    Shape( int cx, int cy, string nm):centerX(cx), centerY(cy), name(nm){}

    // prints name, cx, and cy in format Circle_0 at (cx, cy)
    void print(){
        cout << name << " at (" << centerX << ", " << centerY << ") area = " << area() << endl;
    }

    // returns the area of this shape
    virtual double area() = 0;

    // draws this shape to cout using character graphics
    virtual void draw() = 0;

    // in case any Shapes need to free resources
    virtual ~Shape() = default;
};


#endif