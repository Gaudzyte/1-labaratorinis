#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <chrono>
#include "studentas.h"
#include "mylib.h"
#include "timer.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, int>> failai = {
        {"studentai.1000.txt", 1000},
        {"studentai.10000.txt", 10000},
        {"studentai.100000.txt", 100000},
        {"studentai.1000000.txt", 1000000}
        // {"studentai.10000000.txt", 10000000}
    };

    for (auto& f : failai)
        TestavimasIsFailo(f.first, f.second);

    return 0;
}
