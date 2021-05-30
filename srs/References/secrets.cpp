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

int main() {
    const string text = "test search query";
    for (const string &Item : SplitIntoWords(text)) {
        std::cout << '[' << Item << ']' << " " ;
    }
}