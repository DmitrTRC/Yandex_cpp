//
// Created by Dmitry Morozov on 10.04.2021.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string &source_string, vector<string> &words) {
    string word;
    for (int i =0; i < source_string.size(); i++) {
        if (source_string[i] == ' ') {
            words.push_back(word);
            word.clear();
        } else {
            word += source_string[i];
        }
    }
}

void print_list(vector<string> &list) {
    for (const auto(&item) : list) {
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