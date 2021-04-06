//
// Created by Дмитрий Морозов on 05.04.2021.
//

#include <iostream>

using namespace std;

bool is_space_word(const string &src, int index) {
    return  src [index] == ' ' and src [index +1] == ' ';
}

int main() {
    string query;
    string target_str = "[";
    getline(cin, query);

    for (auto index = 0; index < query.length(); index++) {
        if (query[index] != ' ') {
            target_str += query[index];
        } else {
            target_str += "]";
        }
    }
    cout << target_str;

}