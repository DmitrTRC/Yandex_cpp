//
// Created by Dmitry Morozov on 21/5/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

u_int CalculateSimilarity(vector<string> first_srs, vector<string> second_srs) {
    sort(first_srs.begin(), first_srs.end());
    sort(second_srs.begin(), second_srs.end());
    vector<string>result_vec;
    set_intersection(first_srs.begin(), first_srs.end(), second_srs.begin(), second_srs.end(), back_inserter(result_vec));
    return result_vec.size();

    // выведите размер пересечения множеств слов
}

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

int main() {
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;

    return 0;
}