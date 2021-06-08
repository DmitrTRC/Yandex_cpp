//
// Created by Dmitry Morozov on 7/6/21.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

const int SAMPLE_COUNT = 5;

//TODO
//Напишите функцию CountNames. Пусть она выясняет, какие слова из списка содержатся во множестве,
// и возвращает ответ в виде вектора единиц и нулей.
// Список кандидатов дан в виде вектора строк. Если слово есть во множестве, в ответе будет единица, иначе — ноль.
// В коде вы видите библиотеку <chrono>. Она содержит элементы, связанные с концептами времени.

// TODO Warnings.
vector<int> CountNamesLong(const set<string> &storage, const vector<string> &candidates) {
    vector<int> output;
    output.reserve(candidates.size());
    for (auto &name: candidates) {
        output.push_back(count(storage.begin(), storage.end(), name));
    }
    return output;
}

vector<unsigned> CountNames(const set<string> &storage, const vector<string> &candidates) {
    vector<unsigned> result_vec;
    result_vec.reserve(candidates.size());
    for (auto &name: candidates) {
        result_vec.push_back(count(storage.begin(), storage.end(), name));
    }
    return result_vec;

}

int main() {
    set<string> s;
    vector<string> v;
    string stra = ""s;
    string strb = ""s;

    for (int j = 0; j < 10000; ++j) {
        s.insert(stra);
        stra += "a"s;
        if (j % 2 == 0) {
            v.push_back(strb);
            strb += "b"s;
        } else {
            v.push_back(stra);
        }
    }
    cout << "Testing slow version" << endl;
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        auto begin = chrono::steady_clock::now();
        for (auto Item : CountNamesLong(s, v)) {
            cout << Item << " ";
        }
        cout << endl;

        // cout << CountNamesLong(s, v);
        auto end = chrono::steady_clock::now();
        cout << "Time difference Long = "s << chrono::duration_cast<chrono::microseconds>(end - begin).count()
             << "[µs]"s << endl;
    }
}