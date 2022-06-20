//
// Created by gilee on 2022/06/16.
//
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> p{};
    for(auto x : participant)
        p[x] += 1;
    /*
    for (auto k : p) {
        std::cout << k.first << " " << k.second << std::endl;
    }
    */
    for(auto y : completion) {
        if (p[y] > 1) {
            p[y] -= 1;
            continue;
        }
        if (p[y] == 1)
            p.erase(y);
    }
    return p.begin()->first;
}

int main() {
    std::cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << std::endl;
}