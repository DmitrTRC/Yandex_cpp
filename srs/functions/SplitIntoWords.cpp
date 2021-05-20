//
// Created by Dmitry Morozov on 20/5/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(std::string line, const std::string &delimiter = " ") {
    vector<string> ret_line = {};
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        ret_line.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    ret_line.push_back(line);
    return ret_line;
}

int main() {
    string query;
    getline(cin, query);
    for (string word : SplitIntoWords(query)) {
        cout << '[' << word << ']' << endl;
    }
}
