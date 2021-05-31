//
// Created by Dmitry Morozov on 31/5/21.
//
#include <string>
#include <iostream>
#include <map>


std::map<std::string, std::string> BuildReversedMap(const std::map<std::string, std::string> &m) {
    std::map<std::string, std::string> res_dict;
    for (auto[key, value]: m) {
        res_dict[value] = key;
    }
    return res_dict;
}