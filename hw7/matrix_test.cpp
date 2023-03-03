#include <iostream>
using namespace std;

#include "Matrix.h"

template
    <typename T, typename FN>
void fill_with_fn(Array <T> & a, FN fn){
    for (int i = 0; i < a.length(); ++i)
        a[i] = fn(i);
}

template
    <typename T, typename FN>
void fill_with_fn(Matrix <T> & m, FN fn)
{    
    for (int i = 0; i < m.num_rows(); i++){
        for (int j = 0; j < m.num_cols(); j++){
            m[i][j] = fn(i, j);
        }
    }
}

void test_int_array(){
    Array<int> a{10};
    auto fn = []( int i ){ return i+1;};
    a.fill(int());
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
}

void test_double_array(){
    Array<double> a{10};
    auto fn = []( double i ){ return 1.1 * i;};
    a.fill(double());
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
    // fill with number 1.1 to 9.9 step 1.1
}

void test_char_array(){
    Array<char> a{26};
    auto fn = [&](int i){ return 'a' + i;};
    a.fill('a');
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
    // fill with letters A through Z
}

void test_int_matrix(){
    // define and use fill_with_fn(Matrix & m, auto fn)
    // define a lambda that builds a multiplication table
    Matrix<int> mat{5, 5};
    auto fn = [](int r, int c){ return (r + 1) * (c + 1); };
    mat.fill(int());
    fill_with_fn(mat, fn);
    cout << mat << endl;
    cout << endl;
}

void test_double_matrix(){
    // fill each cell with (row + 1) + (col + 1) / 100
    // e.g., matrix[0][0] = 1.01 matrix[9][9] = 10.10
    Matrix<double> mat{10, 10};
    auto fn = [](double r, double c){ return (r + 1) + (c + 1) / 100; };
    mat.fill(double());
    fill_with_fn(mat, fn);
    cout << mat << endl;
    cout << endl;
}

void test_char_matrix(){
    // fill each row with letters A through Z
    // repeat for each row
    Matrix<char> mat{5, 5};
    auto fn = [](int r, int c){ return 'A' + (r * 5 + c) % 26; };
    mat.fill('a');
    fill_with_fn(mat, fn);
    cout << mat << endl;
    cout << endl;
}


void test_exceptions(){
    try {
        //generate the exception in Array
        Array<int> a{10};
        a.fill(int());
        cout << a[10];
    }
    catch (std::string& e){
        cout << e << endl;
    }
    try {
        // generate the exception in Matrix with row
        Matrix<int> mat{5, 5};
        mat.fill(int());
        cout << mat[9][2];
    }
    catch (std::string& e){
        cout << e << endl;
    }
    try {
        // generate the exception in Matrix with col
        Matrix<int> mat{5, 5};
        mat.fill(int());
        cout << mat[2][9];
    }
    catch (std::string& e){
        cout << e << endl;
    }
}



void test_extras(){
    Matrix<int> m{10,10};
    Matrix<int> n{m}; // copy constructor
    Array<int> a{10};
    cout << &a << endl; // operator <<() for pointer to Array
}


#define N 1

int main(){
    for (int i = 1; i <= N; ++i ){
        test_int_array();
        test_double_array();
        test_char_array();
        test_int_matrix();
        test_double_matrix();
        test_char_matrix();
        test_exceptions();
        test_extras();
    }
}