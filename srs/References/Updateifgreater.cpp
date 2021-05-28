//
// Created by 99843 on 5/28/2021.
//

#include <iostream>


void UpdateIfGreater(const int& limit, int& value) {
    if (limit > value) value = limit;
}

int main() {
    for (int i = 0; i <= 20; i++) {
        int value = i;
        UpdateIfGreater(10, value);
        std::cout << value << std::endl;
    }

    return 0;
}