//
// Created by gilee on 2022/06/21.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> res;
    for (auto x : phone_book)
        res[x];


/*
    for(auto y : res)
        std::cout << y.first << " " << y.second << std::endl;
*/
    auto z = res.begin();
    while (z != res.end()) {
        int a = 2;
        while (--a) {
            auto k = z;
            if (++k == res.end())
                break;
            if (k->first.find(z->first) == 0)
                return false;
        }
        z++;
    }
    return answer;
}


int main() {
    std::cout << solution({"123", "456", "789"}) << std::endl;
}