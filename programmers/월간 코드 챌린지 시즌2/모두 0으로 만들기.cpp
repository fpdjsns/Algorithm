/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/76503#
 * algorithm : DFS
 * time complexity : O(N)
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> check;
vector<vector<int>> edges;
long long answer = 0;

long long dfs(vector<int>& a, int ind) {
    long long sum = a[ind];
    check[ind] = true;
    for(auto next: edges[ind]){
        if(check[next]) continue;
        long long child = dfs(a, next);
        answer += abs(child);
        sum += child;
    }
    return sum;
}

long long solution(vector<int> a, vector<vector<int>> edgeList) {
    int n = a.size();
    
    // init
    edges = vector<vector<int>>(n);
    check = vector<bool>(n, false);
    
    // set
    for(int i=0; i<edgeList.size(); i++){
        int u = edgeList[i][0]; int v = edgeList[i][1];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    // solve
    return dfs(a, 0) == 0 ? answer : -1;
}
