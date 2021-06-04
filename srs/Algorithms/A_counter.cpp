//
// Created by Dmitry Morozov on 4/6/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CountStartsWithA(const vector<string> &xs) {
    //TODO  посчитайте число строк, начинающихся на букву A
    return count_if(xs.begin(), xs.end(), [](string word) { return tolower(word.at(0)) == 'a'; });
}

int main() {
    // не меняйте тело main
    cout << CountStartsWithA({"And"s, "another"s, "one"s, "gone"s, "another"s, "one"s "bites"s, "the"s, "dust"s});
    return 0;
}