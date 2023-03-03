#include <iostream>
#include <cassert>
using namespace std;
#include "String.h"
#include "Alloc.h"


void test_strdup(){
    const char* s1("Hello");
    char* duplicate1 = String::strdup(s1);
    assert(String::strcmp(s1, duplicate1) == 0);


    const char* s2("");
    char* duplicate2 = String::strdup(s2);
    assert(String::strcmp(s2, duplicate2) == 0);


    const char* s3("world");
    char* duplicate3 = String::strdup(s3);
    assert(String::strcmp(s3, duplicate3) == 0);


    std::cout << "All strdup tests passed." << std::endl;
}

void test_constructors_and_print()
{
    cout << "Constructor and operator << TESTS" << endl;

    String s("Hello World");
    cout << "\"" << s << "\"" << endl;
}

void test_assignments()
{
    cout << "Assignment TESTS" << endl;
    String str1("Hello");
    String str2("World");

    cout << "str1 before assignment:" << str1.buf << endl;
    cout << "str2 before assignment:" << str2.buf << endl;

    str1 = str2;

    cout << "str1 after assignment:" << str1.buf << endl;
    cout << "str2 after assignment:" << str2.buf << endl;

}

void test_relationals(){
    cout << "Relational TESTS" << endl;
    String s1("hello");
    String s2("world");
    String s3("hello");

    // Test operator ==
    assert(s1 == s3);
    assert(!(s1 == s2));

    // Test operator !=
    assert(s1 != s2);
    assert(!(s1 != s3));

    // Test operator >
    assert(s2 > s1);
    assert(!(s1 > s2));

    // Test operator <
    assert(s1 < s2);
    assert(!(s2 < s1));

    // Test operator <=
    assert(s1 <= s3);
    assert(s1 <= s2);
    assert(!(s2 <= s1));

    // Test operator >=
    assert(s3 >= s1);
    assert(s2 >= s1);
    assert(!(s1 >= s2));
}

void test_reverse(){
    cout << "Reverse Tests" << endl;

    String str1("hello");
    String reversed = str1.reverse();
    cout << reversed << endl;

    String str2("world");
    String reversed1 = str2.reverse();
    cout << reversed1 << endl;

    String str3("");
    String reversed2 = str3.reverse();
    cout << reversed2 << endl;
}

void test_concatenate(){
    cout << "Concatenate TESTS" << endl;

    String s1("Hello");
    String s2(" World");

    String s3 = s1 + s2;
    cout << s3 << endl;

    s1 += s2;
    cout << s1 << endl;

    String s5("");
    String s4("");
    s4 = s4 + s5;
    cout << s4 << endl;
}

void test_indexOf(){
    cout << "indexOf TESTS" << endl;

    String str1("Hello");
    assert(str1.indexOf('o') == 4);
    assert(str1.indexOf('z') == -1);

    String str2("world");
    assert(str1.indexOf(str2) == -1);

    String str3("Hell");
    assert(str1.indexOf(str3) == 0);

    String str4("lo");
    assert(str1.indexOf(str4) == 3);
}

void test_reverse_cpy()
{
 cout << "Testing reverse_cpy" << endl;
 char A[100] = "Hello World";
 char R[100];
 String::reverse_cpy(R, A);
 cout << "|" << A << "| reversed is |" << R << "|" << endl;
 cout << "strlen(" << A << ") is " << String::strlen(A) << endl;
 cout << "strlen(" << R << ") is " << String::strlen(R) << endl;
}

int main(){
    test_constructors_and_print();
    test_assignments();
    test_relationals();
    test_reverse();
    test_concatenate();
    test_indexOf();
    test_reverse_cpy(); 
    test_strdup();
    Alloc::report_allocations();
    return 0;
}