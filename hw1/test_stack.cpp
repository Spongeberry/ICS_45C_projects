#include <iostream>
#include <string>
#include "stack.h"



using namespace std;

int main(){
    Stack stack;
    string str;

    while (getline(cin, str)) {
        for (int i = 0; i < str.length(); i++){
            stack.push(str[i]);
        }

        while (!stack.isEmpty()){
            cout << stack.pop();
        }

        cout << endl;
    }
    
    return 0;
}