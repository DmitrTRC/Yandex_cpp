//
// Created by Dmitry Morozov on 10.04.2021.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string &source_string, vector<string> &words) {
    string word;
    for (auto(letter) : source_string) {
        if (letter == ' ') {
            words.push_back(word);
            word.clear();
        } else {
            word += letter;
        }
    }
}

void print_list(const vector<string> list) {
    for (auto(item) : list) {
        cout << "[" << item << "]" << endl;
    }
}

int main() {
    string query;
    getline(cin, query);
    vector<string> words;
    split(query, words);
    print_list(words);

}