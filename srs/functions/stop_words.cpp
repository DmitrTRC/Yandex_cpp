//
// Created by Dmitry Morozov on 21/5/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <iterator>


using namespace std;


//vector<string> SplitIntoWords(const std::string text) {
//    std::istringstream iss(text);
//    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
//                                     std::istream_iterator<std::string>());
//    return results;
//}

//vector<string> SplitIntoWords(string text) {
//    vector<string> words;
//    string word;
//    for (int i = 0; i < text.size(); ++i) {
//        if (text[i] == ' ') {
//            words.push_back(word);
//            word = ""s;
//        } else {
//            word += text[i];
//        }
//    }
//    words.push_back(word);
//
//    return words;
//}
std::vector<std::string> SplitIntoWords(const std::string& s, char delimiter = ' ')
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
std::set<string> NormalizeStopWords(const std::string &srs_words) {
    std::set<string> result_set;
    for (const auto &word : SplitIntoWords(srs_words)) result_set.insert(word);
    return result_set;
}

vector<string> FilterQuery(const std::string &query, const std::set<string> &stop_words) {
    std::vector<string> result_vec;
    for (const auto &word : SplitIntoWords(query)) {
        if (!stop_words.count(word)) result_vec.push_back(word);
    }
    return result_vec;
}


int main() {
    string stop_words_string;
    string query;

    getline(cin, stop_words_string);
    getline(cin, query);

    for (auto const &item : FilterQuery(query, NormalizeStopWords(stop_words_string))) {
        cout << "[" << item << "]" << endl;
    }
}