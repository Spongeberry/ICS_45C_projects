#ifndef ARRAY_H
#define ARRAY_H

#include <iomanip>
using namespace std;

template <typename T>
class Array
{
    int len;
    T * buf;

public:

    Array(int new_len): len(new_len), buf(new T[len]){
        fill(T());
    }

    int length(){
        return len;
    }

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
    
    T & operator [] (int index){
        if (!in_bounds(index)) {
            throw string("array index out of bounds!");
        }
        return buf[index];
    }

    // You must define correct copy constructor to pass
    Array(const Array & a): len(a.len), buf(new T[a.len]){
        for (int i =0; i < len; i++){
            buf[i] = a.buf[i];
        }
    }

    //leave this deleted so it's not used accidentally
    Array & operator =(Array & a) = delete;

    void fill(T val){
        for (int i = 0; i < len; ++i)
            buf[i] = val;
    }

    void print(ostream & out) const{
        for ( int i = 0; i < len; ++i)
                    // set the field width to 8 spaces
            out << setw(8)
                    // set decimal precision to 2 digits for real numbers
                << setprecision(2)
                    // use fixed point, not floating point for real numbers
                << fixed
                    // right justify the number within the field width
                << right
                    // print the value at buf[i]
                << buf[i];
    }

    friend ostream & operator << ( ostream & out, const Array & a){
        a.print(out);
        return out;
    }

    friend ostream & operator << ( ostream & out, const Array * a){
        out << *a;
        return out;
    }

    ~Array(){delete[] buf;}

};

#endif