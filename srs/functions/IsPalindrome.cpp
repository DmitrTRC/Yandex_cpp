//
// Created by Dmitry Morozov on 20/5/21.
//

#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    int answer{0};
    if (s == string(s.rbegin(), s.rend())) answer = 1;
    cout << answer << endl;
}
// нужно понять, будет ли s палиндромом


int main() {
    IsPalindrome("ara"s);
    IsPalindrome("deer"s);
    return 0;
}