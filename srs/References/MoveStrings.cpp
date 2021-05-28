//
// Created by 99843 on 5/28/2021.
//
#include <iostream>
#include <vector>
#include <string>

void MoveStrings(std::vector<std::string> &source, std::vector<std::string> &destination) {
    destination.insert(destination.end(), source.begin(), source.end());
    source.clear();
}