//
// Created by Dmitry Morozov on 20/5/21.
//
#include <iostream>

int Factorial(int x) {
    if (x <= 0) return 1;
    else return x * Factorial(x - 1);

}

int main() {
    int n;
    std::cin >> n;
    std::cout << Factorial(n) << std::endl;
}

