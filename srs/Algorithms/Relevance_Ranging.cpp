//
// Created by Dmitry Morozov on 6/6/21.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const unsigned MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWords(const string &text) {
    set<string> stop_words;
    for (const string &word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string &text, const set<string> &stop_words) {
    vector<string> words;
    for (const string &word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(map<string, set<int>> &word_to_documents,
                 const set<string> &stop_words,
                 int document_id,
                 const string &document) {
    for (const string &word : SplitIntoWordsNoStop(document, stop_words)) {
        word_to_documents[word].insert(document_id);
    }
}

// For each document returns its id and relevance
vector<pair<int, int>> FindAllDocuments(
        const map<string, set<int>> &word_to_documents,
        const set<string> &stop_words,
        const string &query) {
    const vector<string> query_words = SplitIntoWordsNoStop(query, stop_words);
    map<int, int> document_to_relevance;
    for (const string &word : query_words) {
        if (word_to_documents.count(word) == 0) {
            continue;
        }
        for (const int document_id : word_to_documents.at(word)) {
            ++document_to_relevance[document_id];
        }
    }

    vector<pair<int, int>> found_documents;
    for (auto[document_id, relevance] : document_to_relevance) {
        found_documents.push_back({document_id, relevance});
    }
    return found_documents;
}

template<typename T>
vector<T> slicing(vector<T> const &v, int X, int Y) {

    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;

    // Copy the element
    vector<T> vector(first, last);

    // Return the results
    return vector;
}

vector<pair<int, int>> FindTopDocuments(const std::vector<pair<int, int>> &relevance_data) {
    vector<pair<int, int >> v_sorted(relevance_data.size());
    partial_sort_copy(begin(relevance_data), end(relevance_data), begin(v_sorted), end(v_sorted));
    //reverse(begin (v_sorted), end(v_sorted));
    unsigned slice_pointer = MAX_RESULT_DOCUMENT_COUNT;
    if (relevance_data.size() < MAX_RESULT_DOCUMENT_COUNT) slice_pointer = relevance_data.size();
    return vector <pair<int, int>>(v_sorted.begin(), v_sorted.end());
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    map<string, set<int>> word_to_documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(word_to_documents, stop_words, document_id, ReadLine());
    }

    const string query = ReadLine();
    for (auto[document_id, relevance] : FindTopDocuments(FindAllDocuments(word_to_documents, stop_words, query))) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s << endl;
    }
}