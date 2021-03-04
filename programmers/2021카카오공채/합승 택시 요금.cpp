/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/72413
 * time complexity : O(N^3)
 * algorithm : Floyd
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define IMPOSSIBLE 1e8
using namespace std;

/**
 * n : 지점 개수
 * s : 출발지점
 * a : 도착지점
 * b : 도착지점
 * fares[u][v] : u->v 로 이동 시 비용
 */
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> pays(n, vector<int>(n, IMPOSSIBLE));
    for(vector<int> fare: fares) {
        int u = fare[0]-1;
        int v = fare[1]-1;
        int money = fare[2];
        pays[u][v] = money;
        pays[v][u] = money;
    }
    for(int i=0;i<n;i++) pays[i][i] = 0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pays[i][j] = min(pays[i][j], pays[i][k] + pays[k][j]);
            }
        }
    }
    
    s--; a--; b--;
    int answer = pays[s][a] + pays[s][b]; // no 합승
    for(int m=0; m<n;m++){// m = 중간지점
        int tmp = pays[s][m];
        if(m != a) tmp += pays[m][a];
        if(m != b) tmp += pays[m][b];
        answer = min(answer, tmp);
    }
    
    return answer;
}
