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
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> split_line(std::string line, const std::string &delimiter = " ") {
    vector<string> com_line = {};
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        com_line.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    com_line.push_back(line);

    return com_line;
}

u_long get_worries_count(const vector<bool> &item_list) {
    u_long count{0};
    for (auto item:item_list) {
        if (item) {
            count++;
        }
    }
    return count;
}

int command_manager(const string &command, vector<bool> &queue_array) {
    int result{0};
    vector<string> command_line = split_line(command);
    const std::unordered_map<std::string, std::function<void()>> command_table{
            {"WORRY_COUNT", [&]() { cout << get_worries_count(queue_array) << endl; }},
            {"WORRY",       [&]() { queue_array.at(stoi(command_line.at(1))) = true; }},
            {"QUIET",       [&]() { queue_array.at(stoi(command_line.at(1))) = false; }},
            {"COME",        [&]() {
                queue_array.resize(queue_array.size() + stoi(command_line.at(1)), false);
            }},
    };

    auto item = command_table.find(command_line.at(0));
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
        std::getline(cin >> ws, operation_code);
        if (command_manager(operation_code, people_list)) {
            cout << "Unknown operation" << endl;
        }
    }
}
