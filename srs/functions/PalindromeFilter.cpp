//
// Created by Dmitry Morozov on 21/5/21.
//
#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(string source_string) {
    return source_string == string(source_string.rbegin(), source_string.rend());
}

int main() {

}