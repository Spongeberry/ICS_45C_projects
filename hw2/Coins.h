#include <iostream>
using namespace std;

class Coins{
public:

    Coins(int q, int d, int n, int p){
        quarters = q;
        dimes = d;
        nickels = n;
        pennies = p;
    }


    void deposit_coins(Coins & c){
        quarters += c.quarters;
        dimes += c.dimes; 
        nickels += c.nickels;
        pennies += c.pennies;
    }


    bool has_exact_change_for_coins(Coins c){
        return (quarters >= c.quarters) && (dimes >= c.dimes) && (nickels >= c.nickels) && (pennies >= c.pennies);
    }


    Coins extract_exact_change(Coins c){
        if (has_exact_change_for_coins(c)){
            quarters -= c.quarters;
            dimes -= c.dimes;
            nickels -= c.nickels;
            pennies -= c.pennies;
            return Coins(c.quarters, c.dimes, c.nickels, c.pennies);
        }
        else {
            cout << "ERROR: Insufficient Funds" << endl << endl;
            return Coins(0,0,0,0);
        }
    }

    
    int total_value_in_cents(){
        return (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1);
    }

    
    void print(ostream & out){
        out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies" << endl;
    }
private:
    int quarters, dimes, nickels, pennies;
};

ostream & operator << (ostream & out, Coins c){
    c.print(out);
    return out;
}


Coins coins_required_for_cents(int amount_in_cents){
    int q = amount_in_cents / 25;
    amount_in_cents = amount_in_cents % 25;
    int d = amount_in_cents / 10;
    amount_in_cents = amount_in_cents % 10;
    int n = amount_in_cents / 5;
    amount_in_cents = amount_in_cents % 5;
    int p = amount_in_cents;
    return Coins(q, d, n, p);
};