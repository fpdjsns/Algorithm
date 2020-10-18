/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/68937
 * algorithm : dijkstra(bfs)
 * time complexity : O(E)
 */

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V;

// return (unique, (the longest edge from start edge, max dist))
pair<bool, pair<int, int>> dijkstra(vector<vector<int>>& edges, int start) {
    queue<int> q; 
    vector<int> dist(V, 0);
    vector<bool> visit(V, false);
    
    dist[start] = 0; // set start edge dist
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()) {
        int vertex = q.front(); q.pop();
        for(auto nextVertex: edges[vertex]) {
            if(visit[nextVertex]) continue;
            visit[nextVertex] = true;
            if(dist[nextVertex] < dist[vertex] + 1) {
                dist[nextVertex] = dist[vertex] + 1;
                q.push(nextVertex);
            }
        }
    }
    
    bool isUnique = true;
    int lastEdge = 0;
    for(int i=1; i<V; i++){
        if(dist[lastEdge] < dist[i]) {
            lastEdge = i;
            isUnique = true;
        } else if(dist[lastEdge] == dist[i]){
            isUnique = false;
        }
    }
    return {isUnique, {lastEdge, dist[lastEdge]}};
}

int solution(int n, vector<vector<int>> edges) {
    vector<vector<int>> newEdges(n);
    V = n;
    
    for(int i = 0; i < edges.size(); i++) {
        vector<int> edge = edges[i];
        newEdges[edge[0]-1].push_back(edge[1]-1);
        newEdges[edge[1]-1].push_back(edge[0]-1);
    }
    
    int edge = dijkstra(newEdges, 0).second.first;
    
    auto first = dijkstra(newEdges, edge);
    if(!first.first) return first.second.second;
    
    auto answer = dijkstra(newEdges, first.second.first);
    int maxDist = answer.second.second;
    bool isUnique = answer.first;
    return isUnique ? maxDist - 1 : maxDist;
}
