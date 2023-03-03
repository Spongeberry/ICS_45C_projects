#ifndef PICTURE_H
#define PICTURE_H

#include <string>
#include <iostream>
using namespace std;
#include "Shape.h"

class Picture
{
    struct ListNode
    {
        Shape * data;
        ListNode * next;

        ListNode(Shape * new_data, ListNode * new_next) : data(new_data), next(new_next){}
    };

    ListNode * head;

public:

    // construct this picture as empty
    Picture():head(nullptr){}

    // adds the shape to this picture
    // shape must be allocated with new
    // picture becomes the owner of the shape resource
    void add(Shape * sp){
        ListNode* new_node = new ListNode(sp, nullptr);
        if (head == nullptr) {
            head = new_node;
        } else {
            ListNode* current = head;
            for (;current -> next != nullptr; current = current -> next){}
            current -> next = new_node;
        }
    }

    // returns the sum of the areas of ALL the shapes in this picture
    double total_area(){    
        double area_counter = 0;    
        ListNode* temp_ptr = head;
        for (;temp_ptr != nullptr; temp_ptr = temp_ptr -> next){
            area_counter += temp_ptr -> data -> area();
        }
        return area_counter;
    }

    // draws ALL of the shapes in this picture
    // in the order they were added to this picture
    void draw_all(){
        ListNode* temp_ptr = head;
        for (;temp_ptr != nullptr; temp_ptr = temp_ptr -> next){
            temp_ptr -> data -> draw();
        }
    }

    // prints the name and origin of each shape in this picture
    void print_all(){
        ListNode* temp_ptr = head;
        for (;temp_ptr != nullptr; temp_ptr = temp_ptr -> next){
            temp_ptr -> data -> print();
            temp_ptr -> data -> draw();
        }
    }

    // releases all resources owned by this Picture
    ~Picture(){
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    }
};
#endif