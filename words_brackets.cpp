//
// Created by Дмитрий Морозов on 05.04.2021.
//

#include <iostream>
#include <string>

using namespace std;


bool get_next_word(const string &source_string, string::size_type &head, string &result_string) {
    bool result = false;
    result_string = "";
    if (not source_string.empty() and head < source_string.length()) {
        result = true;
        if (not isspace(source_string[head])) {
            for (;head < source_string.length(); head++){
                if (not isspace(source_string[head])) {
                    result_string.push_back(source_string[head]);
                } else break;
            }
        } else {
            cout << "Got 1-st space" << endl;
            head++;
            // First space got!
            if ( source_string[head] == ' '){
            cout << "Got 2-nd space" << endl;
            head++;
            }
        }
    }
    return result;
}

string print_word(const string &word) {
    return "[" + word + "]";
}

int main() {
    string query;
    getline(cin, query);
    string::size_type head(0);
    string next_word;
    bool no_words = true;
    while (get_next_word(query, head, next_word)) {
        cout << print_word(next_word) << endl;
        no_words = false;
    }
    if (no_words) cout << "[]" << endl;
}

