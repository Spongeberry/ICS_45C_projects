#include <iostream>
#include "Coins.h"
using namespace std;

int main(){
    Coins temp_coin(0,0,0,0);
    while (true) {
    cout << "Coin Menu" << endl << endl;
    cout << "1. Deposit Change" << endl;
    cout << "2. Extract Change" << endl;
    cout << "3. Print Balance" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "User Input:";
    int num;
    cin >> num;

    if (num == 1) {
        cout << endl;
        cout << "Quarters? ";
        int quarters;
        cin >> quarters;
        cout << "Dimes? ";
        int dimes;
        cin >> dimes;
        cout << "Nickles? ";
        int nickels;
        cin >> nickels;
        cout << "Pennies? ";
        int pennies;
        cin >> pennies;
        cout << endl;
        cout << "Thank you!";
        Coins tempCoins(quarters,dimes,nickels,pennies);
        temp_coin.deposit_coins(tempCoins);
        cout << endl << endl;
    }

    else if (num == 2) {
        cout << endl;
        cout << "Quarters? ";
        int quarters;
        cin >> quarters;
        cout << "Dimes? ";
        int dimes;
        cin >> dimes;
        cout << "Nickles? ";
        int nickels;
        cin >> nickels;
        cout << "Pennies? ";
        int pennies;
        cin >> pennies;
        cout << endl;
        cout << "Thank you!";
        Coins tempCoins(quarters,dimes,nickels,pennies);
        cout << endl;
        cout << endl;
        temp_coin.extract_exact_change(tempCoins);
        
    }
    else if (num == 3){
        cout << "\n";
        cout << "$" << static_cast<double>(temp_coin.total_value_in_cents()) / 100 << endl << endl;
        cout << "Thank you!" << endl << endl;
    }
    else if (num == 4){
        break;
    }
    else
        cout << "ERROR: Invalid Command" << endl;
    
    }
}