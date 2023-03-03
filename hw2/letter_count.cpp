#include <iostream>
using namespace std;

int main(){
    int letterCount_arr[26] = {0};

    char c;
    while (cin >> c) {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z'){
            letterCount_arr[c - 65]++;
        }
    }

    for (int i = 0; i < 26; i++){
        cout << (char)(i + 65) << " " << letterCount_arr[i] << endl;
    }
    return 0;
}