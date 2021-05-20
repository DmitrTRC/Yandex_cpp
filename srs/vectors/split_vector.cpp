//
// Created by Dmitry Morozov on 10.04.2021.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string &source_string, vector<string> &words) {
    string word;
    for (char letter : source_string) {
        if (isspace(letter)) {
            words.push_back(word);
            word.clear();
        } else {
            word += letter;
        }
    }
    words.push_back(word);
}

void print_list(vector<string> &list) {
    for (const string &item : list) {
        cout << "[" << item << "]" << endl;
    }
}

int main() {

    string query;
    getline(cin, query);
    vector<string> words;
    string word;
    split(query, words);
    print_list(words);


}