//
// Created by Dmitry Morozov on 21/5/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>


using namespace std;

vector<string> TokenizeString(const string &text) {
    vector<string> tokens;
    string word;
    for (char i : text) {
        if (i == ' ') {
            tokens.push_back(word);
            word = ""s;
        } else word += i;
    }
    tokens.push_back(word);
    return tokens;
}

//std::vector<std::string> TokenizeString(const std::string &srs_string, const char delimiter = ' ') {
//    std::vector<std::string> tokens;
//    std::istringstream iss(srs_string);
//    std::string word;
//    while (getline(iss, word, delimiter)) {
//        tokens.push_back(word);
//    }
//    return tokens;
//}

std::set<string> NormalizeStopWords(const std::string &srs_words) {
    std::set<string> result_set;
    for (const auto &word : TokenizeString(srs_words)) result_set.insert(word);
    return result_set;
}

vector<string> FilterQuery(const std::string &query, const std::set<string> &stop_words) {
    std::vector<string> result_vec;
    for (const auto &word : TokenizeString(query)) {
        if (!stop_words.count(word)) result_vec.push_back(word);
    }
    return result_vec;
}

void PrintQuery(const std::vector<string> &query) {
    for (auto const &item : query) {
        cout << "[" << item << "]" << endl;
    }
}

int main() {
    string stop_words_string;
    string query;

    getline(cin, stop_words_string);
    getline(cin, query);

    PrintQuery(FilterQuery(query, NormalizeStopWords(stop_words_string)));
}