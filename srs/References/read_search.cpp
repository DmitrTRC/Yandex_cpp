//
// Created by Dmitry Morozov on 30/5/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

string ReadSearchQuery() {
    string query;
    getline(cin, query);
    return query;
}

int main() {
    string query = ReadSearchQuery();
    for (const auto &Token:SplitIntoWords(query)) {
        std::cout << "[" << Token << "]" << " ";
    }


}