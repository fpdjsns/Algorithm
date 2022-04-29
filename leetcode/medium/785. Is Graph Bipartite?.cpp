/**
 * problem : https://leetcode.com/problems/is-graph-bipartite/
 * time complexity : O(N)
 * algorithm : BFS
 */

class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int start = 0; start < n; start++){
            if(color[start] != -1) continue; // already visit
            queue<pair<int,int>> q; // node, color
            q.push({start, 0});
            color[start] = 0;

            while(!q.empty()){
                int u = q.front().first;
                int nextColor = !(q.front().second);
                q.pop();
                for(auto v: graph[u]) {
                    if(color[v] != -1) {
                        if(color[v] != nextColor) return false;
                        continue;
                    }
                    color[v] = nextColor;
                    q.push({v, nextColor});
                }
            }
        }
        return true;
    }
};
