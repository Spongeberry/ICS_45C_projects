#include <iostream>
using namespace std;
#include "String.h"

void String::error(const char * msg) const
{
    cout << "ERROR: " << msg << endl;
}

bool String::in_bounds(int i) const
{
    return i >= 0 && i < ListNode::list_length(head);
}

// Define your other String methods below


    String::String(const char *s) : head(ListNode::list_from_string(s)) {}
    String::String(const String &s) : head(ListNode::list_copy(s.head)) {}
    String::String(String &&s) : head(s.head) { s.head = nullptr; }
    String &String::operator=(String &&s) {
        swap(head, s.head);
        return *this;
    }
    String &String::operator=(const String &s) {
        List tmp = ListNode::list_copy(s.head);
        ListNode::list_delete(head);
        head = tmp;
        return *this;
    }
    char &String::operator[](int index) {
        if (!in_bounds(index)) {
            error("Index out of bounds");
        }
        return ListNode::list_nth(head, index)->data;
    }
    size_t String::size() const {
        return ListNode::list_length(head);
    }
    String String::reverse() const {
        List reversed = ListNode::list_reverse(head);
        return String(reversed);
    }
    int String::indexOf(const char c) const {
        List found = ListNode::list_chr(head, c);
        return found == nullptr ? -1 : ListNode::list_difference(head, found);
    }
    int String::indexOf(const String &s) const {
        List found = ListNode::list_str(head, s.head);
        return found == nullptr ? -1 : ListNode::list_difference(head, found);
    }
    bool String::operator==(const String &s) const {
        return ListNode::list_cmp(head, s.head) == 0;
    }
    bool String::operator!=(const String &s) const {
        return ListNode::list_cmp(head, s.head) != 0;
    }
    bool String::operator>(const String &s) const {
        return ListNode::list_cmp(head, s.head) > 0;
    }
    bool String::operator<(const String &s) const {
        return ListNode::list_cmp(head, s.head) < 0;
    }
    bool String::operator<=(const String &s) const {
        return ListNode::list_cmp(head, s.head) <= 0;
    }
    bool String::operator>=(const String &s) const {
        return ListNode::list_cmp(head, s.head) >= 0;
    }
    String String::operator+(const String &s) const {
        List concatenated = ListNode::list_append(head, s.head);
        return String(concatenated);
    }
    String &String::operator+=(const String &s) {
        List tmp = ListNode::list_append(head, s.head);
        ListNode::list_delete(head);
        head = tmp;
        return *this;
    }
    void String::print(std::ostream &out) const {
        ListNode::print(out, head);
    }
    void String::read(std::istream &in) {

    head = nullptr;


    char c;
    while (in.get(c)) {
        if (isspace(c)) {

            break;
        }

        head = new ListNode(c, head);
    }

    head = ListNode::list_reverse(head);
} 

    String::~String() {
        ListNode::list_delete(head);
    }

ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}

String::String( List L):head(L){}