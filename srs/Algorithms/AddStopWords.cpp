//
// Created by Dmitry Morozov on 6/6/21.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

string AddStopWords(const string &query, const set<string> &stop_words) {
    string res_string = query;
    for (auto word : stop_words) {
        res_string.append(" -" + word);
    }
    return res_string;
}

int main() {
set <string> srs {"in", "off", "out"};
string query = "Moon distance";
std :: cout << AddStopWords (query, srs) << std :: endl;
    return 0;
}