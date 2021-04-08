//
// Created by Дмитрий Морозов on 05.04.2021.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

template<class Container>
void splits(const std::string &str, Container &cont, char delim = ' ') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}


string read_word(const string &source_string, int &head) {
    string result;
    string srs = source_string;
    for (; head < srs.length(); head++) {
        if (not isspace(srs[head])) result.push_back(srs[head]);
        else break;
    }
    return result;
}

void print_tokens(const string &source_string) {
    vector<string> accum;

    splits(source_string, accum);

    for (string &word : accum) {
        cout << "[" << word << "]" << endl;
    }
}


int main() {
    string query;
    getline(cin, query);
    if (query.empty()) {
        cout << "[]" << endl;
    } else {
        print_tokens(query);
    }
    return 0;
}

