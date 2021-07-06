/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/12946
 * time complexity : O(2^N)
 */

#include <string>
#include <vector>

using namespace std;

// a -> c
void hanoi(vector<vector<int>>& answer, int n, int a, int b, int c){
    if(n == 0) {
        return;
    }
    hanoi(answer, n-1, a, c, b);
    answer.push_back({a, c});
    hanoi(answer, n-1, b, a, c);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 2, 3);
    return answer;
}
