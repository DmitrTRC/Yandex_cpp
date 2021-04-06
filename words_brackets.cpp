//
// Created by Дмитрий Морозов on 05.04.2021.
//

#include <iostream>

using namespace std;


bool get_next_word(const string &source_string, string::size_type &head, string &result_string) {
    bool result = false;
    if (head < source_string.length()) {

        result_string.push_back(source_string[head++]);
        for (; head < source_string.length(); head++) {
            if (not isspace(source_string[head])) {
                result_string.push_back(source_string[head]);

            } else break;
        }
        result = true;
    }
    return result;
}

int main() {
    string query;
    string target_str = "";
    getline(cin, query);
    string::size_type head(0);
    string next_word;
    get_next_word(query, head, next_word);
    cout << next_word;

    cout << target_str;
}