//
// Created by Dmitry Morozov on 31/5/21.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> FrequencyCounter(const string &Source) {
    map<char, int> res_map;
    for (auto &ch:Source) {
        ++res_map[ch];
    }
    return res_map;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string first_word, second_word;
        cin >> first_word >> second_word;

        if (FrequencyCounter(first_word) == FrequencyCounter(second_word) ) {
            cout << "YES"s << endl;
        } else {
            cout << "NO"s << endl;
        }
    }

    return 0;
}