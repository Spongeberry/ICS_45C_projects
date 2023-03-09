#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    ifstream input_file("rand_numbers.txt");
    vector<int> numbers{istream_iterator<int>{input_file}, istream_iterator<int>{} };
    sort(numbers.begin(), numbers.end());
    cout << endl;
    ofstream odds_file("odds.txt");
    ofstream evens_file("evens.txt");
    copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>{odds_file, " "}, [](int n) { return n % 2 == 1; });
    odds_file << endl;
    copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>{evens_file, "\n"}, [](int n) { return n % 2 == 0; });
    return 0;
}