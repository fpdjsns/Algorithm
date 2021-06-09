/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/49189
 * time complexity : O(E)
 * algorithm : BFS
 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> edges(n);
    for(auto vertex: edge) {
        int u = vertex[0] - 1;
        int v = vertex[1] - 1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    queue<pair<int,int>> q;
    q.push({0, 0});
    vector<bool> visits(n, false);
    visits[0] = true;
        
    int dist = 0;
    int answer = 0;
    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(dist != cnt) {
            answer = 0;
            dist = cnt;
        }
        answer++;
        
        for(auto next: edges[now]){
            if(visits[next]) continue;
            visits[next] = true;
            q.push({next, cnt+1});
        }
    }
    return answer;
}
