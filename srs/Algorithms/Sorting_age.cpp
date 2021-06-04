//
// Created by Dmitry Morozov on 4/6/21.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef std::pair<std::string, int> p_pair;

// TODO Задача прошла 0/10 проверок
//
//Возможные проблемы:
//- Вы неправильно выводите имена, когда все люди разного возраста
//- Вы неправильно обрабатываете общий случай.
//- Вы неправильно выводите имена, когда есть люди одного возраста
//- Вы неправильно выводите имена, когда все люди одного возраста

int main() {
    int people_number{0};
    std::vector<p_pair> personal_base;
    cin >> people_number;
    for (int i = 0; i < people_number; ++i) {
        std::string name;
        int age;
        std::cin >> name >> age;
        personal_base.emplace_back(std::make_pair(name, age));
        sort(personal_base.begin(), personal_base.end(), [](const p_pair &l, const p_pair &r) {
                 if (l.second != r.second) {
                     return l.second < r.second;
                 }
                 return l.first < r.first;
             }
        );
    }
    reverse(personal_base.begin(), personal_base.end());

    for (const auto &[Name, Age]: personal_base) {
        std::cout << Name << std::endl;
    }
    return 0;
}
