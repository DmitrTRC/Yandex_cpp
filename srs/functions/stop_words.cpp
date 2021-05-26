//
// Created by Dmitry Morozov on 21/5/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(std::string line, const std::string &delimiter = " ") {
    vector<string> ret_line;
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

vector<string> StopWordsFilter(vector<string> stop_srs, vector<string> request) {
    set<string> stop_set(stop_srs.begin(), stop_srs.end());
    set<string> request_set(request.begin(), request.end());
    vector<string> result_vec;
    set_difference (request.begin(), request.end(), stop_set.begin(), stop_set.end(), back_inserter(result_vec));
    return result_vec;
}

int main() {
    string stop_words;
    string query;

    getline(cin, stop_words);
    getline(cin, query);

    vector<string> result = StopWordsFilter(SplitIntoWords(stop_words), SplitIntoWords(query));

    for (const auto &item: result) {
        cout << "[" << item << "]" << endl;
    }

}