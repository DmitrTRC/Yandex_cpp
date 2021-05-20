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
    int result{0};
    const std::unordered_map<std::string, std::function<void()>> command_table{
            {"WORRY_COUNT", [&]() { cout << "Worry count" << endl; }},
            {"WORRY",       [&]() { cout << "Worry [i] " << endl; }},
            {"QUIET",       [&]() { cout << "Quiet " << endl; }},
            {"COME",        [&]() { cout << "COME" << endl; }},
    };

    auto item = command_table.find(command);
    if (item != command_table.end()) {
        item->second();
    } else {
        result = -1;
    }
    return result;
}

int main() {
    vector<bool> people_list;
    int query_num;
    cin >> query_num;
    // Command selection
    for (int i = 0; i < query_num; ++i) {
        string operation_code;
        cin >> operation_code;
        if (command_manager(operation_code)) {
            cout << "Unknown operation" << endl;
        }
    }
}
