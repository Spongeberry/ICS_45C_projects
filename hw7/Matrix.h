#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
#include "Array.h"

template
    <typename T>
class Matrix{
    int rows, cols;
    Array< Array<T>* > matrix;
    // this will change to Array < Array<int> * > matrix;
    // then finally will be Array < Array<T> * > matrix;

public:
    
    // most of class Matrix is unimplemented

    Matrix( int new_rows, int new_cols): rows(new_rows), cols(new_cols), matrix(new_rows){
        for (int i = 0; i < rows; i++){
            matrix[i] = new Array<T>(cols);}
    }

    // You must define correct copy constructor to pass
    Matrix( Matrix & a): rows(a.rows), cols(a.cols), matrix(a.rows){
        for (int i = 0; i < rows; i++){
            matrix[i] = new Array<T>(*a.matrix[i]);
        }
    }

    //leave this deleted it's not used accidentally
    Matrix & operator = (Matrix & a) = delete;

    int num_rows(){
        return rows;
    }

    int num_cols(){
        return cols;
    }

    void fill(T val){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                (*matrix[i])[j] = val;
            }
        } // delete this dummy statement
    }

    bool in_bounds(int row, int col) const {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    Array<T> & operator[](int row) {
        if (!matrix.in_bounds(row)) {
            throw string("matrix index out of bounds!");
        }
        return *matrix[row];
    }

    void print(ostream & out){
        for (int i = 0; i < rows; i++) {
            out << (*matrix[i]);
            out << endl;
        }
    }

    friend ostream & operator << (ostream & out, Matrix & m){
        m.print(out);
        return out;
    }

    ~Matrix(){
        for (int i = 0; i < rows; i++)
            delete matrix[i];
    }
};

#endif