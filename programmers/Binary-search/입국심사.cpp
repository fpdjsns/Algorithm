/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/43238
 * time complexity : O(|times| * logN)
 * algorithm : binary-search
 */

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 0;
    long long right = 1e9 * n;
    long long m = right;
    long long answer = right;
    while(left <= right) {
        m = (left + right) / 2;
        
        long long peopleCnt = 0;
        for(auto time: times) {
            peopleCnt += m / time;
        }
        
        // possible
        if(peopleCnt >= n) {
            answer = min(answer, m);
            right = m - 1;
        } else { // impossible
            left = m + 1;
        }
    }
    return answer;
}
