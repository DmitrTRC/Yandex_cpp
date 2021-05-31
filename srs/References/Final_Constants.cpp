//
// Created by Dmitry Morozov on 31/5/21.
//

// final055.cpp без const-переменных, но с const-ссылками

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (const auto &c : text) {
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

set<string> ParseStopWords(const string &text) {
    set<string> stop_words;
    for (const string &word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(const string &text, const set<string> &stop_words) {
    vector<string> words;
    for (const string &word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}


int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);

    for (const string &word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}