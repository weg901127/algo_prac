//
// Created by gilee on 2022/06/22.
//
#include <iostream>
#include <vector>

using namespace std;

void algo(vector<int> numbers, int sum, int & target, int & answer) {
    if (numbers.empty() && sum == target)
        answer++;
    else if (!numbers.empty()){
        int tmp1, tmp2;
        tmp1 = *numbers.rbegin();
        tmp2 = -1 * *numbers.rbegin();
        numbers.pop_back();
        algo(numbers, sum + tmp1, target, answer);
        algo(numbers, sum + tmp2, target, answer);
    }

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    algo(numbers, 0, target, answer);
    return answer;
}

int main () {
    std::cout << solution({1, 1, 1, 1, 1}, 3) << std::endl;
    return 0;
}