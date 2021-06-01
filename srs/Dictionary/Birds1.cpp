//
// Created by Dmitry Morozov on 1/6/21.
//

#include <string>
#include <vector>
#include <map>
#include<iostream>

using namespace std;


void PrintBirdNumByType(const vector<string> &types) {
    map<string, int> result_map;
    for (const auto &BirdType : types) {
        ++result_map[BirdType];
    }
    for (const auto &[bird_type, counter] : result_map) {
        cout << bird_type <<" "<< counter << endl;
    }

}

int main() {
    vector<string> bird_types = {"zyablik"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    PrintBirdNumByType(bird_types);
}