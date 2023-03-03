//#include <iostream>//

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "Rectangle.h"
using namespace std;

class Square : public Rectangle {
private:
    int width;

public:
    Square(int cx, int cy, string nm, int w) : Rectangle(cx, cy, nm, w, w){}

    double area(){
        return Rectangle::area();
    }

    void draw(){
        Rectangle::draw();
    }

    void print(){
        Rectangle::print();
    }
};




#endif

