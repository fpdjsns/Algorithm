/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/49191
 * algorithm : Floyd
 * time complexity : O(N^3)
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    
    vector<vector<bool>> cnts(n, vector<bool>(n, false));
    
    for(auto result : results) {
        int winner = result[0] - 1;
        int loser = result[1] - 1;
        cnts[winner][loser] = true;
    }
    
    for(int k=0; k<n; k++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(u == v) continue;
                if(cnts[u][k] && cnts[k][v]) cnts[u][v] = true;
            }
        }
    }
    
    int answer = 0;
    for(int u = 0; u < n; u++){
        int sum = 0;
        for(int v = 0; v < n; v++){
            sum += cnts[u][v] + cnts[v][u];
        }
        answer += (sum == n-1);
    }
    return answer;
}
