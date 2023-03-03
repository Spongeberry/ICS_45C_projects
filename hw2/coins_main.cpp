#include <iostream>
#include "Coins.h"
using namespace std;

int main() {
    Coins pocket(5, 3, 6, 8);
    Coins piggyBank(50, 50, 50, 50);


    Coins chips = coins_required_for_cents(68);
    pocket.extract_exact_change(chips);
    cout << "Bought Chips" << endl;
    cout << "Pocket: " << pocket << endl;


    Coins pass = coins_required_for_cents(205);
    piggyBank.extract_exact_change(pass);
    pocket.deposit_coins(pass);
    cout << "Transfer Money to Pocket" << endl;
    cout << "Pocket: " << pocket;
    cout << "Piggy Bank: " << piggyBank << endl;


    Coins change(10, 10, 10, 10);
    piggyBank.deposit_coins(change);
    cout << "Vacuuming Change" << endl;
    cout << "Piggy Bank: $" << piggyBank.total_value_in_cents() / 100 << ".";
    if (piggyBank.total_value_in_cents() % 100 < 10) {
        cout << "0";
    }
    cout << piggyBank.total_value_in_cents() % 100 << endl;

    return 0;
}