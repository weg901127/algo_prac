//
// Created by Giyoung Lee on 6/20/22.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answers;
    while (progresses.size()) {
        int answer = 0;
        for (int i = 0; i < progresses.size(); ++i) {
            progresses[i] += speeds[i];
            if (i == 0 && progresses[i] >= 100) {
                answer++;
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                i = -1;
            }
        }
        if (answer)
            answers.push_back(answer);
    }
    return answers;
}

int main (){
    for (auto x : solution({93, 30, 55}, {1, 30, 5})) {
        std::cout <<  x << " ";
    }
    std::cout << std::endl;
    for (auto x : solution({93, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1})) {
        std::cout <<  x << " ";
    }
    return 0;
}