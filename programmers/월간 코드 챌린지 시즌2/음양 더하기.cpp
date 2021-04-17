/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/76501?language=cpp
 * time complexity : O(N)
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int n = absolutes.size();
    for(int i=0; i<n; i++){
        answer += absolutes[i] * (signs[i] ? 1 : -1);
    }
    return answer;
}
