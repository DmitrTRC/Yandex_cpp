//
// Created by Dmitry Morozov on 21/5/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>


using namespace std;


bool IsStopWord(const set<string> &stop_words, const string &word) {
    if (stop_words.count(word)) {
        return true;
    } else return false;
}


vector<string> SplitIntoWords(const std::string &text, char delimiter = ' ',
                              bool set_filter = false,
                              const set<string> &stop_words = set<std::string>()) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tss(text);
    while (getline(tss, token, delimiter)) {
        if (set_filter) {
            if (IsStopWord(stop_words, token)) continue;
        }
        tokens.push_back(token);
    }
    return tokens;
}


int main() {

    string stop_words_string;
    string query;
    char delimiter = ' ';

    getline(cin, stop_words_string);
    getline(cin, query);

    vector<string> stop_words_vec = SplitIntoWords(stop_words_string);
    set<string> Stop_Words_Set(stop_words_vec.begin(), stop_words_vec.end());
    vector<string> result_vec = SplitIntoWords(query, delimiter, true, Stop_Words_Set);
    for (const auto &item: result_vec) {
        cout << "[" << item << "]" << endl;
    }
}