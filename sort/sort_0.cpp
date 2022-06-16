#include <string>
#include <vector>
#include <algorithm>
/*
 *
 * https://programmers.co.kr/learn/courses/30/lessons/42748
 *
 */
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp(0);
    for (int i = 0 ; i < commands.size() ; i++) {
        tmp.assign(array.begin() + (commands[i][0] - 1), array.begin() + ((commands[i][1])));
        std::sort(tmp.begin(), tmp.begin() + tmp.size());
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}
int main(void) {
    solution({1,2,3,4,5,6,7}, {{2,5,3},{4,4,1},{1,7,3}});
    return 0;
}