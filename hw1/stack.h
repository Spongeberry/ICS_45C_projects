#include <iostream>
#define STACK_CAPACITY 1000

class Stack
{
public:
    char stack_arr[STACK_CAPACITY];
    int top_pointer_index = 0;

    Stack(){};
    void push( char c ){
        if (!isFull()){
            stack_arr[top_pointer_index] = c;
            top_pointer_index++;
        }
    }
    char pop(){
        if (!isEmpty()){
            top_pointer_index--;
            char top = stack_arr[top_pointer_index];
            return top;
        }
        else
            return '@';
    }
    char top(){
        if (!isEmpty()){
            top_pointer_index--;
            char top = stack_arr[top_pointer_index];
            top_pointer_index++;
            return top;
        }
        else
            return '@';
    }
    bool isEmpty(){
        return top_pointer_index <= 0;
    }
    
    bool isFull(){
        return top_pointer_index >= STACK_CAPACITY;
    }

    ~Stack(){}
};