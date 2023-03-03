#include <iostream>
#include "ListNode.h"
using namespace std;

// define the static int counters used by report_allocations()
int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;

// put all other ListNode definitions below
List ListNode::list_from_string(const char* s){
    if (s == nullptr || s[0] == '\0')
        return nullptr;
    List temp_ptr;
    List head = new ListNode(s[0], nullptr);
    temp_ptr = head;
        
    for(int i = 1; s[i] != 0; i++){
        head -> next = new ListNode(s[i], nullptr);
        head = head -> next;
        }
    head = nullptr;
    return temp_ptr;
}


List ListNode::list_copy(List L){
    return !L ? nullptr : new ListNode(L -> data, list_copy(L -> next));
}

List ListNode::list_reverse(List L){
    List result = nullptr;
    for (List p = L; p != nullptr; p = p -> next)
        result = new ListNode(p -> data, result);
    return result;
}

List ListNode::list_append(List L1, List L2){
        if (!L1 && !L2) {
            return nullptr;
        }
        if (!L1)
            return list_copy(L2);
        if (!L2)
            return list_copy(L1);
        List Ltemp = list_copy(L1);
        list_last(Ltemp) -> next = list_copy(L2);
        return Ltemp;
    }

List ListNode::list_str(List haystack, List needle){
    if (needle == nullptr) {
        return haystack;
    }
    if (haystack == nullptr) {
        return nullptr;
    }
    List p1 = haystack;
    while (p1 != nullptr) {
        List p2 = needle;
        List p3 = p1;
        while (p2 != nullptr && p3 != nullptr && p2->data == p3->data) {
            p2 = p2->next;
            p3 = p3->next;
        }
        if (p2 == nullptr) {
            return p1;
        }
        p1 = p1->next;
    }
    return nullptr;
}

List ListNode::list_chr(List str, int c){
    for (; str != nullptr; str = str->next) {
        if (str->data == c) {
            return str;
        }
    }
    return nullptr;
}

List ListNode::list_nth(List str, int n){
    for (int i = 0; str != nullptr; i++, str = str->next) {
        if (i == n) {
            return str;
        }
    }
    return nullptr;
}

void ListNode::list_delete(List L)
{
    while (L != nullptr) {
        List next = L->next;
        delete L;
        L = next;
    }
}

void ListNode::print(ostream & out, List L){
    for (List p = L; p != nullptr; p = p->next) {
        out << p->data;
    }
}

int ListNode::list_difference(List L1, List L2){
    int count;
    for (count = 0; L1 != nullptr && L1 != L2; L1 = L1->next, ++count);
    return (L1 == nullptr) ? -1 : count;
}

List ListNode::list_last(List L){
    if (!L)
        return nullptr;
    List last_ptr = L;
    for (; L->next != nullptr; L = L->next){
        last_ptr = L->next;
    }
    return last_ptr;
}

int ListNode::list_cmp(List L1, List L2){
    for (; L1 != nullptr && L2 != nullptr; L1 = L1->next, L2 = L2->next)
    {
        if (L1->data < L2->data)
            return -1;
        else if (L1->data > L2->data)
            return 1;
    }
    
    if (L1 == nullptr && L2 == nullptr)
        return 0;
    else if (L1 == nullptr)
        return -1;
    else
        return 1;
}

int ListNode::list_ncmp(List L1, List L2, int n){
    for (int i = 0; i < n && L1 != nullptr && L2 != nullptr; i++, L1 = L1->next, L2 = L2->next)
    {
        if (L1->data < L2->data)
            return -1;
        else if (L1->data > L2->data)
            return 1;
    }
    
    if (n == 0 || (L1 == nullptr && L2 == nullptr))
        return 0;
    else if (L1 == nullptr)
        return -1;
    else
        return 1;
}

int ListNode::list_length(List L) {
    int count = 0;
    for (List p = L; p != nullptr; p = p->next) {
        ++count;
    }
    return count;
}