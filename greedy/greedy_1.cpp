//
// Created by Giyoung Lee on 6/16/22.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int,int> m{};
    for (int i = 1; i <= n ; ++i) {
        m[i] = 0;
    }
    for (auto x : m) {
        for (auto y : lost) {
            if (x.first == y)
                m[x.first] -= 1;
        }
        for (auto z : reserve) {
            if (x.first == z)
                m[x.first] += 1;
        }
    }
    /*
    for (auto aa : m) {
        std::cout << aa.first << " " << aa.second << std::endl;
    }
     */
    for (int k = 1 ; k <= n ; k++) {
        if (m[k] == -1) {
            if (k != 1 && m[k - 1] == 1) {
                m[k] = 0;
                m[k - 1] = 0;
            } else if (k != n && m[k + 1] == 1){
                m[k] = 0;
                m[k + 1] = 0;
            }
        }
        if (m[k] == -1)
            answer += m[k];
    }

    /*
    for (auto aa : m) {
        std::cout << aa.first << " " << aa.second << std::endl;
    }
     */
    return answer + n;
}

int main() {
    std::cout << solution(3, {3}, {1}) << std::endl;
}