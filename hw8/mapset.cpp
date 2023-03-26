#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iterator>

using namespace std;

int main() {
    ifstream infile("sample_doc.txt");
    ifstream stopwordsfile("stopwords.txt");
    set<string> stopwords;
    transform(istream_iterator<string>{stopwordsfile}, istream_iterator<string>{}, inserter(stopwords, stopwords.begin()), [](const string& stopword) {
        string lowercase_stopword;
        transform(stopword.begin(), stopword.end(), back_inserter(lowercase_stopword), [](char c) { return tolower(c); });
        return lowercase_stopword;
    });
    map<string, int> word_counts;
    for_each(istream_iterator<string>{infile}, istream_iterator<string>{}, [&](const string& word) {
        string lowercase_word;
        transform(word.begin(), word.end(), back_inserter(lowercase_word), [](char c) { return tolower(c); });
        if (stopwords.find(lowercase_word) == stopwords.end()) {
            ++word_counts[lowercase_word];
        }
    });

    ofstream outfile("frequency.txt");
    for_each(word_counts.begin(), word_counts.end(), [&](const pair<string, int>& word_count) {
        outfile << word_count.first << " " << word_count.second << "\n";
    });

    return 0;
}