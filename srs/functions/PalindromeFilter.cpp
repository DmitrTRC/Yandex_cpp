//
// Created by Dmitry Morozov on 21/5/21.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrome(string source_string) {
    return source_string == string(source_string.rbegin(), source_string.rend());
}

vector<string> PalindromeFilter(const vector<string> &words_array, const int &min_length) {
    vector<string> result_array;
    for (const auto &word: words_array) {
        if ((word.length() >= min_length) and IsPalindrome(word)) result_array.push_back(word);
    }
    return result_array;
}
