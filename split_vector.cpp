//
// Created by Dmitry Morozov on 10.04.2021.
//
#include <iostream>
#include <string>

using namespace std;
int main() {
    string query;
    getline(cin, query);

    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == ' ') {
            cout << i << endl;
        }
    }
    cout << query.size() << endl;
}