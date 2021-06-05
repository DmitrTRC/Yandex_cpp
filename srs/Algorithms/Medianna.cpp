//
// Created by Dmitry Morozov on 5/6/21.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples) {
    // TODO Medianna
    // верните {true, медиана}, если она существует,
    // то есть вектор непустой,
    // иначе - {false, 0}
    // обратите внимание - вектор принимаем по значению,
    // так как его придётся немного подпортить, чтобы вернуть ответ
    pair<bool, double> result{false, 0.0};
    if (!samples.empty()) {
        sort(samples.begin(), samples.end());
        double vec_center = samples.size() / 2;
        if (samples.size() % 2) {
            result = make_pair(true, floor(vec_center));
        } else {
            result = make_pair(true, (samples.at(floor(vec_center)) + samples.at(ceil(vec_center))) / 2.0);
        }
    }
    return result;
}

int main() {
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    pair<bool, double> result = CalcMedian(samples);
    if (result.first) {
        cout << result.second << endl;
    } else {
        cout << "Empty vector"s << endl;
    }
}