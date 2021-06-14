/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/42861
 * time complexity: O(ElogE)
 * algorithm : Kruskal
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;

int find(int now) {
    if(parents[now] == now) return parents[now];
    return parents[now] = find(parents[now]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parents[a] = b;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parents = vector<int>(n, -1);
    for(int i=0;i<n;i++) parents[i] = i;
    
    vector<pair<int, pair<int, int>>> sortedCosts;
    for(auto cost: costs) {
        int u = cost[0];
        int v = cost[1];
        int c = cost[2];
        sortedCosts.push_back({c, {u, v}});
    }
    sort(sortedCosts.begin(), sortedCosts.end());
    for(auto cost: sortedCosts){
        int u = cost.second.first;
        int v = cost.second.second;
        int c = cost.first;
        if(merge(u, v)) 
            answer += c;
    }
    return answer;
}
