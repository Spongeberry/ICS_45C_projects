#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
using namespace std;

class Triangle : public Shape {
private:
    int base;
    int height;

public:
    Triangle(int cx, int cy, string nm, int b, int h) : Shape(cx, cy, nm), base(b), height(h) {}

    double area(){
        return height * base * 0.5;
    }

    void draw()
    {
        int offset = max(height, base);
        for (int row = 0; row < height; row += 2 )
        {
            for (int col = 0; col < (offset - row)/2; col++)
                cout << " ";
            for (int i = 0; i <= row; i++)
                cout << "*";
            cout << endl;
        }
    }

    void print(){
        Shape::print();
    }
};




#endif

