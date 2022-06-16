/*
 *
 * https://programmers.co.kr/learn/courses/30/lessons/42840
 *
 */
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    unordered_map<int, int> scores{};

    for (int i = 1 ; i < 4 ; i++) { scores.emplace(i, 0);}

    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int abc[3] = {0,};

    for (int x : answers) {
        if (x == a[abc[0]++ % 5]) scores[1]++;
        if (x == b[abc[1]++ % 8]) scores[2]++;
        if (x == c[abc[2]++ % 10]) scores[3]++;
    }

    vector<pair<int, int>> ordered(scores.begin(), scores.end());
    sort(ordered.begin(), ordered.end(), cmp);
    int first = ordered[0].second;

    for (auto x : ordered) {
        if (x.second == first)
            answer.push_back(x.first);
    }
    return answer;
}

int main(void) {
    for (auto x : solution({1, 3, 2, 4, 2})) {
        std::cout << '[' << x << "] " ;
    }
    return 0;
}