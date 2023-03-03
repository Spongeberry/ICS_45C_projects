#include <iostream>
#define MAXLEN 128
using namespace std;

class String{
    char buf[MAXLEN];

    static int strlen( const char * s ){
        int i;
        for (i = 0; s[i] != '\0'; i++);
        return i;
    }

    static char * strcpy( char * dest, const char * src ){
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

    static char * strncpy( char * dest, const char * src, int n ){
        int i;
        for (i = 0; i < n && src[i] != '\0'; i++) {
            dest[i] = src[i];
        }
        for ( ; i < n; i++) {
            dest[i] = '\0';
        }
        return dest;
    }

    static char * strcat( char * dest, const char * src ){
        int dest_len = strlen(dest);
        int i;
        for (i = 0; src[i] != '\0' ; dest_len++, i++){
            dest[dest_len] = src[i];
        }
        dest[dest_len] = '\0';
        return dest;
    }


    static char * strncat( char * dest, const char * src, int n){
        int dest_len = strlen(dest);
        int i;
        for (i = 0; i < n && src[i] != '\0'; i++, dest_len++){
            dest[dest_len] = src[i];
        }
        dest[dest_len] = '\0';
        return dest;
    }

    static int strcmp( const char * left, const char * right){
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

    static int strncmp( const char * left, const char * right, int n){
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

    static void reverse_cpy( char * dest, const char * src){
        int src_len = strlen(src);
	    int src_index = src_len-1;
	    int dest_index = 0;
	    for ( ; dest_index < src_len;  ++dest_index,  --src_index  )
		    dest[dest_index] = src[src_index];
	    dest[dest_index] = '\0';
    }

    static char * strchr( char* str, char c){
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == c) {
                return &str[i];
            }
            i++;
            }
        return nullptr;
        }

    static char * strstr( char * haystack, const char * needle){
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

    static const char * strstr( const char * haystack, const char * needle){
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

public:
    /* all public methods must not go beyong buf[MAXLEN - 1] */

    // constructs this string from a C string, defaults to empty string
    explicit String( const char * s = ""){
        strncpy(buf, s, MAXLEN - 1);
    }
    // construct this string as a copy of string s
    String( const String & s){
        strncpy(buf, s.buf, MAXLEN - 1);
    }
    // assignment operator from one string, s, to this string
    String & operator = ( const String & s){
        if (this != &s)
            strncpy(buf, s.buf, MAXLEN - 1);
        return *this;
    }
    // allow indexing this string with notation s[i]
    char & operator [] ( int index ){
        return buf[index];
    }
    // returns the logical length of this string (# os chars up to '\0')
    size_t size(){
        return strlen(buf);
    }

    //returns a reversal of this string, does not modify this string
    String reverse(){
        String temp;
        reverse_cpy (temp.buf, this -> buf);
        return temp;
    }

    // returns index into this string for first occurance of c
    int indexOf( const char c ){
        for (int i = 0; i < MAXLEN; i++){
            if (buf[i] == c) {
                return i;
            }
        }
        return -1;
    }

    // returns index into this string for first occurance of s
    int indexOf( const String s){
        char * find = strstr(buf, s.buf);
        if (find == NULL){
            return -1;
        }
        return find - buf;
    }

    // relational operators for comparing this strings to another string
    bool operator == (const String s){
        return strcmp(buf, s.buf) == 0;
    }
    bool operator != (const String s){
        return strcmp(buf, s.buf) != 0;
    }
    bool operator > (const String s){
        return strcmp(buf, s.buf) > 0;
    }
    bool operator < (const String s){
        return strcmp(buf, s.buf) < 0;
    }
    bool operator <= (const String s){
        return strcmp(buf, s.buf) <= 0;
    }
    bool operator >= (const String s){
        return strcmp(buf, s.buf) >= 0;
    }

    // concatenate this and s to form a return string
    String operator + ( const String s){
        String temp;
        strncpy(temp.buf, buf, MAXLEN - 1);
        strncat(temp.buf, s.buf, MAXLEN - strlen(temp.buf) - 1);
        return temp;
    }

    // concatenate s onto the end of this string
    String & operator += (const String s){
        strncat(buf, s.buf, MAXLEN - strlen(buf) - 1);
        return *this;
    }

    // print this string, hint: use operator << to send buf to out
    void print( ostream & out){
        out << buf;
    }
    //read next word into this string
    //hint: use operator >> to read from in into buf
    void read( istream & in){
        in >> buf;
    }
    //destructor for this string, we won't need it yet...
    ~String(){}

private:
    // use in_ bounds for operator[] top do index checking
    bool in_bounds(int i)
    {
        return i >= 0 && i < strlen(buf);
    }
};

// inserter and extractor for string objects
// use the pattern I showed you for inserter and extractor
ostream & operator << (ostream & out, String s){
    s.print(out);
    return out;
}
istream & operator >> (istream & in, String & s){
    s.read(in);
    return in;
}