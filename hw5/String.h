#include <iostream>
#include "ListNode.h"


class String{

public:

    // constructs this string from a C string
    String( const char * s = "");

    // construct this string as a copy of string s
    String( const String & s);

    //construct this string by moving from dying string s
    String( String && s);

    //assignment to this string by moving from dying string s
    String & operator = (String && s);

    // assignment operator from one string, s, to this string
    String & operator = ( const String & s);

    // allow indexing this string with notation s[i]
    char & operator [] ( int index );

    // returns the logical length of this string
    size_t size() const;

    //returns a reversal of this string, does not modify this string
    String reverse() const;

    // returns index into this string for first occurance of c
    int indexOf( const char c ) const;

    // returns index into this string for first occurance of s
    int indexOf( const String & s) const;

    // relational operators for comparing this strings to another string
    bool operator == (const String & s) const;
    bool operator != (const String & s) const;
    bool operator > (const String & s) const;
    bool operator < (const String & s) const;
    bool operator <= (const String & s) const;
    bool operator >= (const String & s) const;

    // concatenate this and s to form a return string
    String operator + ( const String & s) const;

    // concatenate s onto the end of this string
    String & operator += (const String & s);

    // print this string, hint: use operator << to send buf to out
    void print( ostream & out) const;

    //read next word into this string
    //hint: use operator >> to read from in into buf
    void read( istream & in );

    //destructor for this string
    ~String();

private:

    // construct this string using a given linked list
    String( List L);

    bool in_bounds(int i) const;
    void error(const char * msg) const;

    List head;

    // DO NOT add any other data members

};

ostream & operator << ( ostream & out, const String & s );
istream & operator >> ( istream & in, String & s);