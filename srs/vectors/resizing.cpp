//
// Created by Dmitry Morozov on 20/5/21.
//

/*
WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
QUIET i: пометить i-го человека (в нумерации с 0) как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.
Реализовать операции WORRY, QUIET и COME позволят простые действия с вектором. Для реализации WORRY_COUNT понадобится честный подсчёт указанного числа.

 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

u_long get_worries_count(const vector<bool> &item_list) {
    u_long count{0};
    for (auto item:item_list) {
        if (item) {
            count++;
        }
    }
    return count;
}

int command_manager(const string &command) {

}

int main() {
    vector<bool> people_list;
    int query_num;
    cin >> query_num;

    // Command selection

    const std::unordered_map<std::string, std::function<void()>> m{
            {"WORRY_COUNT", [&]() { cout << "Worry count" << endl; }},
            {"WORRY",       [&]() { cout << "Worry [i] " << endl; }},
            {"QUIET",       [&]() { cout << "Quiet " << endl; }},
            {"COME",        [&]() { cout << "COME" << endl; }},
    };


    const auto end = m.end();
    std::vector<std::string> strings{"one", "two", "three", "foobar"};
    for (const auto &s : strings) {
        auto it = m.find(s);
        if (it != end) {
            it->second();
        } else {
            result = -1;
        }
        std::cout << s << " " << result << std::endl;
    }
}

for (
int i = 0;
i<query_num;
++i) {
string operation_code;
cin >>
operation_code;


if (operation_code == "WORRY_COUNT"s) {
// обработка запроса WORRY_COUNT
std::cout <<
get_worries_count(people_list)
<<
std::endl;
} else {

// обработка остальных запросов

}
}
}
