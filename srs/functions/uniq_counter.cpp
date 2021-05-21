//
// Created by Dmitry Morozov on 21/5/21.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set <string> unique_words;
    for ( auto i = 0; i < n; i++){
        string word;
        cin >> word;
        unique_words.insert(word);
    }
    cout << unique_words.size() << endl;
    return 0;
}