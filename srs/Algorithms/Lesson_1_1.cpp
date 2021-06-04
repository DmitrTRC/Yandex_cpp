//
// Created by 99843 on 6/3/2021.
//

#include <iostream>
#include <vector>

using namespace std;

void PrintWorryCount(const vector<bool> &is_nervous) {
    // подсчитываем количество элементов в векторе is_nervous, равных true
    int worry_count = count(is_nervous.begin(), is_nervous.end(), true);
    cout << worry_count << endl;
}

int main() {
    // не меняйте содержимое функции main
    PrintWorryCount({true, true, false, true});
    return 0;
}