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

int main() {
    vector<bool> people_list;
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "WORRY_COUNT"s) {
            // обработка запроса WORRY_COUNT
            std::cout << get_worries_count(people_list);
        } else {

            // обработка остальных запросов

        }
    }
}
