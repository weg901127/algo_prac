//
// Created by gilee on 2022/06/21.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> res;
    for(auto x : phone_book)
        res[x] = x.length();

    /*
    for(auto y : res)
        std::cout << y.first << " " << y.second << std::endl;
    */
    for (auto z : res) {
        for (auto k = res.begin() ; k != res.end() ; k++) {
            if (z.first != k->first && z.first.length() <= k->first.length() && k->first.find(z.first) == 0)
                return false;
        }
    }
    /*
for (auto k : res) {
    if (k.first.find(tmp.first) == 0)
        return false;
}
}
     */
    return answer;
}