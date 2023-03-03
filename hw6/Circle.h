#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath> // for sqrt()
#include "Shape.h"
using namespace std;

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int cx, int cy, string nm, double r) : Shape(cx, cy, nm), radius(r) {}

    double area(){
        return 3.14159 * radius * radius;
    }

    void draw()
    {
        for (int row = -radius; row <= radius; row += 2)
        {
            for (int col = -radius; col <= radius; col++)
            {
                double distance = sqrt(col * col + row * row);
                if ( distance <= radius )
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }

    void print(){
        Shape::print();
    }
};




#endif

