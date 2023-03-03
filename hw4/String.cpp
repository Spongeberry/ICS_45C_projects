#include <iostream>
using namespace std;
#include "Alloc.h"
#include "String.h"



    int String::strlen( const char * s ){
        int i;
        for (i = 0; s[i] != '\0'; i++);
        return i;
    }

    char * String::strcpy( char * dest, const char * src ){
        int i;
        for (i = 0; i <= strlen(src); i++){
            dest[i] = '\0';
        }
        for (i = 0; src[i] != '\0'; i++){
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return dest;
    }

    char * String::strncpy( char * dest, const char * src, int n ){
        int i;
        for (i = 0; i < n && src[i] != '\0'; i++) {
            dest[i] = src[i];
        }
        for ( ; i < n; i++) {
            dest[i] = '\0';
        }
        return dest;
    }

    char * String::strcat( char * dest, const char * src ){
        int dest_len = strlen(dest);
        int i;
        for (i = 0; src[i] != '\0' ; dest_len++, i++){
            dest[dest_len] = src[i];
        }
        dest[dest_len] = '\0';
        return dest;
    }


    char * String::strncat( char * dest, const char * src, int n){
        int dest_len = strlen(dest);
        int i;
        for (i = 0; i < n && src[i] != '\0'; i++, dest_len++){
            dest[dest_len] = src[i];
        }
        dest[dest_len] = '\0';
        return dest;
    }

    int String::strcmp( const char * left, const char * right){
        int i = 0;
        while (left[i] != '\0' && right[i] != '\0'){
            if (left[i] < right[i]){
                return -1;
            } else if (left[i] > right[i]){
                return 1;
            }
            i++;
        }
        if (left[i] == '\0' && right[i] == '\0'){
            return 0;
        } else if (left[i] == '\0'){
            return -1;
        } else {
            return 1;
        }
    }

    int String::strncmp( const char * left, const char * right, int n){
        int i = 0;
        while (i < n && left[i] != '\0' && right[i] != '\0') {
        if (left[i] < right[i]) {
        return -1;
        } else if (left[i] > right[i]) {
        return 1;
        }
        i++;
    }
    if (i == n) {
        return 0;
    }
    if (left[i] == '\0' && right[i] == '\0') {
        return 0;
    } else if (left[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
    }

    void String::reverse_cpy( char * dest, const char * src){
        int length = strlen(src);
        int i;
        for (i = 0; i < length; i++)
            dest[i] = src[length - i - 1];
        dest[length] = '\0';
    }

    char * String::strchr( char* str, char c){
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == c) {
                return &str[i];
            }
            i++;
            }
        return nullptr;
        }

    char * String::strstr( char * haystack, const char * needle){
        int i, j;
        int haystack_len = strlen(haystack);
        int needle_len = strlen(needle);

        for (i = 0; i < haystack_len - needle_len + 1; i++) {
            for (j = 0; j < needle_len; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
            }
            }
            if (j == needle_len) {
                return &haystack[i];
            }
        }
        return nullptr;
    }

    const char * String::strstr( const char * haystack, const char * needle){
        int i, j;
        int haystack_len = strlen(haystack);
        int needle_len = strlen(needle);

        for (i = 0; i < haystack_len - needle_len + 1; i++) {
            for (j = 0; j < needle_len; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle_len) {
                return &haystack[i];
            }
        }
        return nullptr;
    }

    char* String::strdup(const char* s){
        int len = strlen(s);
        char *dup = Alloc::new_char_array(len + 1);
        strcpy(dup, s);
        return dup;
    }

    // constructs this string from a C string, defaults to empty string
    String::String( const char * s){
        buf = strdup(s);
    }

    // construct this string as a copy of string s
    String::String( const String & s){
        buf = strdup(s.buf);
    }

    String::String( String&& s){
        buf = s.buf;
        s.buf = nullptr;
    }
    // assignment operator from one string, s, to this string
    String & String::operator = ( const String & s){
        if (this != &s){
             Alloc::delete_char_array(buf);
            buf = strdup(s.buf);
        }
        return *this;
    }

    String & String::operator = (String&& s){
        if(this != &s){
            Alloc::delete_char_array(buf);
            buf = s.buf;
            s.buf = nullptr;
        }
        return *this;
    }
    // allow indexing this string with notation s[i]
    char & String::operator [] ( int index ){
        return buf[index];
    }

    // returns the logical length of this string (# os chars up to '\0')
    size_t String::size(){
        return strlen(buf);
    }

    //returns a reversal of this string, does not modify this string
    String String::reverse(){
        int length = strlen(buf);
        char *temp = Alloc::new_char_array(length + 1);
        reverse_cpy(temp, buf);
        String reversed(temp);
        Alloc::delete_char_array(temp);
        return reversed;
    }

    // returns index into this string for first occurance of c
    int String::indexOf( const char c ){
        for (int i = 0; i < strlen(buf); i++){
            if (buf[i] == c) {
                return i;
            }
        }
        return -1;
    }

    // returns index into this string for first occurance of s
    int String::indexOf( const String & s){
        char * find = strstr(buf, s.buf);
        if (find == NULL){
            return -1;
        }
        return find - buf;
    }

    // relational operators for comparing this strings to another string
    bool String::operator == (const String & s){
        return strcmp(buf, s.buf) == 0;
    }
    bool String::operator != (const String & s){
        return strcmp(buf, s.buf) != 0;
    }
    bool String::operator > (const String & s){
        return strcmp(buf, s.buf) > 0;
    }
    bool String::operator < (const String & s){
        return strcmp(buf, s.buf) < 0;
    }
    bool String::operator <= (const String & s){
        return strcmp(buf, s.buf) <= 0;
    }
    bool String::operator >= (const String & s){
        return strcmp(buf, s.buf) >= 0;
    }

    // concatenate this and s to form a return string
    String String::operator + ( const String & s){
        int length1 = strlen(buf);
        int length2 = strlen(s.buf);
        char* newBuf = Alloc::new_char_array(length1 + length2 + 1);

        strcpy(newBuf, buf);
        strcat(newBuf, s.buf);

        String newString(newBuf);
        Alloc::delete_char_array(newBuf);

        return newString;
    }

    // concatenate s onto the end of this string
    String & String::operator += (const String & s){
        int length1 = strlen(buf);
        int length2 = strlen(s.buf);
        char* newBuf = Alloc::new_char_array(length1 + length2 + 1);

        strcpy(newBuf, buf);
        strcat(newBuf, s.buf);

        Alloc::delete_char_array(buf);
        buf = newBuf;

        return *this;
    }

    // print this string, hint: use operator << to send buf to out
    void String::print( ostream & out) const {
        out << buf;
    }
    //read next word into this string
    //hint: use operator >> to read from in into buf
    void String::read( istream & in){
        in >> buf;
    }
    //destructor for this string, we won't need it yet...
    String::~String(){
        Alloc::delete_char_array(buf);
        buf = nullptr;
    }


    // use in_ bounds for operator[] top do index checking
    bool String::in_bounds(int i)
    {
        return i >= 0 && i < strlen(buf);
    }


// inserter and extractor for string objects
// use the pattern I showed you for inserter and extractor
ostream & operator << (ostream & out, const String & s){
    s.print(out);
    return out;
}

istream & operator >> (istream & in, String & s){
    s.read(in);
    return in;
}
