#include <iostream>
using namespace std;

double knots_to_miles_per_minutes(int knots){
    double miles_min = (knots * 6076.0) / (5280.0 * 60.0);
    return miles_min;
}

int main(){
    int knots;
    cin >> knots;
    double miles_min = knots_to_miles_per_minutes(knots);
    cout << miles_min << endl;
    return 0;
}
