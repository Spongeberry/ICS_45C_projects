#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

int main() {
    std::map<std::string, int> word_freq;
    std::set<std::string> stop_words;
    std::string word;


    std::ifstream stopwords_file("stopwords.txt");
    while (stopwords_file >> word) {
        stop_words.insert(word);
    }

    std::ifstream input_file("sample_doc.txt");
    while (input_file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (stop_words.find(word) == stop_words.end()) {
            word_freq[word]++;
        }
    }

    std::ofstream output_file("frequency.txt");
    for (const auto &entry : word_freq) {
        output_file << entry.first << " " << entry.second << std::endl;
    }

    return 0;
}